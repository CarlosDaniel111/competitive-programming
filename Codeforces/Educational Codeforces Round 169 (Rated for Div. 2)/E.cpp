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

constexpr int MAX = 1e7 + 5;
int grundy[MAX];

void solve() {
  int n;
  int curr = 0;
  cin >> n;
  FOR(i, 0, n) {
    int x;
    cin >> x;
    curr ^= grundy[x];
  }
  cout << (curr ? "Alice" : "Bob") << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  grundy[1] = 1;
  int cnt = 2;
  for (int i = 3; i < MAX; i += 2) {
    if (grundy[i]) continue;
    grundy[i] = cnt;
    for (int j = i; j < MAX; j += 2 * i)
      if (!grundy[j]) grundy[j] = cnt;
    cnt++;
  }

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}