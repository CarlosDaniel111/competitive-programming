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

ll type[MAXN];
ll a[MAXN];
ll n, k;
ll dp[MAXN][105];

ll solve(ll l, ll r, ll p, ll c, ll t) {
    if (t == n || t == k) {
        return c;
    }
    l = (l == -1 ? n - 1 : l);
    r = (r == n ? 0 : r);
    ll &ans = dp[l][t];
    if (ans != -1) return ans;

    ll left = 0, right = 0;
    if (type[l] == 1) {
        left = solve(l - 1, r, p + a[l], c, t + 1);
    } else {
        if (a[l] <= p) {
            left = solve(l - 1, r, p - a[l], c + a[l], t + 1);
        }
    }

    if (type[r] == 1) {
        right = solve(l, r + 1, p + a[r], c, t + 1);
    } else {
        if (a[r] <= p) {
            right = solve(l, r + 1, p - a[r], c + a[r], t + 1);
        }
    }

    return ans = max({c, left, right});
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));

    cin >> n >> k;
    F0R(i, n) { cin >> a[i]; }
    F0R(i, n) { cin >> type[i]; }

    ll ans = 0;
    F0R(i, n) { ans = max(ans, solve(i, (i + 1) % n, 0, 0, 0)); }

    cout << ans << ENDL;

    return 0;
}