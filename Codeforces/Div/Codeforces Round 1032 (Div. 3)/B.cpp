#include <bits/stdc++.h>
using namespace std;

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
  string s;
  cin >> s;
  vi vis(26, 0);
  for (int i = 0; i < n - 1; i++) {
    char c = s[i];
    if (vis[c - 'a']) {
      cout << "Yes" << ENDL;
      return;
    }
    vis[c - 'a'] = 1;
  }
  vis.assign(26, 0);
  reverse(ALL(s));
  for (int i = 0; i < n - 1; i++) {
    char c = s[i];
    if (vis[c - 'a']) {
      cout << "Yes" << ENDL;
      return;
    }
    vis[c - 'a'] = 1;
  }
  cout << "No" << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}