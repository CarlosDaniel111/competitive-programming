#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ll((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define ROF(i, a, b) for (ll i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr ll MOD = 1e9 + 7;
constexpr ll MAXN = 1e5 + 5;
constexpr ll INF = 1e9;
constexpr ll LLINF = 1e18;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll n, s;
  cin >> n >> s;
  vi w(n);
  for (ll &x : w) cin >> x;
  vi c(n);
  for (ll &x : c) cin >> x;
  vi prefix(n + 1);
  prefix[0] = 0;
  FOR(i, 1, n + 1) {
    prefix[i] = prefix[i - 1] + c[i - 1];
  }

  ll l = 0;
  ll ans = 0, suma = 0;
  FOR(r, 0, n) {
    suma += w[r];
    while (suma > s) {
      suma -= w[l++];
    }
    ans = max(ans, prefix[r + 1] - prefix[l]);
  }
  cout << ans << ENDL;

  return 0;
}