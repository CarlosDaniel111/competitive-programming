#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x).size())
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
char mp[255][255];
void solve() {
  int n;
  cin >> n;
  vector<pair<char, int>> ans;
  char initial, ant;
  FOR(i, 0, n) {
    char c;
    int x;
    cin >> c >> x;
    if (i == 0) {
      initial = c;
      ant = c;
      ans.push_back({'Z', x});
      continue;
    }
    ans.push_back({mp[ant][c], -1});
    ans.push_back({'Z', x});
    ant = c;
  }
  cout << SZ(ans) << " " << initial << '\n';
  for (auto [c, x] : ans) {
    cout << c;
    if (x != -1) cout << " " << x;
    cout << '\n';
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  mp['S']['E'] = 'L';
  mp['S']['W'] = 'R';
  mp['N']['E'] = 'R';
  mp['N']['W'] = 'L';
  mp['E']['N'] = 'L';
  mp['E']['S'] = 'R';
  mp['W']['N'] = 'R';
  mp['W']['S'] = 'L';

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}