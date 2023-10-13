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
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // abajo, derecha, arriba, izquierda

template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

int binario[70];
ll dp[70][70][5];

ll solve(int pos, int cant1, int cambiado) {
    if (pos < 0)
        return cant1;

    if (dp[pos][cant1][cambiado] != -1)
        return dp[pos][cant1][cambiado];

    ll ans = 0;
    if (cambiado) {
        ans = (solve(pos - 1, cant1 + 1, 1) + solve(pos - 1, cant1, 1));
    } else {
        if (binario[pos] == 1) {
            ans = solve(pos - 1, cant1 + 1, 0) + solve(pos - 1, cant1, 1);
        } else {
            ans = solve(pos - 1, cant1, 0);
        }
    }

    dp[pos][cant1][cambiado] = ans;

    return ans;
}

ll convBin(ll n) {
    int posi = 0;
    while (n != 0) {
        // binario[i] = (1 << i) & n
        binario[posi] = n % 2;
        n = n / 2;
        posi++;
    }
    memset(dp, -1, sizeof(dp));
    return solve(posi - 1, 0, 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll a, b;
    cin >> a >> b;
    ll res1 = convBin(b);
    ll res2 = convBin(a - 1);
    cout << res1 - res2 << ENDL;

    return 0;
}
