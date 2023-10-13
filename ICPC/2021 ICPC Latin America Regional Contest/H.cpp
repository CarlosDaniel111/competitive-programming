#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL begin(x), end(x)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define ROF(i, a, b) for (ll i = (a)-1; i >= (b); i--)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

pair<ll, vi> hungarian(const vector<vi> &a) {
    if (a.empty()) return {0, {}};
    ll n = SZ(a) + 1, m = SZ(a[0]) + 1;
    vi u(n), v(m), p(m), ans(n - 1);
    FOR(i, 1, n) {
        p[0] = i;
        ll j0 = 0;  // add "dummy" worker 0
        vi dist(m, LLONG_MAX), pre(m, -1);
        vector<bool> done(m + 1);
        do {  // dijkstra
            done[j0] = true;
            ll i0 = p[j0], j1, delta = LLONG_MAX;
            FOR(j, 1, m)
            if (!done[j]) {
                auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
                if (cur < dist[j]) dist[j] = cur, pre[j] = j0;
                if (dist[j] < delta) delta = dist[j], j1 = j;
            }
            FOR(j, 0, m) {
                if (done[j])
                    u[p[j]] += delta, v[j] -= delta;
                else
                    dist[j] -= delta;
            }
            j0 = j1;
        } while (p[j0]);
        while (j0) {  // update alternating path
            ll j1 = pre[j0];
            p[j0] = p[j1], j0 = j1;
        }
    }
    FOR(j, 1, m)
    if (p[j]) ans[p[j] - 1] = j - 1;
    return {-v[0], ans};  // min cost
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<vi> mat;
    mat.assign(n + 10, vi(n + 10, 0));
    FOR(i, 1, n + 1) {
        FOR(j, 1, n + 1) {
            cin >> mat[i][j];
        }
    }

    vector<vi> new_mat;

    if (n & 1) {
        for (ll i = 1; i <= n + 1; i += 2) {
            vi linea;
            for (ll j = 0; j <= n - 1; j += 2) {
                linea.pb(mat[j][i] + mat[i][j + 2]);
            }
            new_mat.pb(linea);
        }
    } else {
        for (ll i = 1; i <= n; i += 2) {
            vi linea;
            for (ll j = 0; j <= n - 2; j += 2) {
                linea.pb(mat[j][i] + mat[i][j + 2]);
            }
            new_mat.pb(linea);
        }
    }

    pair<ll, vi> resp = hungarian(new_mat);
    cout << resp.first << ENDL;

    return 0;
}