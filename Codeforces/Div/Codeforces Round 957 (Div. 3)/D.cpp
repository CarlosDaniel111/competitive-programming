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
  int n, m, k;
  cin >> n >> m >> k;
  string s;
  cin >> s;
  s = "L" + s + "L";
  n++;
  int curr = 0;

  auto brinco = [&](int curr) -> int {
    FOR(i, 1, m + 1) {
      if (curr + i == n) return curr + i;
      if (s[curr + i] == 'L') return curr + i;
    }
    ROF(i, min(n + 1, curr + m + 1), curr) {
      if (s[i] == 'W') return i;
    }
    return -1;
  };
  int nado = 0;
  while (curr < n) {
    if (s[curr] == 'L') {
      curr = brinco(curr);
      if (curr == -1) {
        cout << "NO" << ENDL;
        return;
      }
    } else {
      curr++;
      nado++;
      if (s[curr] == 'C' || nado > k) {
        cout << "NO" << ENDL;
        return;
      }
    }
  }
  cout << "YES" << ENDL;
  return;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}