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
#define tcT template <class T
tcT > int lwb(vector<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }

// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define R0F(i, a) ROF(i, a, 0)

#define ENDL '\n'
#define LSOne(S) ((S) & -(S))

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int INF = 1 << 28;
const ll LLINF = 1e18;
const int dx[4] = {1, 0, -1, 0},
          dy[4] = {0, 1, 0, -1};  // abajo, derecha, arriba, izquierda

template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

int n;
vi graph[MAXN];
int tin[MAXN], low[MAXN], timer;
set<pair<int, int>> puentes;
bool nodesValid[MAXN];
bool visited[MAXN];

struct DSU {  // Indice base 0
    vi e;
    void init(int N) { e = vi(N, -1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return 0;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};

DSU UF;

void check_bridge(int u, int p = -1) {
    tin[u] = low[u] = timer++;
    for (int to : graph[u]) {
        if (to == p) continue;
        if (tin[to] != -1)
            low[u] = min(low[u], tin[to]);
        else {
            check_bridge(to, u);
            if (low[to] > tin[u]) {
                puentes.insert({min(u, to), max(u, to)});
            }
            low[u] = min(low[u], low[to]);
        }
    }
}

bool check_cycle(int u) {
    for (int to : graph[u]) {
        if (puentes.count({u, to}) == 0 && puentes.count({to, u}) == 0) {
            return false;
        }
    }
    return true;
}

void createDSU(int u, int p = -1) {
    for (int to : graph[u]) {
        if (to == p) continue;
        if (!visited[to] && nodesValid[to]) {
            UF.unite(u, to);
            createDSU(to, u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int m, q;
    cin >> n >> m >> q;
    F0R(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    // Buscar puentes
    timer = 0;
    fill(tin, tin + n, -1);
    fill(low, low + n, -1);

    F0R(i, n) {
        if (tin[i] == -1) {
            check_bridge(i);
        }
    }

    F0R(i, n) { nodesValid[i] = check_cycle(i); }

    UF.init(n);

    F0R(i, n) {
        if (!visited[i] && nodesValid[i]) {
            createDSU(i);
        }
    }
    F0R(i, q) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (UF.sameSet(x, y)) {
            cout << "YES" << ENDL;
        } else {
            cout << "NO" << ENDL;
        }
    }

    return 0;
}
