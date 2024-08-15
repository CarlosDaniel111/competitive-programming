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
  int l = 1, r = 1000;
  while (l < r) {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    cout << "? " << m1 << " " << m2 << endl;
    int curr = 0;
    int x;
    cin >> x;
    if (m1 * m2 == x)
      l = m2;
    else if ((m1 + 1) * (m2 + 1) == x)
      r = m1;
    else {
      l = m1 + 1;
      r = m2;
    }
  }
  cout << "! " << r << endl;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}