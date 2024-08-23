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

int arr[MAXN];
vl tree[MAXN];
vl euler;

class LazySegmentTree {
   private:
    int n;
    vl A, lazy;
    vpl st;

    int l(int p) { return (p << 1) + 1; }  // ir al hijo izquierdo
    int r(int p) { return (p << 1) + 2; }  // ir al hijo derecho

    void build(int index, int start, int end) {
        if (start == end) {
            st[index].first = arr[A[start]];
            st[index].second = A[start];
        } else {
            int mid = (start + end) / 2;
            build(l(index), start, mid);
            build(r(index), mid + 1, end);
            if (st[l(index)].first >= st[r(index)].first) {
                st[index] = st[l(index)];
            } else {
                st[index] = st[r(index)];
            }
        }
    }

    void propagate(int index, int start, int end) {
        if (lazy[index] != 0) {
            st[index].first += lazy[index];
            if (start != end) {
                lazy[l(index)] += lazy[index];
                lazy[r(index)] += lazy[index];
            }
            lazy[index] = 0;
        }
    }

    void update(int index, int start, int end, int i, int j, ll val) {
        propagate(index, start, end);
        if ((end < i) || (start > j)) return;

        if (start >= i && end <= j) {
            st[index].first += val;
            if (start != end) {
                lazy[l(index)] += val;
                lazy[r(index)] += val;
            }
            return;
        }
        int mid = (start + end) / 2;

        update(l(index), start, mid, i, j, val);
        update(r(index), mid + 1, end, i, j, val);

        if (st[l(index)].first >= st[r(index)].first) {
            st[index] = st[l(index)];
        } else {
            st[index] = st[r(index)];
        }
    }

    pl query(int index, int start, int end, int i, int j) {
        propagate(index, start, end);
        if (end < i || start > j) return {-LLINF, 0};
        if ((i <= start) && (end <= j)) return st[index];

        int mid = (start + end) / 2;

        pl par1 = query(l(index), start, mid, i, j);
        pl par2 = query(r(index), mid + 1, end, i, j);

        if (par1.first >= par2.first) {
            return par1;
        } else {
            return par2;
        }
    }

   public:
    LazySegmentTree(int sz)
        : n(sz), st(4 * n), lazy(4 * n) {}  // Constructor de st sin valores

    LazySegmentTree(const vl &initialA)
        : LazySegmentTree(
              (int)initialA.size()) {  // Constructor de st con arreglo inicial
        A = initialA;
        build(0, 0, n - 1);
    }

    void update(int i, int j, ll val) { update(0, 0, n - 1, i, j, val); }

    pl query(int i, int j) { return query(0, 0, n - 1, i, j); }
};

int eulerTour(int u) {
    euler.pb(u);
    if (tree[u].size() == 0) return u;

    for (auto v : tree[u]) {
        int temp = eulerTour(v);
        euler.pb(temp);
    }
    return u;
}

int res[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    FOR(i, 1, n + 1) {
        cin >> arr[i];
        arr[i] *= -1;
    }
    F0R(i, n - 1) {
        int x, y;
        cin >> x >> y;
        tree[x].pb(y);
    }

    int temp = eulerTour(1);
    euler.pb(temp);
    vpi p;  // Guardar la entrada y salida de cada nodo
    F0R(i, n + 1) { p.pb({0, 0}); }

    F0R(i, euler.size()) {
        if (p[euler[i]].first == 0)
            p[euler[i]].first = i + 1;
        else
            p[euler[i]].second = i + 1;
    }

    LazySegmentTree lst(euler);

    memset(res, -1, sizeof(res));
    F0R(i, q) {
        int x, b;
        cin >> x >> b;
        int dist = (p[x].second - (p[x].first - 1)) / 2;
        int bono = b / dist;
        lst.update(p[x].first - 1, p[x].second - 1, bono);

        if (b % dist != 0) {
            lst.update(p[x].first - 1, p[x].first - 1, b % dist);
            lst.update(p[x].second - 1, p[x].second - 1, b % dist);
        }

        bool sigue = true;
        while (sigue) {
            pl par = lst.query(p[x].first - 1, p[x].second - 1);
            if (par.first >= 0) {
                res[par.second] = i + 1;
                lst.update(p[par.second].first - 1, p[par.second].first - 1,
                           -LLINF);
                lst.update(p[par.second].second - 1, p[par.second].second - 1,
                           -LLINF);
            } else {
                sigue = false;
            }
        }
    }

    F0R(i, n) { cout << res[i + 1] << ENDL; }

    return 0;
}
