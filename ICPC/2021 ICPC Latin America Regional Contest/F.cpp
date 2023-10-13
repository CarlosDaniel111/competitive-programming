#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

struct DSU {
    vi e;
    DSU() {}
    DSU(int N) { e = vi(N, -1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    void unite(int x, int y) {
        x = get(x), y = get(y);
        if (x == y)
            return;
        if (e[x] > e[y])
            swap(x, y);
        e[x] += e[y];
        e[y] = x;
    }
};

vector<vi> g;
DSU dsu;

int n, m;

void dfs(int u) {
    for (auto v : g[u]) {
        if (dsu.get(u) == dsu.get(v) || (dsu.get(u) == n - 1 && dsu.get(v) == n - 2) || (dsu.get(u) == n - 2 && dsu.get(v) == n - 1))
            continue;
        dsu.unite(u, v);
        dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m;
    dsu = DSU(n);
    g.assign(n, vi());

    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;

        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(n - 2);

    dfs(n - 1);

    FOR(i, 0, n) {
        if (dsu.get(i) == dsu.get(n - 1))
            cout << "A";
        else
            cout << "B";
    }
    cout << ENDL;

    return 0;
}