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

vi a = {1, 2, 2, 3, 1, 4, 4, 3};
vi b = {1, 2, 2, 3, 3, 4};

void solve() {
  int n;
  cin >> n;
  if (n <= 6) {
    if (n == 1)
      cout << 1 << ENDL;
    else if (n <= 3)
      cout << 2 << ENDL;
    else if (n <= 5)
      cout << 3 << ENDL;
    else
      cout << 4 << ENDL;
    FOR(i, 0, n) { cout << b[i] << " "; }
  } else {
    cout << 4 << ENDL;
    FOR(i, 0, n) { cout << (i % 4) + 1 << " "; }
  }
  cout << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}