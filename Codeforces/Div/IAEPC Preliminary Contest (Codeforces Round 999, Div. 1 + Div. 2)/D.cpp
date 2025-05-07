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
  int n, m;
  cin >> n >> m;
  priority_queue<int> a, b;
  FOR(i, 0, n) {
    int x;
    cin >> x;
    a.push(x);
  }
  FOR(i, 0, m) {
    int x;
    cin >> x;
    b.push(x);
  }

  while (SZ(a) && SZ(b) && SZ(b) <= SZ(a)) {
    int curr = b.top();
    b.pop();
    if (curr < a.top()) {
      cout << "No" << ENDL;
      return;
    }
    if (curr == a.top()) {
      a.pop();
      continue;
    }
    b.push(curr / 2);
    b.push((curr + 1) / 2);
  }
  if (!SZ(a) && !SZ(b)) {
    cout << "Yes" << ENDL;
  } else {
    cout << "No" << ENDL;
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}