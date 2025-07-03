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

struct node {
  ll x, y, type;
};
const ll INF = 1e9;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, h, k;
  cin >> n >> h >> k;
  vector<node> a(n);
  FOR(i, 0, n) { cin >> a[i].x >> a[i].y >> a[i].type; }
  ll x0, y0;
  cin >> x0 >> y0;
  ll start = -1;
  FOR(i, 0, n) {
    if (a[i].x == x0 && a[i].y == y0) {
      start = i;
      break;
    }
  }
  auto d = [&](ll u, ll v) -> ll {
    ll x1 = a[u].x, x2 = a[v].x, y1 = a[u].y, y2 = a[v].y;
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
  };
  queue<ll> q;
  q.push(start);
  vi dist(n, INF);
  dist[start] = 0;
  while (SZ(q)) {
    ll u = q.front();
    q.pop();

    FOR(v, 0, n) {
      if (v == u) continue;
      if ((a[v].type && d(u, v) <= k * k) or (a[u].type && d(u, v) <= h * h)) {
        if (dist[v] > dist[u] + 1) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
  }
  ll ans = INF;
  FOR(i, 0, n) {
    if (a[i].y == 0) ans = min(ans, dist[i]);
    if (a[i].type == 1 && -a[i].y <= h) {
      ans = min(ans, dist[i] + 1);
    }
  }
  if (ans == INF) ans = -1;
  cout << ans << ENDL;

  return 0;
}