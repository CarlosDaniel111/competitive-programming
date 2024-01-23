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
  if (actual == n) return -INF;
  if (pos == SZ(pat[actual])) return val[actual];
  if (l > r) return (pos == 0 ? 0 : -INF);
  int &ans = dp[l][r][actual][pos];
  if (ans != -1) return ans;
  ans = (l == 0 ? 0 : -INF);

  if (pos == 0)
    ans = max(ans, solve(l, r, actual + 1, pos));

  FOR(i, l, r + 1) {
    if (s[i] == pat[actual][pos])
      ans = max(ans, solve(i + 1, r, actual, pos + 1) + solve(l, i - 1, 0, 0));
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
  cout << solve(0, len - 1, 0, 0) << ENDL;

  return 0;
}