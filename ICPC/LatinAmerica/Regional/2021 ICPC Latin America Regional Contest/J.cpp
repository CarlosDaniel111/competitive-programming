#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ll((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

// AC2#

ll w, h, n;

bool esBorde(ll x, ll y) {
    if ((x == 0 || x == w) || (y == 0 || y == h))
        return true;
    return false;
}

ll aCoordenada(ll x, ll y) {
    int valor = 0;
    if (y == 0)
        return x;
    if (x == w)
        return w + y;
    if (y == h)
        return w + h + (w - x);
    if (x == 0)
        return w * 2 + h + (h - y);
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> w >> h >> n;
    vector<pi> arr;
    FOR(i, 0, n) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (!esBorde(x1, y1) || !esBorde(x2, y2))
            continue;
        ll l = aCoordenada(x1, y1);
        ll r = aCoordenada(x2, y2);

        arr.pb({l, i});
        arr.pb({r, i});
    }

    sort(ALL(arr));
    vector<bool> visited(n, false);
    stack<ll> st;
    FOR(i, 0, SZ(arr)) {
        if (!st.empty() && visited[arr[i].second]) {
            if (st.top() != arr[i].second) {
                cout << "N" << ENDL;
                return 0;
            }
            st.pop();
            visited[arr[i].second] = false;
        } else {
            visited[arr[i].second] = true;
            st.push(arr[i].second);
        }
    }
    cout << "Y" << ENDL;

    return 0;
}