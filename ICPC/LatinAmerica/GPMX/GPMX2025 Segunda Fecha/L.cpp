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

constexpr ll MAX = 1e5 + 5;
ll n;
string s;
bool taken[MAX];
ll sz[MAX];
ll cnt[MAX];
vi g[MAX];
ll mx;
ll ans = 0;
ll calcsz(ll u, ll f = -1) {
  sz[u] = 1;
  for (auto v : g[u])
    if (v != f && !taken[v]) sz[u] += calcsz(v, u);
  return sz[u];
}

void countFirst(ll u, ll abierto, ll p) {
  ll plus = (s[u] == '(' ? 1 : -1);
  abierto += plus;
  if (abierto < 0) return;
  if (abierto == 0) ans++;
  for (auto v : g[u]) {
    if (v != p && !taken[v]) {
      countFirst(v, abierto, u);
    }
  }
}

void countLast(ll u, ll cerrado, ll p) {
  ll plus = (s[u] == ')' ? 1 : -1);
  cerrado += plus;
  if (cerrado < 0) return;
  if (cerrado == 0) ans++;
  for (auto v : g[u]) {
    if (v != p && !taken[v]) {
      countLast(v, cerrado, u);
    }
  }
}

void marcar(ll u, ll cerrado, ll abierto, ll marca, ll p = -1) {
  if (s[u] == ')')
    cerrado++;
  else {
    if (cerrado == 0)
      abierto++;
    else
      cerrado--;
  }
  if (cerrado == 0) {
    cnt[abierto] += marca;
    mx = max(mx, abierto);
  }
  for (auto v : g[u]) {
    if (v != p && !taken[v]) {
      marcar(v, cerrado, abierto, marca, u);
    }
  }
}

void contar(ll u, ll abierto, ll cerrado, ll p = -1) {
  if (s[u] == '(')
    abierto++;
  else {
    if (abierto == 0)
      cerrado++;
    else
      abierto--;
  }
  if (abierto == 0) {
    ans += cnt[cerrado];
  }
  for (auto v : g[u]) {
    if (v != p && !taken[v]) {
      contar(v, abierto, cerrado, u);
    }
  }
}

void solve(ll u) {
  mx = 0;
  for (auto v : g[u]) {
    if (!taken[v]) {
      if (s[u] == '(') {
        countFirst(v, 1, u);
      } else {
        countLast(v, 1, u);
      }

      // Marcar
      if (s[u] == '(')
        marcar(v, 0, 1, 1, u);
      else
        marcar(v, 1, 0, 1, u);
    }
  }
  for (auto v : g[u]) {
    if (!taken[v]) {
      // Desmarcar
      if (s[u] == '(')
        marcar(v, 0, 1, -1, u);
      else
        marcar(v, 1, 0, -1, u);
      // Contar
      contar(v, 0, 0, u);

      // Desmarcar
      if (s[u] == '(')
        marcar(v, 0, 1, 1, u);
      else
        marcar(v, 1, 0, 1, u);
    }
  }
  fill(cnt, cnt + mx + 1, 0);
}

void decompose(ll u = 0, ll globalSz = -1) {
  if (globalSz == -1) globalSz = calcsz(u);
  for (auto v : g[u])
    if (!taken[v] && sz[v] * 2 >= globalSz) {
      sz[u] = 0;
      decompose(v, globalSz);
      return;
    }
  taken[u] = true;
  solve(u);
  // cout << u << " " << ans << ENDL;
  for (auto v : g[u])
    if (!taken[v]) decompose(v);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  cin >> s;
  FOR(i, 1, n) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  decompose();
  // countLast(3, 1, -1);
  cout << ans << ENDL;

  return 0;
}