#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int m, s;
  cin >> m >> s;
  if (m * 9 < s || (!s && m != 1)) {
    cout << "-1 -1" << ENDL;
    return 0;
  }
  if (!s && m == 1) {
    cout << "0 0" << ENDL;
    return 0;
  }
  int suma = 1;
  vi ans2(m, 0);
  ans2[0] = 1;
  int j = m - 1;
  while (suma < s) {
    if (ans2[j] == 9) j--;
    ans2[j]++;
    suma++;
  }

  int s2 = s;
  vi ans;
  while (s2 >= 10) {
    ans.pb(9);
    s2 -= 9;
  }
  ans.pb(s2);
  while (SZ(ans) < m) ans.pb(0);

  FOR(i, 0, m) { cout << ans2[i]; }
  cout << " ";

  FOR(i, 0, m) { cout << ans[i]; }
  cout << ENDL;

  return 0;
}