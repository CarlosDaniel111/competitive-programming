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

void solve() {
    int m, k, x1, xk;
    cin >> m >> k >> x1 >> xk;
    if (xk * k <= m) {
        m -= xk * k;
        xk = 0;
    } else {
        int necesarias = m / k;
        xk -= necesarias;
        m = m % k;
        m -= x1;
        if (m <= 0) {
            cout << 0 << ENDL;
        } else {
            cout << m << ENDL;
        }
        return;
    }
    int ans = 0;
    if (x1 >= m) {
        cout << 0 << ENDL;
        return;
    }

    int residuo = m % k;
    m /= k;
    if (residuo <= x1) {
        x1 -= residuo;
        residuo = 0;
    } else {
        ans += residuo - x1;
        residuo = 0;
        x1 = 0;
    }
    if (m <= 0) {
        cout << ans << ENDL;
        return;
    }

    m -= x1 / k;
    if (m <= 0) {
        cout << ans << ENDL;
    } else {
        ans += m;
        cout
            << ans << ENDL;
    }

    // cout << m << ENDL;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}