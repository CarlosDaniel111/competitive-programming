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

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;

  if (s[0] == 'E') {
    map<string, int> mp;
    auto getID = [&](string &s) -> int {
      if (mp.count(s)) return mp[s];
      return mp[s] = SZ(mp);
    };
    vector<vi> g(605, vi());
    int u;
    while (cin >> s) {
      if (s.back() == ':') {
        s.erase(--s.end());
        u = getID(s);
      } else {
        int v = getID(s);
        g[u].pb(v);
      }
    }
    vector<string> names(SZ(mp));
    for (auto &[name, id] : mp) {
      names[id] = name;
    }
    string b = "";
    auto dfs = [&](auto self, int u) -> void {
      cout << names[u] << ENDL;
      b += '0';
      for (auto v : g[u]) {
        self(self, v);
      }
      b += '1';
    };
    dfs(dfs, 0);
    cout << b << ENDL;
  } else {
    vector<string> names;
    while (cin >> s) {
      if (s[0] == 0 or s[0] == 1) continue;
      names.pb(s);
    }
    vector<vi> g(605);
    int curr = 0;
    stack<int> st;

    for (auto c : s) {
      if (c == '0') {
        if (SZ(st)) {
          g[st.top()].pb(++curr);
        }
        st.push(curr);
      } else {
        st.pop();
      }
    }

    FOR(u, 0, 605) {
      if (SZ(g[u])) {
        cout << names[u] << ": ";
        for (auto v : g[u]) {
          cout << names[v] << " ";
        }
        cout << ENDL;
      }
    }
  }

  return 0;
}