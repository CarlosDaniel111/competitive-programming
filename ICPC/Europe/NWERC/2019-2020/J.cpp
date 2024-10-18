#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

ll sign(ll x) {
  if (x > 0) return 1;
  if (x < 0) return -1;
  return 0;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, c, r;
  cin >> n >> c >> r;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];

  // Sin fake accounts
  ll ultimo = 0, del = 0;
  FOR(i, 0, n) {
    if (!a[i]) {
      del++;
      continue;
    }
    if (!ultimo or ultimo != sign(a[i]))
      ultimo = sign(a[i]);
    else
      del++;
  }
  ll ans = r * del;

  vector<pi> b(n);
  FOR(i, 0, n) { b[i] = {abs(a[i]), i}; }
  sort(ALL(b));
  reverse(ALL(b));

  auto needDelete = [&](ll l, ll r) -> ll {
    if (l == -1 or r == n) return 0;
    if ((r - l) % 2)
      return sign(a[l]) == sign(a[r]);
    else
      return sign(a[l]) != sign(a[r]);
  };

  del = 0;
  set<ll> s;
  s.insert(-1);
  s.insert(n);
  for (auto &[val, idx] : b) {
    ans = min(ans, (val + 1) * c + del * r);
    if (!val) break;
    ll r = *s.lower_bound(idx);
    ll l = *prev(s.lower_bound(idx));
    s.insert(idx);
    del += needDelete(l, idx) + needDelete(idx, r) - needDelete(l, r);
  }
  cout << ans << ENDL;

  return 0;
}