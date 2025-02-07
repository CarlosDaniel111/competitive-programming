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

constexpr int MAX = 1e6 + 5;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vi a(n), b(MAX, 0);
  FOR(i, 0, n) {
    cin >> a[i];
    b[a[i]] = a[i];
  }
  FOR(i, 1, MAX)
  if (!b[i]) b[i] = b[i - 1];

  FOR(i, 2, MAX) { if () }

  return 0;
}