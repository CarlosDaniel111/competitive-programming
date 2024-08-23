#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

struct Node {
    ll B, F, D;
} a[MAXN];
bool cmp(Node a, Node b) {
    return a.B == b.B ? a.F < b.F : a.B < b.B;
}

ll bit[MAXN];  // Utilizar a partir del 1
ll n, m;
ll t[MAXN];
ll f[MAXN];

ll query(ll index) {
    ll sum = 0;
    while (index > 0) {
        sum = max(bit[index], sum);
        index -= index & (-index);
    }
    return sum;
}

void add(ll index, ll val) {
    while (index <= m) {
        bit[index] = max(val, bit[index]);
        index += index & (-index);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;
    FOR(i, 1, n + 1) {
        cin >> a[i].B >> a[i].F >> a[i].D;
        t[i] = a[i].F;
    }
    sort(t + 1, t + n + 1);
    m = unique(t + 1, t + n + 1) - t - 1;
    sort(a + 1, a + n + 1, cmp);

    FOR(i, 1, n + 1) {
        a[i].F = lower_bound(t + 1, t + m + 1, a[i].F) - t;
    }

    ll last = 1;
    ll ans = 0;
    FOR(i, 1, n + 1) {
        if (a[i].B == a[i + 1].B && a[i].F == a[i + 1].F) {
            a[i + 1].D += a[i].D;
            continue;
        }

        if (a[i].B != a[last].B) {
            while (last < i) {
                add(a[last].F, f[last]);
                last++;
            }
        }
        f[i] = a[i].D + query(a[i].F - 1);
        // cout << query(a[i].F - 1) << ENDL;
        ans = max(ans, f[i]);
    }
    cout << ans << ENDL;

    return 0;
}