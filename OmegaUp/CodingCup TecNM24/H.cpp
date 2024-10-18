#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int p;
            cin >> p;
            a[i].push_back(p);
        }
    }
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    for (auto &p : a[0]) if (p <= m) dp[0][p] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (auto &p : a[i]) {
                if (j - p >= 0 && dp[i - 1][j - p]) {
                    dp[i][j] = 1;
                    break;
                }
            }
        }
    }
    for (int i = m; i >= 0; --i) {
        if (dp[n - 1][i]) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}