#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
#define ENDL '\n'
#define FOR(x, n) for (long long x = 0; x < (long long)n; x++)
#define FOR1(x, n) for (long long x = 1; x <= (long long)n; x++)
#define FORR(x, n) for (long long x = n - 1; x >= 0; x--)
#define FORR1(x, n) for (long long x = n; x >= 1; x--)
const long long INF = 1 << 28, MOD = 1e9 + 7, MAXN = 105;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vii;
typedef tuple<int, int, int> iii;

bool DP[MAXN][MAXN];
int mat[MAXN][MAXN];
ii coords[MAXN * MAXN];
int r, c;

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
priority_queue<iii, vector<iii>, greater<iii>> pq;

void procesar(int i, int j) {
    DP[i][j] = true;

    FOR(k, 4) {
        int x = i + dx[k], y = j + dy[k];
        if (x == -1 || x == r || y == -1 || y == c || mat[x][y] < mat[i][j])
            continue;
        pq.push({mat[x][y], x, y});
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int r, c;
    cin >> r >> c;

    FOR(i, r) {
        FOR(j, c) {
            cin >> mat[i][j];
            coords[mat[i][j] - 1] = {i, j};
            DP[i][j] = 0;
        }
    }

    int ans = 0;
    FOR(k, r * c) {
        auto [i, j] = coords[k];
        if (!DP[i][j]) {
            int localans = 1;
            procesar(i, j);
            while (!pq.empty()) {
                localans++;
                auto [valor, x, y] = pq.top();
                pq.pop();
                procesar(x, y);
            }
            ans = max(localans, ans);
        }
    }

    cout << ans << ENDL;
    return 0;
}
