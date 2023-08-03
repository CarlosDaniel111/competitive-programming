#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e3 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

ll dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n) {
        memset(dp, 0, sizeof(dp));
        FOR(i, 1, n + 1) {
            FOR(j, 1, i + 1) {
                cin >> dp[i - j + 1][j];
            }
        }

        FOR(i, 1, n + 1) {
            FOR(j, 1, n - i + 2) {
                dp[i][j] += dp[i][j - 1];
            }
        }

        FOR(i, 1, n + 1) {
            ROF(j, n - i + 1, 0) {
                dp[i][j] = max(dp[i][j], dp[i][j + 1]);
                dp[i + 1][j] += dp[i][j];
            }
        }

        ll ans = 0;
        FOR(i, 1, n + 1) {
            ans = max(ans, dp[i][1]);
        }
        cout << ans << ENDL;
    }

    return 0;
}