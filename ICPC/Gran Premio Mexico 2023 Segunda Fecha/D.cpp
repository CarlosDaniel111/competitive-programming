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

int arr1[MAXN], arr2[MAXN];
int ans = 0;

void buildPi(vi &p, vi &pi) {
    pi = vi(p.size());
    int k = -2;
    for (int i = 0; i < p.size(); i++) {
        while (k >= -1 && p[k + 1] != p[i]) k = (k == -1) ? -2 : pi[k];
        pi[i] = ++k;
    }
}

void KMP(vi &t, vi &p) {
    vi pi;
    buildPi(p, pi);
    int k = -1;
    for (int i = 0; i < t.size(); i++) {
        while (k >= -1 && p[k + 1] != t[i]) k = (k == -1) ? -2 : pi[k];
        k++;
        if (k == p.size() - 1) {
            // p matches t[i-m+1, ..., i]
            ans++;
            k = (k == -1) ? -2 : pi[k];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vi diff1;
    vi diff2;
    F0R(i, n) {
        cin >> arr1[i];
        if (i == 0) continue;
        diff1.pb(arr1[i] - arr1[i - 1]);
    }

    F0R(i, m) {
        cin >> arr2[i];
        if (i == 0) continue;
        diff2.pb(arr2[i] - arr2[i - 1]);
    }

    if (n == 1) {
        cout << m << ENDL;
        return 0;
    }

    KMP(diff2, diff1);
    cout << ans << ENDL;

    return 0;
}
