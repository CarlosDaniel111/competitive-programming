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

struct DSU {
    vi e;
    DSU(int N) { e = vi(N, -1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y)
            return 0;
        if (e[x] > e[y])
            swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};

void solve() {
    // AC2++
    int n, m;
    cin >> n >> m;
    vector<pi> heights(n);
    FOR(i, 0, n) {
        int x;
        cin >> x;
        heights[i] = {x, i};
    }
    vector<vi> graph(n, vi());
    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (heights[u].first > heights[v].first) {
            graph[u].pb(v);
        } else {
            graph[v].pb(u);
        }
    }
    int q;
    cin >> q;
    vector<tuple<int, int, int, int>> querys(q);
    FOR(i, 0, q) {
        int a, b, e;
        cin >> a >> b >> e;
        a--;
        b--;
        querys[i] = {heights[a].first + e, i, a, b};
    }

    sort(ALL(heights));
    sort(ALL(querys));

    DSU dsu(n);
    vector<bool> ans(q);

    int j = 0;
    for (auto e : querys) {
        auto [energia, pos, a, b] = e;
        while (j < n && heights[j].first <= energia) {
            for (int u : graph[heights[j].second]) {
                dsu.unite(heights[j].second, u);
            }
            j++;
        }
        ans[pos] = dsu.sameSet(a, b);
    }
    FOR(i, 0, q) {
        cout << (ans[i] ? "YES" : "NO");
        cout << ENDL;
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