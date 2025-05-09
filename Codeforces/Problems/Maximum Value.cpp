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

constexpr int MAX = 2e6 + 5;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vi a(n), sig(MAX * 2, 0);
  FOR(i, 0, n) {
    cin >> a[i];
    sig[a[i]] = a[i];
  }
  sort(ALL(a));
  a.erase(unique(ALL(a)), a.end());
  FOR(i, 1, MAX)
  if (!sig[i]) sig[i] = sig[i - 1];

  int ans = 0;
  for (auto x : a) {
    for (int j = x + x - 1; j < MAX; j += x) {
      if (sig[j] >= j + 1 - x) ans = max(ans, sig[j] - (j + 1 - x));
    }
  }
  cout << ans << ENDL;

  return 0;
}