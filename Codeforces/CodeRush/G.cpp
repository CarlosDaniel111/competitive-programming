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
  int cnt1 = 0, cnt2 = 0;
  FOR(i, 0, n) {
    int x;
    cin >> x;
    cnt1 += (x & 1);
    cnt2 += !(x & 1);
  }
  if (cnt1 >= cnt2) {
    cout << "Notbastian" << ENDL;
  } else {
    cout << "Sebastian" << ENDL;
  }

  return 0;
}