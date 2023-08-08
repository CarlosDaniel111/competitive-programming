#include <bits/stdc++.h>

using namespace std;
// AC2#
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define ENDL '\n'

constexpr int MAXN = 1e3 + 5, MOD = 1e9 + 7;

int dp[MAXN][MAXN][3];
// int abajo[MAXN][MAXN][3];
char grid[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cin >> grid[i][j];
            int change = (grid[i][j] == 'G' ? 0 : 1);
            dp[i][j][change] = 1;
            dp[i][j][!change] = 0;
            // abajo[i][j][change] = 1;
            // abajo[i][j][!change] = 0;
        }
    }

    /*ROF(i, n, 0) {
        FOR(j, 0, m - 1) {
            int change = (grid[i][j] == 'G' ? 0 : 1);
            abajo[i][j][change] = abajo[i + 1][j][change] + 1;
        }
    }*/

    /*FOR(i, 0, n) {
        FOR(j, 0, m) {
            cout << abajo[i][j][0] << " ";
        }
        cout << ENDL;
    }*/

    FOR(i, 0, n - 1) {
        ROF(j, m - 1, 0) {
            int change = (grid[i][j] == 'G' ? 0 : 1);
            dp[i][j][change] = dp[i][j + 1][change] + 1;
        }
    }

    ROF(i, n - 1, 0) {
        FOR(j, 0, m) {
            int change = (grid[i][j] == 'G' ? 0 : 1);
            int change2 = (grid[i + 1][j] == 'G' ? 0 : 1);
            dp[i][j][change] = min({dp[i][j][change], dp[i + 1][j][change2] + 1, dp[i + 1][j + 1][change2] + 1});
        }
    }

    ll ans = 0;
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            ans = max(ans, (ll)dp[i][j][0]);
            ans = max(ans, (ll)dp[i][j][1]);
        }
    }

    cout << ans * ans << ENDL;

    return 0;
}