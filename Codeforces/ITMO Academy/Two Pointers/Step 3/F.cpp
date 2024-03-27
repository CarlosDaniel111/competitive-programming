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

  ll n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  vi cnt(200, 0);
  vi a(200, 0);
  FOR(i, 0, m)
  cnt[t[i]]++;

  ll l = 0, ans = 0;
  FOR(r, 0, n) {
    a[s[r]]++;
    if (a[s[r]] > cnt[s[r]]) {
      while (s[l] != s[r]) {
        a[s[l++]]--;
      }
      a[s[l++]]--;
    }
    ans += r - l + 1;
  }
  cout << ans << ENDL;

  return 0;
}