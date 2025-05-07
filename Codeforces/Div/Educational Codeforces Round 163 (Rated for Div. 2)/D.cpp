#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

void solve() {
  string s;
  cin >> s;
  int n = SZ(s);
  vector<vi> iguales(n, vi(n, 0));
  FOR(i, 0, n) {
    FOR(j, 1, n) {
      if (i + j >= n) break;
      if (s[i] == '?' || s[i + j] == '?' || s[i] == s[i + j]) iguales[i][j] = 1;
    }
  }
  int ans = 0;
  FOR(j, 1, n) {
    int cnt = 0;
    int mx = 0;
    FOR(i, 0, n) {
      if (iguales[i][j]) {
        cnt++;
        mx = max(mx, cnt);
      } else {
        cnt = 0;
      }
    }
    if (mx >= j)
      ans = max(j, ans);
  }
  cout << ans * 2 << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}