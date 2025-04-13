#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

vi a, cnt, prefix;
ll n, m, k, result = 0;

void add(int ind, int end) {
  ll v = prefix[ind];
  result += cnt[v xor k];
  cnt[v]++;
}
void del(int ind, int end) {
  ll v = prefix[ind];
  cnt[v]--;
  result -= cnt[v xor k];
}
ll calc() { return result; }

vi mo(vector<pi> Q) {
  int L = 0, R = 0, blk = 350;
  vi s(SZ(Q)), res = s;
#define K(x) pi(x.first / blk, x.second ^ -(x.first / blk & 1))
  iota(ALL(s), 0);
  sort(ALL(s), [&](int s, int t) { return K(Q[s]) < K(Q[t]); });
  for (int qi : s) {
    pi q = Q[qi];
    while (L > q.first) add(--L, 0);
    while (R < q.second) add(R++, 1);
    while (L < q.first) del(L++, 0);
    while (R > q.second) del(--R, 1);
    res[qi] = calc();
  }
  return res;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n >> m >> k;
  a.resize(n);
  ll mx = 0;
  FOR(i, 0, n) { cin >> a[i]; }
  prefix.assign(n + 1, 0);
  FOR(i, 1, n + 1) { prefix[i] = prefix[i - 1] xor a[i - 1]; }
  vector<pi> queries(m);
  FOR(i, 0, m) {
    cin >> queries[i].first >> queries[i].second;
    queries[i].first--, queries[i].second++;
  }
  cnt.assign(2e6 + 5, 0);
  vi ans = mo(queries);

  FOR(i, 0, m) { cout << ans[i] << ENDL; }

  return 0;
}