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
  string s;
  cin >> n >> s;
  int ans = 1e9;
  FOR(i, 0, n - 1) {
    vi a;
    FOR(j, 0, n) {
      if (j == i + 1) continue;
      if (j == i)
        a.pb(stoi(s.substr(j, 2)));
      else
        a.pb(s[j] - '0');
    }
    int suma = 0;
    for (auto x : a) {
      if (x == 0) {
        cout << "0" << ENDL;
        return;
      }
      if (x > 1) suma += x;
    }
    suma = max(suma, 1);
    ans = min(ans, suma);
  }
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}