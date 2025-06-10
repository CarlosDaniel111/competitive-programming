#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << ENDL;
    return 0;
  }
  if (n <= 3) {
    cout << "NO SOLUTION" << ENDL;
    return 0;
  }
  if (n == 4) {
    cout << "2 4 1 3" << ENDL;
    return 0;
  }
  for (int i = 0; i < n; i += 2) cout << i + 1 << " ";
  for (int i = 1; i < n; i += 2) cout << i + 1 << " ";
  cout << ENDL;

  return 0;
}