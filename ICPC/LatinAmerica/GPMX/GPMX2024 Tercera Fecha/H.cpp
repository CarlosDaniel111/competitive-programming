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

  string S, T;
  cin >> S >> T;

  FOR (msk, 0, 1 << 16) {
    string s = S, t = T;
    int bit = 0;
    for (auto &c : s) if (c == '*') {
      c = char('0' + ((msk >> bit) & 1));
      bit++;
    }
    for (auto &c : t) if (c == '*') {
      c = char('0' + ((msk >> bit) & 1));
      bit++;
    }
    int vt = 0;
    FOR (i, 0, SZ(t)) if (t[i] == '1') vt |= 1 << (SZ(t) - i - 1);
    int res = 0;
    for (auto &c : s) {
      res += c == '1';
      res %= vt;
      res *= 2;
    }
    if (!res) {
      cout << s << ENDL;
      return 0;
    }
  }

  return 0;
}