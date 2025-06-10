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
  int q;
  cin >> q;
  int n = SZ(s);
  auto can = [&](string &t) -> bool {
    int m = SZ(t);
    if (m % n != 0) return 0;
    int veces = m / n;
    FOR(i, 0, veces) {
      FOR(j, 0, n) {
        if (s[j] != t[i * n + j]) return false;
      }
    }
    return 1;
  };
  while (q--) {
    string t;
    cin >> t;
    if (can(t))
      cout << "Yes" << ENDL;
    else
      cout << "No" << ENDL;
  }

  return 0;
}