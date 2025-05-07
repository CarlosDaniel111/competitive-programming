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
  int ini = -1;
  vi pos;
  FOR(i, 0, n) {
    if (s[i] == '0') {
      ini = i;
      FOR(j, 0, i + 1) {
        if (s[j] == '1') {
          pos.pb(j);
        }
      }
      break;
    }
  }

  if (ini == -1) {
    cout << "1 " << n << " 1 1" << ENDL;
    return;
  }
  int curr = 0;
  FOR(i, ini, n) {
    char need = s[i] == '1' ? '0' : '1';
    vi sigPos;
    for (auto j : pos) {
      if (s[j + curr] == need) {
        sigPos.pb(j);
      }
    }
    if (SZ(sigPos)) {
      pos = sigPos;
    } else {
      break;
    }
    curr++;
  }
  cout << "1 " << n << " " << pos[0] + 1 << " " << pos[0] + (n - ini) << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}