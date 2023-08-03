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
    int n, k;
    cin >> n >> k;
    vi cont(n + 1, 0);
    int aux = 0, primero;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        if (i == 0) {
            primero = x;
        }
        if (primero == x) {
            cont[primero]++;
        } else if (cont[primero] >= k) {
            cont[x]++;
        }
        if (i == n - 1) {
            if (cont[x] >= k && cont[primero] >= k) {
                cout << "YES" << ENDL;
            } else {
                cout << "NO" << ENDL;
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