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

constexpr int MAXN = 1e3 + 5;

int main() {
    int n, x;
    cin >> n >> x;

    int A[n];
    FOR(i, 0, n)
    cin >> A[i];

    vector<int> dp(n, 1);

    int ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (A[i + 1] - A[i] <= x)
            dp[i] = dp[i + 1] + 1;
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
}