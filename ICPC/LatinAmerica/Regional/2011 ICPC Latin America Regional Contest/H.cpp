#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
#define ENDL '\n'
#define FOR(x, n) for (long long x = 0; x < (long long)n; x++)
#define FOR1(x, n) for (long long x = 1; x <= (long long)n; x++)
#define FORR(x, n) for (long long x = n - 1; x >= 0; x--)
#define FORR1(x, n) for (long long x = n; x >= 1; x--)
const long long INF = 1 << 28, MOD = 1e9 + 7, MAXN = 1e5 + 5;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vii;

vector<bool> visited;
vector<int> tin, low;
int timer;

class UnionFind {
  private:
    vi p, rank;

  public:
    UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) {
            p[i] = i;
        }
    }
    int get(int i) {
        return (p[i] == i) ? i : (p[i] = get(p[i]));
    }
    bool isSameSet(int i, int j) {
        return get(i) == get(j);
    }
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = get(i), y = get(j);
            if (rank[x] > rank[y]) {
                p[y] = x;
            } else {
                p[x] = y;
                if (rank[x] == rank[y]) {
                    rank[y]++;
                }
            }
        }
    }
};

void dfs(int v, int p, vector<vector<int>> &graph, UnionFind &UF) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : graph[v]) {
        if (to == p)
            continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v, graph, UF);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                // encontramos un puente
                // puentes.emplace(to);
                // puentes.emplace(v);
                UF.unionSet(to, v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;
    while (true) {
        timer = 0;
        visited.assign(a + 1, false);
        UnionFind UF(a + 1);
        low.assign(a + 1, -1);
        tin.assign(a + 1, -1);
        vector<vector<int>> graph(a + 1);
        FOR(i, a + 1) {
            vector<int> vec;
            graph[i] = vec;
        }
        FOR(i, b) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for (int i = 0; i <= a; i++) {
            if (!visited[i]) {
                dfs(i, -1, graph, UF);
            }
        }
        FOR(i, c) {
            // procesar consultas aqui;
            int x, y;
            cin >> x >> y;
            if (UF.isSameSet(x, y)) {
                cout << 'Y' << '\n';
            } else {
                cout << 'N' << '\n';
            }
        }
        cout << '-' << '\n';
        cin >> a >> b >> c;
        if (a || b || c) {
            continue;
        } else {
            break;
        }
    }
    return 0;
}
