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
  int n, l;
  cin >> n >> l;
  vector<pi> a(n);
  FOR(i, 0, n) cin >> a[i].second >> a[i].first;
  sort(ALL(a));
  int ans = 0;
  FOR(i, 0, n) {
    priority_queue<int> pq;
    ll curr = 0;
    FOR(j, i, n) {
      pq.push(a[j].second);
      curr += a[j].second;
      while (SZ(pq) && a[j].first - a[i].first + curr > l) {
        curr -= pq.top();
        pq.pop();
      }
      ans = max(ans, SZ(pq));
    }
  }
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}