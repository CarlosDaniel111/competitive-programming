#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

int n, k;
string s;
int dp[505][505][505];

int solve(int l, int r, int falta) {
  if (falta == 0) return 0;
  if (falta == 1 && l <= r) return 0;
  if (l >= r) return 3e8;

  int &ans = dp[l][r][falta];
  if (ans != -1) return ans;

  if (s[l] == s[r]) return ans = solve(l + 1, r - 1, falta - 2);
  ans = solve(l + 1, r, falta);
  ans = min(ans, solve(l, r - 1, falta));
  ans = min(ans, solve(l + 1, r - 1, falta - 2) + 1);
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n >> k;
  cin >> s;
  memset(dp, -1, sizeof(dp));
  cout << solve(0, n - 1, k) << ENDL;

  return 0;
}