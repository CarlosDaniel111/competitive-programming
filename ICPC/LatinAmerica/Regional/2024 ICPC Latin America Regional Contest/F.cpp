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

  int k, n;
  cin >> k >> n;
  if (k < (n + 2) / 3 or k > (n + 1) / 2) {
    cout << "*" << ENDL;
    return 0;
  }
  if (n == k * 2 - 1) {
    FOR(_, 0, k - 1) { cout << "X-"; }
    cout << "X" << ENDL;
    return 0;
  }

  FOR(i, 0, k * 3 - n) { cout << "X-"; }
  FOR(i, 0, n - k * 2) { cout << "-X-"; }
  cout << ENDL;

  return 0;
}