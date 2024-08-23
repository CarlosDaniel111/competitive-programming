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

const int MOD = 998244353;
const int MAXN = 5 * 1e3 + 5;
const int INF = 1 << 28;
const ll LLINF = 1e18;
const int dx[4] = {1, 0, -1, 0},
          dy[4] = {0, 1, 0, -1};  // abajo, derecha, arriba, izquierda

template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

ll dp[MAXN];
int arr[MAXN];
int arrmin[MAXN];
int n;
ll f(int x) {
    if (x == (n - 1)) return 1;

    ll &ans = dp[x];
    if (ans != -1) return ans;

    ans = (arr[x] == arrmin[x]);
    int minimo = INF;
    FOR(i, x + 1, n) {
        if (min(arr[x], arr[i]) <= minimo) {
            ans += f(i);
            ans %= MOD;
        }
        minimo = min(minimo, arr[i]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));
    cin >> n;
    F0R(i, n) { cin >> arr[i]; }
    arrmin[n - 1] = arr[n - 1];
    R0F(i, n - 1) { arrmin[i] = min(arrmin[i + 1], arr[i]); }

    ll res = 0;
    int minimo = INF;
    F0R(i, n) {
        minimo = min(minimo, arr[i]);
        if (arr[i] == minimo) {
            res += f(i);
            res %= MOD;
        }
    }
    cout << res << ENDL;

    return 0;
}
