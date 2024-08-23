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

int r, s, n;
vi prefA, prefB, prefC;
vi a, b, c;
vector<bool> can;
bool dp[105][55][55];

bool solve(int i, int t1, int t2) {
  if (i == n) return true;
  if (dp[i][t1][t2]) return false;
  dp[i][t1][t2] = true;

  FOR(x, 0, r + 1) {
    FOR(y, 0, s + 1) {
      int val = c[i];
      val -= prefA[t1 + x] - prefA[t1];
      val -= prefB[t2 + y] - prefB[t2];
      if (val < 0 || !can[val]) continue;
      int sigT1 = (t1 + x) % r, sigT2 = (t2 + y) % s;
      if (solve(i + 1, sigT1, sigT2)) return true;
    }
  }
  return false;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> r >> s >> n;
  a.resize(r + r), b.resize(s + s), c.resize(n);
  FOR(i, 0, r) {
    cin >> a[i];
    a[i + r] = a[i];
  }
  FOR(i, 0, s) {
    cin >> b[i];
    b[i + s] = b[i];
  }
  FOR(i, 0, n) { cin >> c[i]; }

  prefA.assign(r + r + 1, 0);
  prefB.assign(s + s + 1, 0);
  FOR(i, 1, r + r + 1) { prefA[i] = prefA[i - 1] + a[i - 1]; }
  FOR(i, 1, s + s + 1) { prefB[i] = prefB[i - 1] + b[i - 1]; }

  can.assign(2e6 + 5, 0);
  can[0] = true;
  FOR(i, 0, 2e6 + 5) {
    if (i - prefA[r] >= 0) can[i] = can[i] || can[i - prefA[r]];
    if (i - prefB[s] >= 0) can[i] = can[i] || can[i - prefB[s]];
  }

  if (solve(0, 0, 0)) {
    cout << "yes" << ENDL;
  } else {
    cout << "no" << ENDL;
  }

  return 0;
}