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

  ll n, c;
  string s;
  cin >> n >> c >> s;
  ll na = 0, nb = 0, suma = 0, l = 0, ans = 0;
  FOR(r, 0, n) {
    if (s[r] == 'a') {
      na++;
    } else if (s[r] == 'b') {
      nb++;
      suma += na;
    }
    while (suma > c) {
      if (s[l] == 'a') {
        na--;
        suma -= nb;
      } else if (s[l] == 'b') {
        nb--;
      }
      l++;
    }
    ans = max(ans, r - l + 1);
  }
  cout << ans << ENDL;

  return 0;
}