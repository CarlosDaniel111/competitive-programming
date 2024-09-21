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

constexpr int MAX = 55;
bitset<2505> dp[MAX][MAX][MAX];

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, K;
  string s;
  cin >> n >> K >> s;
  FOR(i, 0, n + 1) dp[0][0][i][0] = 1;
  FOR(i, 1, n + 1) {
    FOR(j, 0, i + 1) {
      FOR(k, 0, n - i + 1) {
        if ((s[i - 1] == 'N' || s[i - 1] == '?') && j)
          dp[i][j][k] |= dp[i - 1][j - 1][k];
        if (s[i - 1] == 'A' || s[i - 1] == '?')
          dp[i][j][k] |= dp[i - 1][j][k] << (j * k);
        if (s[i - 1] == 'C' || s[i - 1] == '?')
          dp[i][j][k] |= dp[i - 1][j][k + 1];
        if (s[i - 1] != 'N' && s[i - 1] != 'A' && s[i - 1] != 'C')
          dp[i][j][k] |= dp[i - 1][j][k];
      }
    }
  }

  int aux = -1;
  FOR(i, 0, n + 1) {
    if (dp[n][i][0][K]) aux = i;
  }
  if (aux == -1) {
    cout << aux << ENDL;
    return 0;
  }
  int j = aux, k = 0, now = K;

  ROF(i, n + 1, 1) {
    if (s[i - 1] == 'N' || (s[i - 1] == '?' && j && dp[i - 1][j - 1][k][now]))
      s[i - 1] = 'N', j--;
    else if (s[i - 1] == 'A' ||
             (s[i - 1] == '?' && now >= j * k && dp[i - 1][j][k][now - j * k]))
      s[i - 1] = 'A', now -= j * k;
    else if (s[i - 1] == 'C' || (s[i - 1] == '?' && dp[i - 1][j][k + 1][now]))
      s[i - 1] = 'C', k++;
  }
  cout << s << ENDL;

  return 0;
}