#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(), x.end();
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __                      \
  ios_base::sync_with_stdio(0); \
  cin.tie(nullptr);

struct TwoSat {
  int N;
  vector<vi> adj;
  vi values;

  TwoSat(int n = 0) : N(n), adj(2 * n) {}

  void either(int x, int y) {
    x = max(2 * x, -1 - 2 * x), y = max(2 * y, -1 - 2 * y);
    adj[x].push_back(y ^ 1), adj[y].push_back(x ^ 1);
  }
  void setValue(int x) { either(x, x); }
  void make_diff(int x, int y) {
    either(x, y);
    either(~x, ~y);
  }

  vi dfs_num, comp;
  stack<int> st;
  int time = 0;
  int tarjan(int u) {
    int x, low = dfs_num[u] = ++time;
    st.push(u);
    for (int v : adj[u])
      if (!comp[v])
        low = min(low, dfs_num[v] ?: tarjan(v));
    if (low == dfs_num[u]) do {
        x = st.top();
        st.pop();
        comp[x] = low;
        if (values[x >> 1] == -1)
          values[x >> 1] = x & 1;
      } while (x != u);
    return dfs_num[u] = low;
  }

  bool solve() {
    values.assign(N, -1), dfs_num.assign(2 * N, 0), comp.assign(2 * N, 0);
    for (int i = 0; i < 2 * N; i++)
      if (!comp[i])
        tarjan(i);
    for (int i = 0; i < N; i++)
      if (comp[2 * i] == comp[2 * i + 1])
        return 0;
    return 1;
  }
};

signed main() {
  __ int n;
  cin >> n;

  vector<tuple<int, int, int>> inv(n);

  FOR(i, 0, n) {
    string s;
    int p, r, v1, v2;
    cin >> s >> p >> r;
    v1 = s[0] - 'A' + (p == 2 ? 26 : 0);
    v2 = s[1] - 'A' + (p == 2 ? 26 : 0);
    inv[i] = {v1, v2, r};
  }

  auto isValidGame = [&](int a, int b, int c) -> bool {
    TwoSat ts(52);

    ts.setValue(~a), ts.setValue(~(a + 26));
    ts.setValue(~b), ts.setValue(~(b + 26));
    ts.setValue(~c), ts.setValue(~(c + 26));

    FOR(i, 0, 26) {
      if (i != a && i != b && i != c)
        ts.make_diff(i, i + 26);
    }

    for (auto &[v1, v2, r] : inv) {
      if (r == 0) {
        ts.setValue(~v1), ts.setValue(~v2);
        continue;
      }
      if (r == 1) {
        ts.make_diff(v1, v2);
        continue;
      }
      if (r == 2) {
        ts.setValue(v1), ts.setValue(v2);
      }
    }

    return ts.solve();
  };

  int cnt = 0;

  FOR(a, 0, 26) {
    FOR(b, a + 1, 26) {
      FOR(c, b + 1, 26) {
        cnt += isValidGame(a, b, c);
      }
    }
  }

  cout << cnt << ENDL;

  return 0;
}