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
constexpr int MAXN = 2e5 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

vector<pi> graph[MAXN];
vector<ll> dist;

bool dfs(int u, ll d) {
    if (dist[u] != LLINF) {
        return (d == dist[u]);
    }
    dist[u] = d;
    for (auto to : graph[u]) {
        if (!dfs(to.first, d + ll(to.second))) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vi in_degree(n, 0);
    FOR(i, 0, MAXN) {
        graph[i].clear();
    }
    FOR(i, 0, m) {
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        graph[x].pb({y, w});
        graph[y].pb({x, -w});
    }
    dist = vector<ll>(n, LLINF);
    FOR(i, 0, n) {
        if (dist[i] == LLINF) {
            if (!dfs(i, 0)) {
                cout << "NO" << ENDL;
                return;
            }
        }
    }
    cout << "YES" << ENDL;
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