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
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)

#define ENDL '\n'

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int INF = 1 << 28;
const ll LLINF = 1e18;

// abajo, derecha, arriba, izquierda
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int mov[605][605][4];
bool visited[605][605] = {};

template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

int n;

void init() {
    F0R(i, 2 * n + 3) {
        F0R(j, 2 * n + 3) {
            mov[i][j][0] = 1;
            mov[i][j][1] = 1;
            mov[i][j][2] = 1;
            mov[i][j][3] = 1;
            visited[i][j] = false;
        }
    }
}

bool isValid(int x, int y) {
    return (x >= 0 && x < 2 * n && y >= 0 && y < 2 * n + 1 && !visited[x][y]);
}

void bfs(int i, int j) {
    queue<pi> q;
    visited[i][j] = true;
    q.push({i, j});
    while (!q.empty()) {
        pi s = q.front();
        q.pop();
        F0R(m, 4) {
            int xSig = s.first + dx[m];
            int ySig = s.second + dy[m];
            if (isValid(xSig, ySig)) {
                if (mov[s.first][s.second][m]) {
                    visited[xSig][ySig] = 1;
                    q.push({xSig, ySig});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    while (cin >> n) {
        init();
        F0R(i, 2 * n - 1) {
            F0R(j, n) {
                int aux = 2 * j + (i & 1);
                char opc;
                cin >> opc;
                // abajo, derecha, arriba, izquierda
                if (opc == 'H') {
                    mov[i][aux][0] = 0;
                    mov[i][aux + 1][0] = 0;
                    mov[i + 1][aux][2] = 0;
                    mov[i + 1][aux + 1][2] = 0;
                } else {
                    mov[i][aux][1] = 0;
                    mov[i][aux + 1][3] = 0;
                    mov[i + 1][aux][1] = 0;
                    mov[i + 1][aux + 1][3] = 0;
                }
            }
        }

        int res = 0;

        F0R(i, 2 * n) {
            F0R(j, 2 * n + 1) {
                if (!visited[i][j]) {
                    bfs(i, j);
                    res++;
                }
            }
        }

        cout << res - 1 << ENDL;
    }

    return 0;
}
