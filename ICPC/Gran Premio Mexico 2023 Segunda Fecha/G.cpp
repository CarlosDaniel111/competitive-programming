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

ll sumafila[MAXN];
ll sumacolum[MAXN];
pl maxfila = {-1, -1};
pl maxcolum = {-1, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, t;
    ll res = 0;
    cin >> n >> t;
    F0R(i, t) {
        int fila, colum;
        cin >> fila >> colum;
        fila--;
        colum--;
        if (fila == colum) res++;
        res += sumacolum[fila];
        res += sumafila[colum];
        sumafila[fila]++;
        if (sumafila[fila] == maxfila.f) {
            if (sumacolum[fila] >= sumacolum[maxfila.s]) {
                maxfila = {sumafila[fila], fila};
            }
        } else if (sumafila[fila] > maxfila.f) {
            maxfila = {sumafila[fila], fila};
        }
        sumacolum[colum]++;
        if (sumacolum[colum] == maxcolum.f) {
            if (sumafila[colum] >= sumafila[maxcolum.s]) {
                maxcolum = {sumacolum[colum], colum};
            }
        } else if (sumacolum[colum] >= maxcolum.f) {
            maxcolum = {sumacolum[colum], colum};
        }
        ll additional = 0;

        additional = max(additional, maxfila.f + maxcolum.f);
        additional = max(additional, maxfila.f + sumacolum[maxfila.s] + 1);
        additional = max(additional, maxcolum.f + sumafila[maxcolum.s] + 1);

        cout << res << " " << additional << ENDL;
    }

    return 0;
}
