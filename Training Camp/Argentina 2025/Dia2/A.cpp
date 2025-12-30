#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

template <typename T>
pair<T, vi> hungarian(const vector<vector<T>> &a) {
#define INF numeric_limits<T>::max()
  if (a.empty()) return {0, {}};
  ll n = SZ(a) + 1, m = SZ(a[0]) + 1;
  vi p(m), ans(n - 1);
  vector<T> u(n), v(m);
  FOR(i, 1, n) {
    p[0] = i;
    ll j0 = 0;  // agregar trabajador "dummy" 0
    vector<T> dist(m, INF);
    vi pre(m, -1);
    vector<bool> done(m + 1);
    do {  // dijkstra
      done[j0] = true;
      ll i0 = p[j0], j1;
      T delta = INF;
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
    while (j0) {  // actualizar camino alternativo
      ll j1 = pre[j0];
      p[j0] = p[j1], j0 = j1;
    }
  }
  FOR(j, 1, m)
  if (p[j]) ans[p[j] - 1] = j - 1;
  return {-v[0], ans};
}

void solve() {
  ll n, k;
  cin >> n >> k;
  vi a(n), b(n);
  FOR(i, 0, n) cin >> a[i] >> b[i];

  vector<vi> mat(n, vi(n, 0));
  FOR(i, 0, n) {
    FOR(j, 0, n) {
      if (j == n - 1) {
        mat[i][j] = -(a[i] + b[i] * (k - 1));
        continue;
      }
      if (j < k - 1) {
        mat[i][j] = -(a[i] + b[i] * j);
      } else {
        mat[i][j] = -(b[i] * (k - 1));
      }
    }
  }
  pair<ll, vi> ans = hungarian<ll>(mat);
  vi order(n);
  iota(ALL(order), 0);
  sort(ALL(order), [&](ll i, ll j) { return ans.second[i] < ans.second[j]; });

  if (k == 1) {
    cout << 1 << ENDL;
    cout << order[n - 1] + 1 << ENDL;
    return;
  }
  vi res;
  FOR(i, 0, n) {
    res.pb(order[i] + 1);
    if (i >= k - 1 && i != n - 1) {
      res.pb(-(order[i] + 1));
    }
  }
  cout << SZ(res) << ENDL;
  for (auto x : res) cout << x << " ";
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t;
  cin >> t;
  while (t--) solve();

  return 0;
}