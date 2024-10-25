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
  string s, t;
  cin >> s >> t;
  int n = SZ(s), m = SZ(t);
  int aux = 0;
  FOR(i, 0, min(n, m)) {
    if (s[i] == t[i]) {
      aux++;
    } else {
      break;
    }
  }
  if (aux) {
    aux--;
  }
  cout << n + m - aux << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}