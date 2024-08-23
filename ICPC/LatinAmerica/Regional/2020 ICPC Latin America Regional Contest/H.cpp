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

struct Dinic {
    struct Edge {
        int to, rev;
        ll c, oc;
        ll flow() { return max(oc - c, 0LL); }  // if you need flows
    };
    vi lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
    void addEdge(int a, int b, ll c, ll rcap = 0) {
        adj[a].push_back({b, SZ(adj[b]), c, c});
        adj[b].push_back({a, SZ(adj[a]) - 1, rcap, rcap});
    }
    ll dfs(int v, int t, ll f) {
        if (v == t || !f) return f;
        for (int& i = ptr[v]; i < SZ(adj[v]); i++) {
            Edge& e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1)
                if (ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
        }
        return 0;
    }
    ll calc(int s, int t) {
        ll flow = 0;
        q[0] = s;
        FOR(L, 0, 31)
        do {  // 'int L=30' maybe faster for random data
            lvl = ptr = vi(SZ(q));
            int qi = 0, qe = lvl[s] = 1;
            while (qi < qe && !lvl[t]) {
                int v = q[qi++];
                for (Edge e : adj[v])
                    if (!lvl[e.to] && e.c >> (30 - L))
                        q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
            }
            while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
        } while (lvl[t]);
        return flow;
    }
    bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int graph[105][105];
const int MAXIMO = 1e4 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;

    FOR(i, 0, n) {
        char K[10];
        cin >> K;
        if (K[0] == '*') {
            int l;
            cin >> l;
            l--;
            if (l == 0) {
                l = n;
            }
            graph[i][l] = MAXIMO + 1;
        } else {
            int k = stoi(K);
            FOR(j, 0, k) {
                int l;
                cin >> l;
                l--;
                if (l == 0) {
                    l = n;
                }
                graph[i][l]++;
            }
        }
    }

    Dinic mf(n + 1);
    FOR(i, 0, n + 1) {
        FOR(j, 0, n + 1) {
            if (graph[i][j]) {
                // cout << i << " " << j << " " << graph[i][j] << ENDL;
                mf.addEdge(i, j, graph[i][j]);
            }
        }
    }

    int ans = mf.calc(0, n);
    if (ans >= MAXIMO) {
        cout << '*' << ENDL;
    } else {
        cout << ans + 1 << ENDL;
    }

    return 0;
}