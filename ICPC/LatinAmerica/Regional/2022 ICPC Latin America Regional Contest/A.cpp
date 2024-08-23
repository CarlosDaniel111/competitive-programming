#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
#define ENDL '\n'
#define FOR(x, n) for (long long x = 0; x < (long long)n; x++)
#define FOR1(x, n) for (long long x = 1; x <= (long long)n; x++)
#define FORR(x, n) for (long long x = n - 1; x >= 0; x--)
#define FORR1(x, n) for (long long x = n; x >= 1; x--)
const long long INF = 1 << 28, MOD = 1e9 + 7, MAXN = 1e3 + 5;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vii;

vi graph[MAXN];
vi graphRev[MAXN];
int n;

bool visited[MAXN][3];

void DFS(int a, int numVis) {
    if (visited[a][numVis])
        return;
    visited[a][numVis] = true;
    for (int b : graphRev[a])
        DFS(b, numVis);
}

void clear() {
    FOR(i, n) {
        visited[i][0] = false;
        visited[i][1] = false;
        visited[i][2] = false;
    }
}

bool pierdeDinero(int i) {
    clear();
    DFS(i, 0);
    int a, b;
    a = graph[i][0];
    b = graph[i][1];
    visited[i][1] = true;
    visited[i][2] = true;
    DFS(a, 1);
    DFS(b, 2);
    FOR(j, n) {
        if (j == i)
            continue;
        if (visited[j][0] && visited[j][1] && visited[j][2]) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;
    FOR(i, n) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[i].push_back(a);
        graph[i].push_back(b);
        graphRev[a].push_back(i);
        graphRev[b].push_back(i);
    }

    FOR(i, n) {
        cout << (pierdeDinero(i) ? 'Y' : 'N');
    }
    cout << ENDL;

    return 0;
}
