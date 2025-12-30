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

void solve() {
  int n;
  cin >> n;
  vi a(n);
  priority_queue<pi> pq;
  FOR(i, 0, n) {
    cin >> a[i];
    if (a[i] != -1) pq.push({a[i], i});
  }
  if (!SZ(pq)) {
    FOR(i, 0, n) { cout << (i & 1) + 1 << " "; }
    cout << ENDL;
    return;
  }

  while (SZ(pq)) {
    auto [_, i] = pq.top();
    pq.pop();
    if (i) {
      if (a[i - 1] == -1) {
        a[i - 1] = (a[i] != 1 ? a[i] / 2 : 2);
        pq.push({a[i - 1], i - 1});
      } else if (a[i] != a[i - 1] / 2 && a[i] / 2 != a[i - 1]) {
        cout << -1 << ENDL;
        return;
      }
    }

    if (i < n - 1) {
      if (a[i + 1] == -1) {
        a[i + 1] = (a[i] != 1 ? a[i] / 2 : 2);
        pq.push({a[i + 1], i + 1});
      } else if (a[i] != a[i + 1] / 2 && a[i] / 2 != a[i + 1]) {
        cout << -1 << ENDL;
        return;
      }
    }
  }
  for (auto x : a) cout << x << " ";
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}