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
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define ENDL '\n'

constexpr int MAXN = 1e4 + 5, MOD = 1e9 + 7;

vector<int> g[MAXN];
ll dp[MAXN];
bool processed[MAXN];
int n, l;
unordered_set<int> real_values;

ll dfs(int u) {
    if (processed[u])
        return dp[u];

    processed[u] = 1;

    if (u >= l) {
        real_values.insert(u);
        return dp[u] = 1;
    }

    for (int &v : g[u])
        dp[u] = (dp[u] + dfs(v)) % MOD;

    return dp[u];
}

int main() {
    cin >> n >> l;

    FOR(i, 0, l) {
        int k;
        cin >> k;

        while (k--) {
            int x;
            cin >> x;

            g[i].push_back(x - 1);
        }
    }

    ll ans = dfs(0);
    cout << ans << ' ' << SZ(real_values) << ENDL;

    return 0;
}