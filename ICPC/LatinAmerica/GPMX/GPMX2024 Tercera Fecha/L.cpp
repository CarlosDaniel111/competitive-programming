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
  vi cnt(30);
  FOR (i, 0, n) {
    int x;
    cin >> x;
    FOR (j, 0, 30) cnt[j] += (x >> j) & 1;
  }
  FOR (i, 0, n) {
    int x = 0;
    FOR (j, 0, 30) if (cnt[j]) x |= 1 << j, cnt[j]--;
    cout << x << ' ';
  }
  cout << ENDL;

  return 0;
}