#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = unsigned long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define ROF(i, a, b) for (ll i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __                      \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);

constexpr ll LIM = 1e18;

signed main() {
  __
      ll r,
      s, m, d, n;
  cin >> r >> s >> m >> d >> n;
  vi b(r);
  for (auto &x : b)
    cin >> x;
  vector<vi> ing(s + m + d);
  FOR(i, 0, s + m + d) {
    ll k;
    cin >> k;
    FOR(j, 0, k) {
      ll x;
      cin >> x;
      ing[i].pb(x - 1);
    }
  }
  vector<vector<bool>> ban(s + m + d, vector<bool>(s + m + d, 0));
  FOR(i, 0, n) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    ban[min(u, v)][max(u, v)] = 1;
  }
  ll ans = 0;
  FOR(i, 0, s) {
    FOR(j, s, s + m) {
      FOR(k, s + m, s + m + d) {
        if (ban[i][j] || ban[i][k] || ban[j][k])
          continue;
        vi cnt(1005, 0);
        for (auto &x : ing[i])
          cnt[x]++;
        for (auto &x : ing[j])
          cnt[x]++;
        for (auto &x : ing[k])
          cnt[x]++;
        ll prod = 1;
        FOR(l, 0, r) {
          if (cnt[l] == 0) continue;
          ll tam = SZ(to_string(prod)) + SZ(to_string(b[l]));
          prod *= b[l];
          if (tam >= 20 && prod != 1e18) {
            cout << "too many" << ENDL;
            return 0;
          }
        }
        ans += prod;
        if (ans > LIM) {
          cout << "too many" << ENDL;
          return 0;
        }
      }
    }
  }
  cout << ans << ENDL;

  return 0;
}