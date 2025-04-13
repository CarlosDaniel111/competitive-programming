#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;

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
    // AC2++
    int b, c, h;
    cin >> b >> c >> h;

    int aux = c + h;
    if (b == aux) {
        cout << b * 2 - 1 << ENDL;
    } else if (b > aux) {
        cout << aux * 2 + 1 << ENDL;
    } else {
        int ans = b * 2 - 1;
        cout << ans << ENDL;
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