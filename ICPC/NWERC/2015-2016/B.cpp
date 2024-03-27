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

vector<pi> emp;
vector<int> good;
vector<pi> bad;
int n, p;

vector<vi> dp;

int solve(int i, int line) {
  if (line <= 0 && i != SZ(bad)) return -3e8;
  if (i == SZ(bad)) return 0;
  int &ans = dp[i][line];
  if (ans != -3e8) return ans;
  ans = -3e8;
  int l = bad[i].first;
  int r = bad[i].second;
  for (int j = i + 1; l < r && j <= SZ(bad); j++) {
    ans = max(ans, solve(j, line - 1) + (r - l));
    l = max(l, bad[j].first);
    r = min(r, bad[j].second);
  }
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n >> p;
  emp.resize(n);
  dp.assign(n + 5, vi(p + 5, -3e8));
  FOR(i, 0, n) {
    cin >> emp[i].first >> emp[i].second;
  }

  FOR(i, 0, n) {
    bool bueno = false;
    FOR(j, 0, n) {
      if (i == j) continue;
      if (emp[i] == emp[j]) {
        if (i > j) {
          bueno = true;
          break;
        }
      } else if (emp[i].first <= emp[j].first && emp[i].second >= emp[j].second) {
        bueno = true;
        break;
      }
    }

    if (bueno) {
      good.pb(emp[i].second - emp[i].first);
    } else {
      bad.pb(emp[i]);
    }
  }

  sort(ALL(bad));
  sort(ALL(good), greater<int>());

  FOR(i, 1, p + 1) {
    solve(0, i);
  }

  int ngood = SZ(good);
  vi prefix(ngood + 1, 0);
  FOR(i, 1, ngood + 1) {
    prefix[i] = prefix[i - 1] + good[i - 1];
  }

  int ans = 0;
  FOR(i, 0, p) {
    if (i <= ngood)
      ans = max(ans, dp[0][p - i] + prefix[i]);
  }
  cout << ans << ENDL;

  return 0;
}