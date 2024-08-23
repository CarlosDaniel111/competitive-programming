#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
#define __                      \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);

signed main() {
  __

      int n;
  cin >> n;
  vi input(n * 2);
  vi entrada(n + 1);
  vi salida(n + 1);
  FOR(i, 0, n * 2) {
    string s;
    cin >> s;
    int num = stoi(s.substr(1));
    if (s[0] == '+') {
      entrada[num] = i;
      input[i] = num;
    } else {
      salida[num] = i;
      input[i] = -num;
    }
  }

  vector<vi> g(n, vi());
  FOR(i, 0, 2 * n) {
    if (input[i] > 0) {
      FOR(j, i + 1, salida[input[i]]) {
        if (input[j] < 0) continue;
        if (salida[input[j]] > salida[input[i]]) {
          g[input[i] - 1].pb(input[j] - 1);
          g[input[j] - 1].pb(input[i] - 1);
          // cout << input[i] << " " << input[j] << ENDL;
        }
      }
    }
  }

  vector<int> color(n, -1);

  auto dfs = [&](auto self, int u) -> bool {
    for (auto &v : g[u]) {
      if (color[v] == color[u]) return false;
      if (color[v] != -1) continue;
      color[v] = color[u] ^ 1;
      if (!self(self, v)) return false;
    }
    return true;
  };

  FOR(i, 0, n) {
    if (color[i] != -1) continue;
    color[i] = 0;
    if (!dfs(dfs, i)) {
      cout << "*" << ENDL;
      return 0;
    }
  }

  for (auto &c : color) {
    cout << (c ? "S" : "G");
  }
  cout << ENDL;

  return 0;
}