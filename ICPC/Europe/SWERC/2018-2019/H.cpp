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

constexpr ll INF = 3e15;
constexpr ll MAXN = 2e5 + 5;

struct node {
  ll a, b, c;
  bool operator<(node otro) const { return tie(a, b, c) < tie(otro.a, otro.b, otro.c); }
  bool operator==(node otro) const { return tie(a, b, c) == tie(otro.a, otro.b, otro.c); }
};

vector<pi> graph[MAXN];
ll n, m;
vi dist;

// O(V + E log V)
void dijkstra(ll x) {
  dist.assign(n, INF);
  dist[x] = 0;

  priority_queue<pi> pq;
  pq.emplace(0, x);
  while (!pq.empty()) {
    auto [du, u] = pq.top();
    du *= -1;
    pq.pop();

    if (du > dist[u])
      continue;

    for (auto &[v, dv] : graph[u]) {
      if (du + dv < dist[v]) {
        dist[v] = du + dv;
        pq.emplace(-dist[v], v);
      }
    }
  }
}

vi bit;

ll query(ll i) {
  i++;
  ll res = INF;
  while (i) {
    res = min(bit[i], res);
    i -= i & (-i);
  }
  return res;
}

void update(ll i, ll val) {
  i++;
  while (i < SZ(bit)) {
    bit[i] = min(bit[i], val);
    i += i & (-i);
  }
}

vector<node> distances;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n >> m;
  FOR(i, 0, m) {
    ll u, v, w;
    cin >> u >> v >> w;
    graph[u].pb({v, w});
    graph[v].pb({u, w});
  }

  distances.resize(n);

  dijkstra(0);
  FOR(i, 0, n)
  distances[i].a = dist[i];

  dijkstra(1);
  FOR(i, 0, n)
  distances[i].b = dist[i];

  dijkstra(2);
  FOR(i, 0, n)
  distances[i].c = dist[i];

  sort(ALL(distances));
  vector<ll> aux;
  FOR(i, 0, n) {
    aux.pb(distances[i].b);
  }
  sort(ALL(aux));
  unique(ALL(aux));
  bit.assign(n, INF);
  vi inutil(n, 0);
  ll inutiles = 0;
  FOR(i, 0, n) {
    if (i != 0 && distances[i] == distances[i - 1]) {
      inutil[i] = inutil[i - 1];
      inutiles += inutil[i];
      continue;
    }
    ll pos = lower_bound(ALL(aux), distances[i].b) - aux.begin();
    ll minC = query(pos);
    if (minC <= distances[i].c)
      inutil[i] = 1, inutiles++;
    else
      update(pos, distances[i].c);
  }

  cout << n - inutiles << ENDL;

  return 0;
}