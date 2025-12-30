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

array<vi, 2> manacher(const string& s) {
  int n = SZ(s);
  array<vi, 2> p = {vi(n + 1), vi(n)};
  FOR(z, 0, 2)
  for (int i = 0, l = 0, r = 0; i < n; i++) {
    int t = r - i + !z;
    if (i < r) p[z][i] = min(t, p[z][l + t]);
    int L = i - p[z][i], R = i + p[z][i] - !z;
    while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1]) p[z][i]++, L--, R++;
    if (R > r) l = L, r = R;
  }
  return p;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  while (cin >> s) {
    int n = SZ(s);
    array<vi, 2> p = manacher(s);
    int r = n;
    FOR(i, 0, n) {
      if (p[1][i] + i + 1 == n) {
        r = min(r, i - p[1][i]);
      }
    }
    FOR(i, 0, n + 1) {
      if (p[0][i] + i == n) {
        r = min(r, i - p[0][i]);
      }
    }
    string s2 = s.substr(0, r);
    reverse(ALL(s2));
    cout << s + s2 << ENDL;
  }

  return 0;
}