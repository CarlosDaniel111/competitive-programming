#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

constexpr int INF = 3e8;

string s;
vector<string> pat;
vi val;
int n;

int dp[55][55][405][55];

int solve(int l, int r, int actual, int pos) {
  if (l > r) return (actual == n ? 0 : -INF);
  int &ans = dp[l][r][actual][pos];
  if (ans != -1) return ans;
  ans = -INF;
  if (actual == n) {
    FOR(i, 0, n) {
      if (pat[i][0] == s[l]) {
        if (pat[i][1] != '\0')
          ans = max(ans, solve(l + 1, r, i, 1));
        else
          ans = max(ans, solve(l + 1, r, n, 0) + val[i]);
      }
    }
  } else {
    FOR(i, l, r + 1) {
      if (pat[actual][pos] == s[i]) {
        if (pat[actual][pos + 1] != '\0')
          ans = max(ans, solve(i + 1, r, actual, pos + 1) + solve(l, i - 1, n, 0));
        else
          ans = max(ans, solve(i + 1, r, n, 0) + solve(l, i - 1, n, 0) + val[actual]);
      }
    }
  }
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  memset(dp, -1, sizeof dp);
  cin >> s;
  cin >> n;
  pat.resize(n * 2);
  val.resize(n * 2);
  FOR(i, 0, n) {
    cin >> pat[i] >> val[i];
    pat[i + n] = pat[i];
    reverse(ALL(pat[i + n]));
    val[i + n] = val[i];
  }
  n *= 2;

  int len = SZ(s);
  vi dp2(len, 0);
  FOR(i, 0, len) {
    dp2[i] = (i == 0 ? 0 : dp2[i - 1]);
    FOR(j, 0, i + 1) {
      dp2[i] = max(dp2[i], (j == 0 ? 0 : dp2[j - 1]) + solve(j, i, n, 0));
    }
  }

  cout << dp2[len - 1] << ENDL;

  return 0;
}