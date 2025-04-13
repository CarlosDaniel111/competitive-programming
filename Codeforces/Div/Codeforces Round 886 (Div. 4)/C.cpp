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
constexpr int MAXN = 1e5 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

void solve() {
    char grid[10][10];
    FOR(i, 0, 8) {
        FOR(j, 0, 8) {
            cin >> grid[i][j];
        }
    }

    string ans = "";
    FOR(i, 0, 8) {
        FOR(j, 0, 8) {
            if (grid[i][j] != '.') {
                ans += grid[i][j];
                while ((i + 1 < 8 && grid[i + 1][j] != '.') || (j + 1 < 8 && grid[i][j + 1] != '.')) {
                    if (grid[i + 1][j] != '.') {
                        ans += grid[i + 1][j];
                        i++;
                    } else {
                        ans += grid[i][j + 1];
                        j++;
                    }
                }
                cout << ans << ENDL;
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}