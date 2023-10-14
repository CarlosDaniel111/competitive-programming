#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7, MAXN = 5e5 + 5;

ll n = -1, bit[MAXN];
ll query(int index) {
    if (index == 0)
        return 0;

    ll sum = 0;
    while (index > 0) {
        sum += bit[index];
        index -= index & (-index);
    }
    return sum > 0;
}

void add(int index, int val) {
    while (index <= MAXN - 1) {
        bit[index] += val;
        index += index & (-index);
    }
}

int main() {
    int m, x;
    cin >> m >> x;

    while (m--) {
        ll k, d;
        cin >> k >> d;
        add(k, 1);
        // cerr << query(k + 1) << ENDL;
        add(k + d + 1, -1);
        n = max(n, k + d);
    }

    n += 800;
    int ans = 1e9, ind_ans;
    vector<ll> dp(n, 0);
    for (int i = n - x - 1; i >= 0; i--) {
        dp[i] = dp[i + x] + query(i);

        if (i <= 480 && dp[i] == ans)
            ind_ans = i;
        if (i <= 480 && dp[i] < ans) {
            ans = dp[i];
            ind_ans = i;
        }
    }
    cout << ind_ans << ' ' << ans << ENDL;

    return 0;
}