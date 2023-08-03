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

vi costo;

ll calcular(ll x, vi &min_cost, vector<vi> &requer) {
    ll ans = LLINF;
    for (auto y : requer[x]) {
        if (ans == LLINF) ans = 0;
        if (min_cost[y] == -1) {
            min_cost[y] = calcular(y, min_cost, requer);
        }
        ans += min_cost[y];
    }
    min_cost[x] = min(costo[x], ans);
    return min_cost[x];
}

void solve() {
    ll n, k;
    cin >> n >> k;
    costo = vi(n);
    FOR(i, 0, n) {
        cin >> costo[i];
    }
    vi min_cost(n, -1);
    FOR(i, 0, k) {
        ll x;
        cin >> x;
        x--;
        min_cost[x] = 0;
    }

    vector<vi> requer(n, vi());
    FOR(i, 0, n) {
        ll m;
        cin >> m;
        FOR(j, 0, m) {
            ll x;
            cin >> x;
            x--;
            requer[i].pb(x);
        }
    }

    FOR(i, 0, n) {
        if (min_cost[i] == -1) {
            min_cost[i] = calcular(i, min_cost, requer);
        }
        cout << min_cost[i] << " ";
    }
    cout << ENDL;
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