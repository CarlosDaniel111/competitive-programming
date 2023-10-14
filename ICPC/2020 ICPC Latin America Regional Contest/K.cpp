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

ll dp[10005][755];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int k, l;
    cin >> k >> l;
    vector<vi> a(k, vi(k));
    FOR(i, 0, k) {
        for (auto &x : a[i]) cin >> x;
    }

    int n;
    cin >> n;
    vi p(n);
    for (auto &x : p) cin >> x;

    FOR(i, 0, k) {
        dp[n - 1][i] = i + 1;
    }

    ROF(i, n - 1, 0) {
        FOR(j, 0, k) {
            dp[i][j] = j ? dp[i][j - 1] : 0;
            int primero = upper_bound(ALL(a[j]), p[i] + l) - a[j].begin();
            ll v1 = primero ? dp[i + 1][primero - 1] : 0;
            int ultimo = lower_bound(ALL(a[j]), p[i] - l) - a[j].begin();
            ll v2 = ultimo ? dp[i + 1][ultimo - 1] : 0;
            dp[i][j] = (dp[i][j] + v1 - v2 + MOD) % MOD;
        }
    }
    cout << dp[0][k - 1];

    return 0;
}