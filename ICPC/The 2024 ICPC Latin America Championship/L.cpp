#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
#define __                      \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);

signed main() {
  __ int r, c, k;
  cin >> r >> c >> k;
  vector<string> A(r), B(r);
  FOR(i, 0, r) {
    cin >> A[i] >> B[i];
  }

  vi has(r, 0);
  FOR(i, 0, r) {
    for (auto &c : B[i]) has[i] |= (c == '*');
  }

  FOR(i, 0, r) {
    for (auto &c : A[i]) {
      if (c == '-' && has[i]) {
        cout << "N" << ENDL;
        return 0;
      }
    }
  }
  cout << "Y" << ENDL;

  return 0;
}