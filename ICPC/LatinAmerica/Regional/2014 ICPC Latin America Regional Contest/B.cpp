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

ll a, b;
ll dp[5005][5005];
string linea;

ll solve(int izq, int der) {
    if (izq >= der)
        return 0;

    if (linea[izq] == 'B')
        return solve(izq + 1, der);
    if (linea[der] == 'W')
        return solve(izq, der - 1);

    ll &ans = dp[izq][der];
    if (ans != -1)
        return ans;

    ll opc1 = a + solve(izq + 1, der - 1);
    ll opc2 = 0;
    ll cont = 0;
    FOR(i, izq, der + 1) {
        while (i <= der && linea[i] == 'W') {
            i++;
            cont++;
        }
        opc2 += cont * (a - b);
    }

    return ans = min(opc1, opc2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> a >> b;
    cin >> linea;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, linea.size() - 1) << ENDL;
    return 0;
}
