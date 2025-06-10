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
  cin >> n;
  int jury;
  cout << "digit" << endl;
  cin >> jury;
  cout << "digit" << endl;
  cin >> jury;

  cout << "add " << -8 << endl;
  cin >> jury;

  cout << "add " << -4 << endl;
  cin >> jury;

  cout << "add " << -2 << endl;
  cin >> jury;

  cout << "add " << -1 << endl;
  cin >> jury;

  if (n == 1) {
    cout << "!" << endl;
  } else {
    cout << "add " << n - 1 << endl;
    cin >> jury;
    cout << "!" << endl;
  }
  cin >> jury;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}