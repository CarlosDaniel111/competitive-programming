#include <bits/stdc++.h>
using namespace std;
// AC2++
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

struct DSU {
    vi e;
    DSU(int N) { e = vi(N, -1); }
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
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

vi tree[MAXN];
int jump[MAXN][20];  // Donde jump[u][h] es el ancestro 2^h del nodo u
int depth[MAXN], p[MAXN], pciclo[MAXN], visited[MAXN], val[MAXN], tamciclo[MAXN], papi[MAXN];

void getArbol(int u, int d = 0) {
    visited[u] = 1;
    depth[u] = d;
    for (auto &hijo : tree[u]) {
        if (!visited[hijo]) {
            if (pciclo[hijo] != -1) {
                getArbol(hijo, d);
            } else {
                papi[hijo] = u;
                getArbol(hijo, d + 1);
            }
        }
    }
}

void build(int n) {
    FOR(i, 0, n) {
        if (pciclo[i] != -1)
            jump[i][0] = -1;
        else
            jump[i][0] = papi[i];
    }

    // Construccion del binary-lifting
    for (int i = 1; (1 << i) <= n; i++)
        for (int u = 0; u < n; u++)
            if (jump[u][i - 1] != -1)
                jump[u][i] = jump[jump[u][i - 1]][i - 1];
}

pi LCA(int p, int q) {
    if (p == q) return make_pair(p, q);
    if (depth[p] < depth[q])
        swap(p, q);

    int dist = depth[p] - depth[q];  // Distancia necesaria para estar en la misma profundidad
    for (int i = 16; i >= 0; i--)
        if (dist >= (1 << i)) {
            dist -= 1 << i;
            p = jump[p][i];
        }

    if (p == q || depth[p] == 0)  // Verificar si el ancestro es la misma profundidad
        return make_pair(p, q);

    // Busqueda por saltos binarios
    for (int i = 16; i >= 0; i--)
        if (jump[p][i] != jump[q][i] && depth[jump[p][i]] != 0) {
            p = jump[p][i];
            q = jump[q][i];
        }

    return make_pair(papi[p], papi[q]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        memset(jump, -1, sizeof jump);
        memset(p, -1, sizeof p);
        memset(pciclo, -1, sizeof pciclo);
        memset(papi, -1, sizeof(papi));
        memset(depth, 0, sizeof depth);
        memset(visited, 0, sizeof visited);
        memset(tamciclo, 0, sizeof(tamciclo));
        memset(val, 0, sizeof(val));

        FOR(i, 0, n) {
            tree[i].clear();
        }

        DSU uf(n);

        FOR(i, 0, n) {
            int u;
            cin >> u;
            u--;
            if (uf.get(i) == uf.get(u)) {
                int aux = i;
                int tam = 0;
                p[i] = u;

                while (true) {
                    tam++;
                    visited[aux] = 1;
                    pciclo[aux] = p[aux];
                    aux = p[aux];
                    if (visited[aux]) break;
                }

                int aux2 = i;
                for (int j = 1;; j++) {
                    val[aux2] = j;
                    tamciclo[aux2] = tam;
                    aux2 = p[aux2];
                    if (aux2 == aux) break;
                }
            }

            uf.unite(i, u);
            p[i] = u;
            tree[i].pb(u);
            tree[u].pb(i);
        }

        memset(visited, 0, sizeof visited);

        FOR(i, 0, n) {
            if (pciclo[i] != -1 && !visited[i])
                getArbol(i, 0);
        }

        FOR(i, 0, n) {
            if (!visited[i])
                getArbol(i, 0);
        }

        build(n);
        int q;
        cin >> q;
        while (q--) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            if (uf.get(a) != uf.get(b)) {
                cout << -1 << ENDL;
            } else {
                pi node = LCA(a, b);

                if (node.first == node.second) {
                    cout << depth[a] - depth[node.first] + depth[b] - depth[node.first] << ENDL;
                } else {
                    int dif = abs(val[node.first] - val[node.second]);
                    cout << depth[a] + depth[b] + min(tamciclo[node.first] - dif, dif) << ENDL;
                }
            }
        }
    }

    return 0;
}