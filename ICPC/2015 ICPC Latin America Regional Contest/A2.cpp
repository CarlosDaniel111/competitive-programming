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

int n;
string s;
ll pow3[15];
ll dp[20][60000][3];

ll solve(int pos, int mask, int cambio, ll num) {
    if (pos == n) {
        return num;
    }

    ll &ans = dp[pos][mask][cambio];
    if (ans != -1) return ans;

    int aux_mask = mask;
    vi mask_array(11, 0);
    ROF(j, 11, 0) {
        while (aux_mask - pow3[j] >= 0) {
            mask_array[j]++;
            aux_mask -= pow3[j];
        }
    }

    if (cambio == 0) {
        int digit = s[pos] - '0';
        if (mask_array[digit] < 2) {
            ll next = num * 10 + digit;
            ans = max(ans, solve(pos + 1, mask + pow3[digit], 0, next));
        }
        ROF(i, digit, 0) {
            if (mask_array[i] < 2) {
                ll next = num * 10 + i;
                ans = max(ans, solve(pos + 1, mask + pow3[i], 1, next));
            }
        }
    } else {
        ROF(i, 10, 0) {
            if (mask_array[i] < 2) {
                ll next = num * 10 + i;
                ans = max(ans, solve(pos + 1, mask + pow3[i], 1, next));
            }
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> s;
    n = SZ(s);
    pow3[0] = 1;
    memset(dp, -1, sizeof(dp));
    FOR(i, 1, 15) {
        pow3[i] = pow3[i - 1] * 3;
    }

    cout << solve(0, 0, 0, 0) << ENDL;

    return 0;
}