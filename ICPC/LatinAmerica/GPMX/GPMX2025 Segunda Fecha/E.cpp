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

void solve() {
  int n;
  cin >> n;
  vector<string> a(n);
  multimap<string, int> mp[10][2];
  vector<multimap<string, int>::iterator> its(n);
  vi pos(10, -1);
  FOR(i, 0, n) {
    cin >> a[i];
    pos[SZ(a[i])] = i;
    its[i] = mp[SZ(a[i])][0].insert({a[i], i});
  }
  vector<string> b(n);
  vector<vector<pair<string, int>>> posb(10);
  FOR(i, 0, n) {
    cin >> b[i];
    posb[SZ(b[i])].pb({b[i], i});
  }
  FOR(i, 0, n) {
    if (SZ(a[i]) < SZ(b[i]) or pos[SZ(b[i])] == -1) {
      cout << -1 << ENDL;
      return;
    }
  }
  vector<pi> ans;
  for (int i = 9; i >= 1; i--) {
    vector<pair<string, int>> quedan;
    for (auto [num, to] : posb[i]) {
      auto it = mp[i][1].find(num);
      if (it == mp[i][1].end()) {
        quedan.pb({num, to});
        continue;
      }
      int from = it->second;
      // change
      auto it2 = its[pos[i]];
      swap(it2->second, it->second);
      ans.pb({from, pos[i]});
      swap(its[pos[i]], its[from]);
      swap(pos[i], from);

      if (from == to) {
        mp[i][1].erase(it);
        continue;
      }

      for (int k = i; k >= 1; k--) {
        if (pos[k] == from) {
          pos[k] = to;
        } else if (pos[k] == to) {
          pos[k] = from;
        }
      }

      it2 = its[to];
      swap(it2->second, it->second);
      swap(its[from], its[to]);
      ans.pb({from, to});
      mp[i][1].erase(it);
    }
    for (auto [num, to] : quedan) {
      auto it = mp[i][0].find(num);
      if (it == mp[i][0].end()) {
        cout << -1 << ENDL;
        return;
      }
      int from = it->second;
      if (from == to) {
        mp[i][0].erase(it);
        continue;
      }
      for (int k = i; k >= 1; k--) {
        if (pos[k] == from) {
          pos[k] = to;
        } else if (pos[k] == to) {
          pos[k] = from;
        }
      }

      auto it2 = its[to];
      swap(it2->second, it->second);
      swap(its[from], its[to]);
      ans.pb({from, to});
      mp[i][0].erase(it);
    }

    for (auto [num, p] : mp[i][0]) {
      its[p] = mp[i - 1][1].insert({num.substr(1, SZ(num) - 1), p});
    }
    for (auto [num, p] : mp[i][1]) {
      its[p] = mp[i - 1][1].insert({num.substr(1, SZ(num) - 1), p});
    }
  }

  cout << SZ(ans) << ENDL;
  for (auto [x, y] : ans) {
    cout << x + 1 << " " << y + 1 << ENDL;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}