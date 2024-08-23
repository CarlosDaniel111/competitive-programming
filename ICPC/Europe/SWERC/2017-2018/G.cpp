#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

pair<ll, vi> hungarian(const vector<vi> &a) {
  if (a.empty()) return {0, {}};
  ll n = SZ(a) + 1, m = SZ(a[0]) + 1;
  vi u(n), v(m), p(m), ans(n - 1);
  FOR(i, 1, n) {
    p[0] = i;
    ll j0 = 0;  // add "dummy" worker 0
    vi dist(m, INT_MAX), pre(m, -1);
    vector<bool> done(m + 1);
    do {  // dijkstra
      done[j0] = true;
      ll i0 = p[j0], j1, delta = INT_MAX;
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

vector<pi> botellas, motos;

ll dist(ll a, ll b) {
  return abs(botellas[a].first - motos[b].first) + abs(botellas[a].second - motos[b].second);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll n, m;
  cin >> n >> m;
  botellas.resize(n);
  FOR(i, 0, n) {
    cin >> botellas[i].first >> botellas[i].second;
  }
  motos.resize(m);
  FOR(i, 0, m) {
    cin >> motos[i].first >> motos[i].second;
  }
  ll x0, y0;
  cin >> x0 >> y0;
  vector<vi> val(n, vi(m + n - 1));
  FOR(i, 0, n) {
    FOR(j, 0, m) {
      val[i][j] = (dist(i, j));
    }
  }
  FOR(i, 0, n) {
    FOR(j, m, m + n - 1) {
      val[i][j] = (abs(x0 - botellas[i].first) + abs(y0 - botellas[i].second));
    }
  }

  ll ans = 0;
  FOR(i, 0, n) {
    ans += abs(x0 - botellas[i].first) + abs(y0 - botellas[i].second);
  }

  /*FOR(i, 0, SZ(val)) {
    FOR(j, 0, SZ(val[0])) {
      cout << val[i][j] << " ";
    }
    cout << ENDL;
  }*/

  pair<ll, vi> ans2 = hungarian(val);
  // cout << ans2.first << ENDL;
  cout << ans + ans2.first << ENDL;

  return 0;
}