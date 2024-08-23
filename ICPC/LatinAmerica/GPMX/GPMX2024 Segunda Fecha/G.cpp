#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define ALL(x) (x.begin(), x.end())
#define SZ(x) ((int)x.size())
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; i++)
#define ENDL '\n'

#define MAX 1000005
vi g[MAX];
ll st_sz[MAX];

void dfs_sz(int u, int p) {
  st_sz[u] = 1;
  for (auto &v : g[u]) {
    if (v != p) {
      dfs_sz(v, u);
      st_sz[u] += st_sz[v];
    }
  }
}

pair<ll, int> dfs_ans(int u, int p) {
  pair<ll, int> ans = {-1, 0};
  for (auto &v : g[u]) {
    if (v != p) {
      auto [x, cnt] = dfs_ans(v, u);

      ll outside = st_sz[0] - st_sz[v];
      ll inside = st_sz[v];
      ll val = outside * inside;

      pair<ll, int> aux = {val, 1};
      if (val == x) {
        aux.second += cnt;
      } else if (x > val) {
        aux = {x, cnt};
      }

      if (aux.first == ans.first) {
        ans.second += aux.second;
      } else if (aux.first > ans.first) {
        ans = aux;
      }
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;
  FOR(i, 1, n) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v), g[v].pb(u);
  }

  dfs_sz(0, -1);

  auto [u, cnt] = dfs_ans(0, -1);
  cout << u << ' ' << cnt << ENDL;
}