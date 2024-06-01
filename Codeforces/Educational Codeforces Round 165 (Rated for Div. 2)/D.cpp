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

void solve() {
  ll n, k;
  cin >> n >> k;
  vi aa(n), bb(n);
  ll tota = 0, totb = 0;
  FOR(i, 0, n) {
    cin >> aa[i];
  }
  FOR(i, 0, n) {
    cin >> bb[i];
  }

  vector<pi> a(n);
  FOR(i, 0, n) {
    a[i] = {aa[i], bb[i]};
  }
  sort(ALL(a), [&](pi a, pi b) { return (a.second > b.second); });

  ll suf = 0;
  FOR(i, 0, n) {
    suf += max(0ll, a[i].second - a[i].first);
  }
  ll ans = 0;
  priority_queue<ll> q;
  ll sum = 0;
  if (k == 0) {
    ans = suf;
  }
  FOR(i, 0, n) {
    q.push(a[i].first);
    sum += a[i].first;
    if (SZ(q) > k) {
      sum -= q.top();
      q.pop();
    }
    suf -= max(0ll, a[i].second - a[i].first);
    if (SZ(q) == k) {
      ans = max(ans, suf - sum);
    }
  }
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}