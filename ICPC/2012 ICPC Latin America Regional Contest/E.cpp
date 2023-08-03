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

double p1[10], q1[10], p2[10], q2[10];
int K;

double f(double x, double m) {
    double num1 = 0, den1 = 0, num2 = 0, den2 = 0;

    for (int i = K; i >= 0; i--) {
        num1 = num1 * x + p1[i];
        den1 = den1 * x + q1[i];
        num2 = num2 * x + p2[i];
        den2 = den2 * x + q2[i];
    }

    double upper_layer = num1 / den1;
    double bottom_layer = num2 / den2;

    if (m > upper_layer) return 0;
    if (m > bottom_layer) return upper_layer - m;
    return upper_layer - bottom_layer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    double W, D, A;

    while (cin >> W >> D >> A >> K) {
        F0R(i, K + 1)
            cin >> p1[i];
        F0R(i, K + 1)
            cin >> q1[i];
        F0R(i, K + 1)
            cin >> p2[i];
        F0R(i, K + 1)
            cin >> q2[i];

        double low = -D;
        double high = 0;

        F0R(k, 22) {
            double m = (low + high) / 2;
            double h = W / 10000;
            double s = f(0, m) + f(W, m);
            for (int i = 1; i < 10000; ++i) {
                double x = double(h * i);
                s += f(x, m) * ((i & 1) ? 4 : 2);
            }
            s *= h / 3;

            if (s < A)
                high = m;
            else
                low = m;
        }
        printf("%.5f\n", -low);
    }

    return 0;
}