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
  string s;
  cin >> s;
  int n = SZ(s);
  vi p(n);
  iota(ALL(p), 1);

  auto can = [&]() -> bool {
    FOR(i, 0, n) {
      char c = s[i];
      if (c == '.') continue;
      if (c == 's') {
        vi st(n + 1, 0);
        FOR(j, i, n) { st[p[j]] = 1; }
        FOR(j, 1, n - i + 1) {
          if (st[j] == 0) {
            return false;
          }
        }
      } else {
        vi st(n + 1, 0);
        FOR(j, 0, i + 1) { st[p[j]] = 1; }
        FOR(j, 1, i + 2) {
          if (st[j] == 0) return false;
        }
      }
    }
    return true;
  };
  do {
    if (can()) {
      FOR(i, 0, n) { cout << p[i] << " "; }
      cout << ENDL;
      return;
    }
  } while (next_permutation(ALL(p)));
  cout << "no" << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}