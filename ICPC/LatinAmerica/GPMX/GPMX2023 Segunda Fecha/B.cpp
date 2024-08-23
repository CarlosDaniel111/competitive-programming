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
const int MAXN = 1e6 + 5;
const int INF = 1 << 28;
const ll LLINF = 1e18;
const int dx[4] = {1, 0, -1, 0},
          dy[4] = {0, 1, 0, -1};  // abajo, derecha, arriba, izquierda

template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

ll fastpow(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
    while (b) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

int modInverse(int b, int m = MOD) { return fastpow(b, m - 2, m) % m; }

int arr[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    ll numerador = 1;
    FOR(i, 2, n + 1) { numerador = numerador * i % MOD; }
    ll denominador = 1;
    unordered_map<int, int> mapa;
    F0R(i, n) {
        cin >> arr[i];
        mapa[arr[i]]++;
        denominador = (denominador * mapa[arr[i]]) % MOD;
    }
    ll aux = numerador * modInverse(denominador) % MOD;
    cout << modInverse(aux) << ENDL;

    F0R(i, k) {
        int x, y;
        cin >> x >> y;
        x--;
        denominador = denominador * modInverse(mapa[arr[x]]) % MOD;
        mapa[arr[x]]--;
        arr[x] = y;
        mapa[arr[x]]++;
        denominador = (denominador * mapa[arr[x]]) % MOD;
        aux = numerador * modInverse(denominador) % MOD;
        cout << modInverse(aux) << ENDL;
    }

    return 0;
}
