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

ll impares = 0;
vi mp;
vi a;
void add(ll idx, ll end) {
  mp[a[idx]]++;
  if (mp[a[idx]] % 2)
    impares++;
  else
    impares--;
}  // add a[idx] (end = 0 or 1)
void del(ll idx, ll end) {
  mp[a[idx]]--;
  if (mp[a[idx]] % 2 == 0)
    impares--;
  else
    impares++;
}  // remove a[idx]
ll calc() { return impares == 0; }  // compute current answer

vi mosAlgo(vector<pi> Q, ll n, ll q) {
  // IMPORTANT!! blk ~= N/sqrt(Q)
  ll L = 0, R = 0, blk = ((n + 1) / (sqrt(q) + 1)) + 10;
  vi s(SZ(Q)), res = s;
#define K(x) pi(x.first / blk, x.second ^ -(x.first / blk & 1))
  iota(ALL(s), 0);
  sort(ALL(s), [&](ll s, ll t) { return K(Q[s]) < K(Q[t]); });
  for (ll qi : s) {
    pi q = Q[qi];
    while (L > q.first) add(--L, 0);
    while (R < q.second) add(R++, 1);
    while (L < q.first) del(L++, 0);
    while (R > q.second) del(--R, 1);
    res[qi] = calc();
  }
  return res;
}

void solve() {
  a.clear();

  impares = 0;
  ll n, q;
  cin >> n >> q;
  a.resize(n);

  ll mx = 0;
  FOR(i, 0, n) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  mp.assign(mx + 5, 0);
  vector<pi> Q(q);
  FOR(i, 0, q) {
    cin >> Q[i].first >> Q[i].second;
    Q[i].first--;
  }
  vi ans = mosAlgo(Q, n, q);
  FOR(i, 0, q) { cout << (ans[i] ? "YES" : "NO") << ENDL; }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}