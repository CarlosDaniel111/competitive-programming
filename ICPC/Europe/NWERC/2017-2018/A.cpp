#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
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
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int N;
  cin >> N;
  vi a, b, input(N);
  FOR(i, 0, N) {
    cin >> input[i];
  }
  a.pb(input[0]);
  b.pb(input[0]);
  FOR(i, 1, N) {
    if (input[i] != input[i - 1]) {
      a.pb(input[i]);
      b.pb(input[i]);
    }
  }
  int n = SZ(a), m = 0;
  map<int, int> mapa;
  mapa[b[0]] = m++;
  sort(ALL(b));
  FOR(i, 1, n) {
    if (b[i] != b[i - 1]) {
      mapa[b[i]] = m++;
    }
  }
  vi f[N + 5];
  FOR(i, 0, n) {
    a[i] = mapa[a[i]];
    f[a[i]].pb(i);
  }
  int ans = n;
  vi vis(N + 5);
  FOR(i, 0, m) {
    int cnt = 0, idx;
    for (auto x : f[i]) {
      if (a[x - 1] == a[x] - 1) {
        if (vis[x - 1]) continue;
        idx = x;
        cnt++;
      }
    }
    if (cnt != 0) ans--;
    if (SZ(f[i]) != 1 && cnt == 1) vis[idx] = true;
  }

  cout << ans - 1 << ENDL;

  return 0;
}