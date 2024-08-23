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

int dp[55][505][505];
int A, B, C, n;
int maximo = 0;
int arr[55];

int solve(int pos, int a, int b) {
    if (pos == n) {
        int o1 = ceil((float)a / (float)A);
        int o2 = ceil((float)b / (float)B);
        int o3 = ceil((float)(maximo - a - b) / (float)C);
        return max({o1, o2, o3});
    }
    int &ans = dp[pos][a][b];
    if (ans != -1) {
        return dp[pos][a][b];
    }
    int opc1 = solve(pos + 1, a + arr[pos], b);
    int opc2 = solve(pos + 1, a, b + arr[pos]);
    int opc3 = solve(pos + 1, a, b);
    ans = min({opc1, opc2, opc3});
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));
    cin >> n >> A >> B >> C;
    F0R(i, n) {
        cin >> arr[i];
        maximo += arr[i];
    }
    cout << solve(0, 0, 0) << ENDL;

    return 0;
}
