#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, k;
  cin >> n >> m >> k;
  bool canGLose = true, canRLose = true;
  bool hayG = false, hayR = false;
  vi nims;
  FOR(i, 0, n) {
    int posG = -1, posR = -1;
    bool libre = false;
    FOR(j, 0, m) {
      char c;
      cin >> c;
      if (c == 'G') {
        posG = j;
        hayG = true;
      } else if (c == 'R') {
        posR = j;
        hayR = true;
      } else if (c == '-') {
        libre = true;
      }
    }
    if (libre) {
      if (posG == -1 && posR != -1) canRLose = false;
      if (posG != -1 && posR == -1) canGLose = false;
    }

    if (posG != -1 && posR != -1) {
      nims.pb(abs(posG - posR) - 1);
    }
  }

  if (!canGLose && !canRLose) {
    cout << "Draw" << ENDL;
    return 0;
  }
  if (!canGLose) {
    cout << "First" << ENDL;
    return 0;
  }
  if (!canRLose) {
    cout << "Second" << ENDL;
    return 0;
  }

  if (!hayG) {
    cout << "Second" << ENDL;
    return 0;
  }
  if (!hayR) {
    if (!canGLose) {
      cout << "First" << ENDL;
    } else {
      cout << "Second" << ENDL;
    }
    return 0;
  }

  vi nimBits(30, 0);
  for (auto nim : nims) {
    FOR(i, 0, 30) { nimBits[i] += ((nim >> i) & 1); }
  }

  FOR(i, 0, 30) {
    if (nimBits[i] % (k + 1) != 0) {
      cout << "First" << ENDL;
      return 0;
    }
  }
  cout << "Second" << ENDL;
  return 0;

  return 0;
}