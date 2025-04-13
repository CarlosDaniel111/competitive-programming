#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

// s[i,n) + & + t[j,m)

int dp[505][505][2];

vi Z(const string& S) {
  vi z(SZ(S));
  int l = -1, r = -1;
  FOR(i, 1, SZ(S)) {
    z[i] = i >= r ? 0 : min(r - i, z[i - l]);
    while (i + z[i] < SZ(S) && S[i + z[i]] == S[z[i]]) z[i]++;
    if (i + z[i] > r) l = i, r = i + z[i];
  }
  return z;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  int ans = 1e6;
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      FOR(k, i, n) { dp[k][j][1] = dp[i][j][0] + 1; }
      string s2 = s.substr(i);
      string t2 = t.substr(j);
      string con = s2 + "%" + t2;
      vi z = Z(con);
      bool encontro = false;
      int mx = 0;
      FOR(p, 0, SZ(t2)) {
        int k = z[SZ(s2) + 1 + p];
        mx = max(mx, k);
        dp[i + k][j + p + k][0] = dp[i][j][1] + k;
        // encontro |= (k != 0);
      }
      ans = min(ans, dp[i][j][1] + mx);
      // if (!encontro) ans = min(ans, dp[i][j][1]);
    }
  }
  cout << ans << ENDL;

  return 0;
}