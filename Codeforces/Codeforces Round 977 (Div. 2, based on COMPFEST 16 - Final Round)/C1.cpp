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
  int n, m, q;
  cin >> n >> m >> q;
  vi a(n);
  set<int> comodines;
  FOR(i, 0, n) { cin >> a[i]; }
  vi b(m);
  FOR(i, 0, m) { cin >> b[i]; }
  int curr = 0;
  FOR(i, 0, m) {
    if (comodines.count(b[i])) {
      continue;
    }
    if (curr == n) {
      cout << "TIDAK" << ENDL;
      return;
    }
    if (a[curr] == b[i]) {
      comodines.insert(a[curr++]);
      continue;
    }
    cout << "TIDAK" << ENDL;
    return;
  }
  cout << "YA" << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}