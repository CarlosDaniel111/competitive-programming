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
const int INF = 1e7;
const ll LLINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // abajo, derecha, arriba, izquierda

template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

/*Esta implementado para obtener la suma en un rango, pero es posible usar cualquier
operacion conmutativa como la multiplicacion, XOR, AND, OR, MIN, MAX, etc.*/

class SegmentTree {
  private:
    int n;
    vi arr, st;

    int l(int p) { return p << 1; }       // ir al hijo izquierdo
    int r(int p) { return (p << 1) + 1; } // ir al hijo derecho

    void build(int index, int start, int end) {
        if (start == end) {
            st[index] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(l(index), start, mid);
            build(r(index), mid + 1, end);
            st[index] = min(st[l(index)], st[r(index)]);
        }
    }

    int query(int index, int start, int end, int i, int j) {
        if (j < start || end < i)
            return INF; // Si ese rango no nos sirve, retornar un valor que no cambie nada

        if (i <= start && end <= j)
            return st[index];

        int mid = (start + end) / 2;
        int q1 = query(l(index), start, mid, i, j);
        int q2 = query(r(index), mid + 1, end, i, j);

        return min(q1, q2);
    }

    void update(int index, int start, int end, int idx, int val) {
        if (start == end) {
            st[index] = val;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid)
                update(l(index), start, mid, idx, val);
            else
                update(r(index), mid + 1, end, idx, val);

            st[index] = min(st[l(index)], st[r(index)]);
        }
    }

  public:
    SegmentTree(int sz) : n(sz), st(4 * n) {} // Constructor de st sin valores

    SegmentTree(const vi &initialArr) : SegmentTree((int)initialArr.size()) { // Constructor de st con arreglo inicial
        arr = initialArr;
        build(1, 0, n - 1);
    }

    void update(int i, int val) { update(1, 0, n - 1, i, val); }

    int query(int i, int j) { return query(1, 0, n - 1, i, j); }
};

pi pmm[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi alturas(n + 2);
    alturas[0] = INF;
    alturas[n + 1] = INF;
    FOR(i, 1, n + 1) {
        cin >> alturas[i];
    }
    SegmentTree st(alturas);
    vi picos(n + 1);
    int lenPicos = 1;
    picos[0] = 0;
    FOR(i, 1, n + 1) {
        if (alturas[i - 1] < alturas[i] && alturas[i + 1] < alturas[i]) {
            picos[lenPicos] = i;
            lenPicos++;
        }
    }
    picos[lenPicos] = n + 1;
    lenPicos++;

    stack<int> pila;
    pila.push(0);
    FOR(i, 1, lenPicos - 1) {
        while (alturas[picos[pila.top()]] <= alturas[picos[i]]) {
            pila.pop();
        }
        pmm[i].first = pila.top();
        pila.push(i);
    }

    stack<int> pila2;
    pila2.push(lenPicos - 1);

    ROF(i, lenPicos - 1, 1) {
        while (alturas[picos[pila2.top()]] <= alturas[picos[i]]) {
            pila2.pop();
        }
        pmm[i].second = pila2.top();
        pila2.push(i);
    }

    /*F0R(i, lenPicos) {
        cout << "PICO " << picos[i] << ENDL;
        cout << picos[pmm[i].first] << " " << picos[pmm[i].second] << ENDL;
    }
    cout << ENDL;*/

    FOR(i, 1, lenPicos - 1) {
        int aux1 = st.query(picos[pmm[i].first], picos[i]);
        int aux2 = st.query(picos[i], picos[pmm[i].second]);
        // cout << aux1 << " " << aux2 << ENDL;
        if (alturas[picos[i]] - aux1 >= 150000 && alturas[picos[i]] - aux2 >= 150000) {
            cout << picos[i] << " ";
        }
    }

    return 0;
}
