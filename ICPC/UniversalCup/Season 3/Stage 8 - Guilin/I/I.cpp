#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x).size())

struct FT {
  vector<int> s;
  FT(int n) : s(n) {}
  void update(int pos, int dif) {
    for (; pos < SZ(s); pos |= pos + 1) s[pos] += dif;
  }
  int query(int pos) {
    int res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
    return res;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  FT bit(n + 5);
  map<int, int> ant;
  int ans = -1e9;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (!ant.count(x)) {
      ans = max(ans, bit.query(i) - x);
    } else {
      ans = max(ans, bit.query(i) - bit.query(ant[x] + 1) - x);
      bit.update(ant[x], -1);
    }
    ant[x] = i;
    bit.update(i, 1);
  }
  for (int i = 1; i <= min(n, m) + 1; i++) {
    if (!ant.count(i)) {
      ans = max(ans, bit.query(n) - i);
    } else {
      ans = max(ans, bit.query(n) - bit.query(ant[i] + 1) - i);
    }
  }
  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}