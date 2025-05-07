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

template<typename T>
struct Dinic {
  #define INF numeric_limits<T>::max()
  struct Edge {
    ll to, rev;
    T c, oc;
    T flow() { return max(oc - c, T(0)); }  // if you need flows
  };
  vi lvl, ptr, q;
  vector<vector<Edge>> adj;
  Dinic(ll n) : lvl(n), ptr(n), q(n), adj(n) {}
  void addEdge(ll a, ll b, T c, T rcap = 0) {
    adj[a].push_back({b, SZ(adj[b]), c, c});
    adj[b].push_back({a, SZ(adj[a]) - 1, rcap, rcap});
  }
  T dfs(ll v, ll t, T f) {
    if (v == t || !f) return f;
    for (ll& i = ptr[v]; i < SZ(adj[v]); i++) {
      Edge& e = adj[v][i];
      if (lvl[e.to] == lvl[v] + 1) if (T p = dfs(e.to, t, min(f, e.c))) {
        e.c -= p, adj[e.to][e.rev].c += p;
        return p;
      }
    }
    return 0;
  }
  T calc(ll s, ll t) {
    T flow = 0;
    q[0] = s;
    FOR(L, 0, 31) do {  // 'll L=30' maybe faster for random data
      lvl = ptr = vi(SZ(q));
      ll qi = 0, qe = lvl[s] = 1;
      while (qi < qe && !lvl[t]) {
        ll v = q[qi++];
        for (Edge e : adj[v]) if (!lvl[e.to] && e.c >> (30 - L)) q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
      }
      while (T p = dfs(s, t, INF)) flow += p;
    }
    while (lvl[t]);
    return flow;
  }
  bool leftOfMinCut(ll a) { return lvl[a] != 0; }
};


signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n,m;
  cin >> n >> m;
  vi a(n);
  FOR(i,0,n) cin >> a[i];
  vector<vi> g(n);
  FOR(i,0,m){
    ll u,v;
    cin >> u >> v;
    u--,v--;
    g[v].pb(u);
  }

  vi vis(n,0);
  ll orig;
  const ll S = n,T=n+1,INF2 = 1e15;
  Dinic<ll> mf(n+2);
  auto dfs = [&](auto self,ll u) -> void {
    vis[u] = 1;
    for(auto v:g[u]){
      if(vis[v]) continue;
      if(a[v]<=0){
        mf.addEdge(orig,v,INF2);
      } 
      self(self,v);
    }
  };
  
  ll pos = 0;
  FOR(i,0,n){
    if(a[i] > 0){
      pos+=a[i];
      mf.addEdge(S,i,a[i]);
      vis.assign(n,0);
      orig = i;
      dfs(dfs,i);
    }else{
      mf.addEdge(i,T,abs(a[i]));    }
  }
  ll tot = mf.calc(S,T);
  cout << pos - tot << ENDL;


  return 0;
}