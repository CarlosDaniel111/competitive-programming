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

vector<string> num;
int n, m;
int dp[45][45][405][15];

int solve(int l, int r, int pos, int newDigit) {
  if (l == n || pos == m || l > r) return 0;
  if (newDigit > 9) return 3e8;
  int &ans = dp[l][r][pos][newDigit];
  if (ans != -1) return ans;
  ans = solve(l, r, pos, newDigit + 1);
  int changes = 0;
  FOR(i, l, r + 1) {
    changes += (num[i][pos] - '0' != newDigit);
    ans = min(ans, solve(i + 1, r, pos, newDigit + 1) + solve(l, i, pos + 1, 0) + changes);
  }
  return ans;
}

void build(int l, int r, int pos, int newDigit) {
  if (l == n || pos == m || l > r || newDigit > 9) return;
  int mxi = -1;
  int ans = solve(l, r, pos, newDigit + 1);
  int changes = 0;
  FOR(i, l, r + 1) {
    changes += (num[i][pos] - '0' != newDigit);
    int x = solve(i + 1, r, pos, newDigit + 1) + solve(l, i, pos + 1, 0) + changes;
    if (x < ans) {
      ans = x;
      mxi = i;
    }
  }

  if (mxi == -1) {
    build(l, r, pos, newDigit + 1);
  } else {
    FOR(i, l, mxi + 1) {
      num[i][pos] = newDigit + '0';
    }
    build(mxi + 1, r, pos, newDigit + 1);
    build(l, mxi, pos + 1, 0);
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  memset(dp, -1, sizeof(dp));
  cin >> n >> m;
  num.resize(n);
  FOR(i, 0, n) {
    cin >> num[i];
  }
  build(0, n - 1, 0, 0);
  FOR(i, 0, n) {
    cout << num[i] << ENDL;
  }

  return 0;
}