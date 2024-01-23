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

typedef long long T;
struct Poll {
  T x, y;

  // Operaciones Punto - Punto
  Poll operator+(Poll p) const { return {x + p.x, y + p.y}; }
  Poll operator-(Poll p) const { return {x - p.x, y - p.y}; }
  Poll operator*(Poll b) const { return {x * b.x - y * b.y, x * b.y + y * b.x}; }

  // Operaciones de comparacion para enteros
  bool operator<(Poll p) const { return tie(x, y) < tie(p.x, p.y); }
  bool operator==(Poll p) const { return tie(x, y) == tie(p.x, p.y); }
};

T cross(Poll v, Poll w) { return v.x * w.y - v.y * w.x; }
T cross(Poll a, Poll b, Poll c) { return cross(b - a, c - a); }
T dot(Poll v, Poll w) { return v.x * w.x + v.y * w.y; }

ll sgn(T x) {
  return (T(0) < x) - (x < T(0));
}

bool onSegment(Poll s, Poll e, Poll p) {
  return cross(p, s, e) == 0 && dot(s - p, e - p) <= 0;
}

bool segInter(Poll a, Poll b, Poll c, Poll d) {
  auto oa = cross(c, d, a), ob = cross(c, d, b),
       oc = cross(a, b, c), od = cross(a, b, d);
  if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
    return 1;
  set<Poll> s;
  if (onSegment(c, d, a)) s.insert(a);
  if (onSegment(c, d, b)) s.insert(b);
  if (onSegment(a, b, c)) s.insert(c);
  if (onSegment(a, b, d)) s.insert(d);
  return SZ(s) > 0;
}

vector<vi> g;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll w, p;
  cin >> w >> p;
  vector<Poll> pozos(w);
  FOR(i, 0, w) {
    ll x, y;
    cin >> pozos[i].x >> pozos[i].y;
  }
  vector<pair<ll, Poll>> pipas(p);
  FOR(i, 0, p) {
    cin >> pipas[i].first >> pipas[i].second.x >> pipas[i].second.y;
  }
  g.assign(p, vi());
  FOR(i, 0, p) {
    FOR(j, i + 1, p) {
      if (pozos[pipas[i].first - 1] == pozos[pipas[j].first - 1]) continue;
      if (segInter(pozos[pipas[i].first - 1], pipas[i].second, pozos[pipas[j].first - 1], pipas[j].second)) {
        g[i].pb(j);
        g[j].pb(i);
      }
    }
  }

  vector<ll> side(p, -1);
  bool is_bipartite = true;
  queue<ll> q;
  for (ll st = 0; st < p; ++st) {
    if (side[st] == -1) {
      q.push(st);
      side[st] = 0;
      while (!q.empty()) {
        ll v = q.front();
        q.pop();
        for (ll u : g[v]) {
          if (side[u] == -1) {
            side[u] = side[v] ^ 1;
            q.push(u);
          } else {
            is_bipartite &= side[u] != side[v];
          }
        }
      }
    }
  }

  cout << (is_bipartite ? "possible" : "impossible") << ENDL;

  return 0;
}