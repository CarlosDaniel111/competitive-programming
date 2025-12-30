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

void solve() {
  int n;
  cin >> n;
  vi a(n);
  int start;
  FOR(i, 0, n) {
    cin >> a[i];
    if (a[i] == n) start = !(i & 1);
  }
  vi ans(n);
  vi id1, id2;
  for (int i = start; i < n; i += 2) id1.pb(i);
  for (int i = !start; i < n; i += 2) id2.pb(i);
  sort(ALL(id1), [&](int i, int j) { return a[i] > a[j]; });
  sort(ALL(id2), [&](int i, int j) { return a[i] > a[j]; });
  int cnt = 1;
  for (auto i : id1) ans[i] = cnt++;
  for (auto i : id2) ans[i] = cnt++;
  for (auto x : ans) cout << x << " ";
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}