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
const int MAXN = 2505;
const int INF = 1 << 28;
const ll LLINF = 1e18;
const int dx[4] = {1, 0, -1, 0},
          dy[4] = {0, 1, 0, -1};  // abajo, derecha, arriba, izquierda

template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

int n, m;
char grid[55][55];
int val[55][55];
vi graph[MAXN];

int dist[MAXN], pairU[MAXN], pairV[MAXN], c1, c2;

bool bfs() {
    queue<int> q;

    for (int u = 1; u <= c1; u++) {
        if (!pairU[u]) {
            dist[u] = 0;
            q.push(u);
        } else
            dist[u] = INF;
    }

    dist[0] = INF;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (dist[u] < dist[0]) {
            for (int v : graph[u]) {
                if (dist[pairV[v]] == INF) {
                    dist[pairV[v]] = dist[u] + 1;
                    q.push(pairV[v]);
                }
            }
        }
    }

    return dist[0] != INF;
}

bool dfs(int u) {
    if (u) {
        for (int v : graph[u]) {
            if (dist[pairV[v]] == dist[u] + 1) {
                if (dfs(pairV[v])) {
                    pairU[u] = v;
                    pairV[v] = u;
                    return true;
                }
            }
        }

        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroftKarp() {
    int result = 0;

    while (bfs())
        for (int u = 1; u <= c1; u++)
            if (!pairU[u] && dfs(u)) result++;
    memset(pairU, 0, sizeof pairU);
    memset(pairV, 0, sizeof pairV);

    return result;
}

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.');
}

void createGraph(int x, int y, bool p) {
    val[x][y] = (p) ? ++c1 : ++c2;
    F0R(k, 4) {
        if (isValid(x + dx[k], y + dy[k])) {
            if (val[x + dx[k]][y + dy[k]] == -1)
                createGraph(x + dx[k], y + dy[k], !p);
            if (p) {
                graph[val[x][y]].pb(val[x + dx[k]][y + dy[k]]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    while (cin >> n >> m) {
        F0R(i, n) {
            F0R(j, m) {
                cin >> grid[i][j];
                val[i][j] = -1;
            }
        }

        F0R(i, MAXN)
        graph[i].clear();

        c1 = c2 = 0;
        F0R(i, n) {
            F0R(j, m) {
                if (grid[i][j] == '.' && val[i][j] == -1) {
                    createGraph(i, j, 0);
                }
            }
        }

        int ans = (c1 + c2) - 2 * hopcroftKarp();
        cout << (ans == 0 ? 2 : 1) << ENDL;
    }

    return 0;
}