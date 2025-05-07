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

bool check(int k, string s) {
  int n = SZ(s);

  FOR(i, 0, k) {
    if (s[0] != s[i]) return false;
  }
  for (int i = 0; i + k < n; i++) {
    if (s[i] == s[i + k]) return false;
  }
  return true;
}

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (check(k, s)) {
    cout << n << ENDL;
    return;
  }
  int cnt = 1, r;
  s += "0";
  FOR(i, 0, n) {
    if (s[i] == s[i + 1]) {
      cnt++;
    } else {
      if (cnt == k) {
        cnt = 1;
        continue;
      } else if (cnt < k) {
        r = i;
        break;
      } else {
        r = i - k;
        break;
      }
    }
  }
  string res = "";
  FOR(i, r + 1, n) { res += s[i]; }
  ROF(i, r + 1, 0) { res += s[i]; }
  if (check(k, res)) {
    cout << r + 1 << ENDL;
  } else {
    cout << -1 << ENDL;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}