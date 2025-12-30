#include <bits/stdc++.h>
using namespace std;
#define ENDL '\n'
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)

using ll = long long;
using vi = vector<int>;

array<vi, 2> manacher(string& s) {
  int n = s.size();
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

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  auto [m, _] = manacher(s);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (m[i] >= 2) {
      for (int j = m[i] / 2; j >= ans; j--) {
        if (m[i - j] >= j && m[i + j] >= j) {
          ans = j;
          break;
        }
      }
    }
  }
  cout << ans * 4 << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}