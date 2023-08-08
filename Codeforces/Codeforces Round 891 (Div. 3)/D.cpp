
#include <bits/stdc++.h>
using namespace std;
// AC2++
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
    int n;
    cin >> n;
    vi a(n), b(n);
    vector<pi> ans(n);
    for (auto &x : a) cin >> x;
    FOR(i, 0, n) {
        cin >> b[i];
        ans[i] = {a[i] - b[i], -i};
    }
    sort(ALL(ans), greater<pi>());
    int mayor = ans[0].first;
    vi res;
    FOR(i, 0, n) {
        if (ans[i].first == mayor) {
            res.pb(-ans[i].second + 1);
        } else {
            break;
        }
    }
    int tam = SZ(res);
    cout << tam << ENDL;
    FOR(i, 0, tam) {
        cout << res[i] << " ";
    }
    cout << ENDL;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}