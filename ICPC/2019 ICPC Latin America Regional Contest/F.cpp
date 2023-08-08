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
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define ENDL '\n'

constexpr int MAXN = 5005, MOD = 1e9 + 7;

// AC2#

ll dp[MAXN][MAXN];

ll solve(int l, int res) {
    if (res < 0)
        return 0;
    if (res == 0 || l == 1)
        return 1;
    if (l == 0)
        return 0;
    if (dp[l][res] != -1)
        return dp[l][res];
    ll primero = solve(l, res - l);
    ll segundo = solve(l - 1, res) * 2 % MOD;
    ll tercero = solve(l - 2, res);
    return dp[l][res] = ((((primero + segundo) % MOD) - tercero + MOD) % MOD);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int S, B;
    cin >> S >> B;

    memset(dp, -1, sizeof dp);

    cout << solve(S, B - S);

    return 0;
}