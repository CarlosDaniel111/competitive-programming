#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

struct DSU {
  vector<int> e;
  void init(int n) { e = vi(n, -1); }
  int size(int x) { return -e[get(x)]; }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

struct Edge {
  int u, v, w, id;
  bool operator<(Edge other) const {
    return tie(w, id, u, v) < tie(other.w, other.id, other.u, other.v);
  }
  bool operator==(Edge other) const {
    return tie(w, id, u, v) == tie(other.w, other.id, other.u, other.v);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<Edge> edges(m);
  vector<Edge> originales(m);
  FOR(i, 0, m) {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
    edges[i].u--;
    edges[i].v--;

    edges[i].id = i + 1;
    originales[i] = edges[i];
  }
  sort(ALL(edges));
  DSU dsu;
  dsu.init(n);
  set<Edge> mst;
  FOR(i, 0, m) {
    if (dsu.join(edges[i].u, edges[i].v)) {
      mst.insert(edges[i]);
    }
  }
  set<Edge> nosirve, now;
  FOR(i, 0, n - 1) {
    if (mst.count(originales[i]))
      mst.erase(originales[i]);
    else
      nosirve.insert(originales[i]);
    now.insert(originales[i]);
  }

  int tot = SZ(nosirve);
  cout << tot << ENDL;
  FOR(i, 0, tot) {
    dsu.init(n);
    for (auto e : now) {
      if (e == *nosirve.begin()) continue;
      dsu.join(e.u, e.v);
    }
    Edge bueno;
    for (auto e : mst) {
      if (dsu.get(e.u) != dsu.get(e.v)) {
        bueno = e;
        break;
      }
    }
    cout << nosirve.begin()->id << " " << bueno.id << ENDL;
    now.erase(*nosirve.begin());
    now.insert(bueno);
    nosirve.erase(nosirve.begin());
    mst.erase(bueno);
  }

  return 0;
}