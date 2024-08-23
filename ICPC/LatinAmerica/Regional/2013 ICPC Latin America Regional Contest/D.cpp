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
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // abajo, derecha, arriba, izquierda

template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

vi graph[1005];
int dp[1005][1005];

bool solve(int x, int y) {
    if (x == 1) {
        return true;
    }
    if (x == y) {
        return false;
    }

    int &ans = dp[x][y];
    if (ans != -1)
        return ans;

    ans = 0;
    for (auto u : graph[y]) {
        if (solve(min(x, u), max(x, u))) {
            ans = 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int c, p;
    cin >> c >> p;
    F0R(i, p) {
        int a, b;
        cin >> a >> b;
        graph[b].pb(a);
    }

    memset(dp, -1, sizeof(dp));

    int res = 0;
    FOR(i, 2, c + 1) {
        FOR(j, i + 1, c + 1) {
            if (solve(i, j))
                res++;
        }
    }
    cout << res + c - 1 << ENDL;

    return 0;
}
