#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, w;
  cin >> n >> w;
  vector<string> words(n);
  FOR(i, 0, n) {
    cin >> words[i];
  }

  vi dp;
  auto can = [&](int x) -> bool {
    dp.assign(n + 1, w + 1);
    dp[0] = -1;
    FOR(i, 1, n + 1) {
      int mx = 0;
      for (int j = i; j <= n && j - i < x; j++) {
        mx = max(mx, SZ(words[j - 1]));
        dp[j] = min(dp[j], dp[i - 1] + mx + 1);
      }
    }
    return dp[n] <= w;
  };

  int l = 1, r = n + 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  can(l);
  vector<pi> ans;
  int mx_len = 0, mx_cur = 0;
  ROF(i, n + 1, 1) {
    mx_len = max(mx_len, SZ(words[i - 1]));
    mx_cur = max(mx_cur, dp[i]);
    if (dp[i - 1] + mx_len + 1 == mx_cur) {
      ans.pb({i - 1, mx_cur});
      mx_len = mx_cur = 0;
    }
  }

  sort(ALL(ans));
  int x = l, y = SZ(ans);
  cout << x << " " << y << ENDL;

  int ant = 0;
  vector<pi> len;
  for (auto a : ans) {
    len.pb({a.first, a.second - ant});
    cout << a.second - ant << " ";
    ant = a.second + 1;
  }
  cout << ENDL;

  len.pb({n, n});
  vector<vector<string>> ans2(x, vector<string>(y));

  FOR(i, 0, y) {
    int r = 0;
    FOR(j, len[i].first, len[i + 1].first) {
      string espacio(len[i].second - SZ(words[j]), ' ');
      ans2[r++][i] = words[j] + espacio;
    }
    string espacio(len[i].second, ' ');
    for (; r < x; r++) {
      ans2[r][i] = espacio;
    }
  }

  FOR(i, 0, x) {
    FOR(j, 0, y) {
      cout << ans2[i][j] << " ";
    }
    cout << ENDL;
  }

  return 0;
}