#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<double, double>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<double>;
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

// pairs
#define mp make_pair
#define f first
#define s second

// vectors
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
tcT > int lwb(vector<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }

// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)

#define ENDL '\n'

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int INF = 1 << 28;
const ll LLINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

using edge = tuple<int, ll, ll>;

class max_flow {
   private:
    int V;
    vector<edge> EL;
    vector<vi> AL;
    vi d, last;
    vector<pi> p;
    vector<bool> t;

    bool BFS(int s) {
        d.assign(V, -1);
        d[s] = 0;
        queue<int> q({s});
        p.assign(V, {-1, -1});
        while (sz(q)) {
            int u = q.front();
            q.pop();
            if (t[u]) return 1;
            for (auto &idx : AL[u]) {
                auto &[v, cap, flow] = EL[idx];
                if ((cap - flow > 0) && (d[v] == -1))
                    d[v] = d[u] + 1, q.push(v), p[v] = {u, idx};
            }
        }
        return 0;
    }

    ll DFS(int u, ll f = LLINF) {
        if (t[u] || (f == 0)) return f;
        for (int &i = last[u]; i < sz(AL[u]); i++) {
            auto &[v, cap, flow] = EL[AL[u][i]];
            if (d[v] != d[u] + 1) continue;
            if (ll pushed = DFS(v, min(f, cap - flow))) {
                flow += pushed;
                auto &rflow = get<2>(EL[AL[u][i] ^ 1]);
                rflow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

   public:
    max_flow(int initialV, vector<bool> &aux_t) : V(initialV), t(aux_t) {
        EL.clear();
        AL.assign(V, vi());
    }

    void add_edge(int u, int v, bool directed = true) {
        if (u == v) return;
        EL.emplace_back(v, 1, 0);
        AL[u].pb(sz(EL) - 1);
        EL.emplace_back(u, 0, 0);
        AL[v].pb(sz(EL) - 1);
    }

    ll dinic(int s) {
        ll mf = 0;
        while (BFS(s)) {
            last.assign(V, 0);
            while (ll f = DFS(s, s)) mf += f;
        }
        return mf;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, S, E;
    cin >> n >> S >> E;

    vector<int> start_nodes;
    F0R(i, S) {
        int u;
        cin >> u;
        start_nodes.pb(u - 1);
    }

    vector<bool> t(n * 2 + 1, 0);
    F0R(i, E) {
        int u;
        cin >> u;
        u--;
        t[u] = 1;
    }

    max_flow MF(n * 2 + 1, t);
    F0R(i, n)
    MF.add_edge(i + n, i, 1);

    for (auto u : start_nodes) MF.add_edge(2 * n, u + n);

    int m;
    cin >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        MF.add_edge(u, v + n, 1);
    }

    cout << MF.dinic(2 * n) << ENDL;

    return 0;
}