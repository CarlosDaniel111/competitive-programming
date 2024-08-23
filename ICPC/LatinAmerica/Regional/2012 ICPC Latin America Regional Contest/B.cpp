#include <bits/stdc++.h>
using namespace std;
// AC2++
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
constexpr int MAXN = 1e5 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

int dp[105][205][205];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    dp[0][0][0] = 1;
    FOR(i, 0, 101) {
        FOR(j, 0, 201) {
            FOR(k, 0, j + 1) {
                for (int p = 0; p + j <= 200; p++) {
                    dp[i + 1][j + p][k / 2 + p] += dp[i][j][k];
                    dp[i + 1][j + p][k / 2 + p] %= MOD;
                }
            }
        }
    }

    int s, b;
    while (cin >> s >> b) {
        cout << dp[b][s][0] << ENDL;
    }

    return 0;
}