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
  int n, m, k;
  cin >> n >> m >> k;
  vi a(n), b(m);
  map<int, int> cnt;
  FOR(i, 0, n) {
    cin >> a[i];
  }
  int act = 0;
  set<int> impor;
  FOR(i, 0, m) {
    cin >> b[i];
    cnt[b[i]]++;
    impor.insert(b[i]);
  }
  vector<bool> conto(n, 0);

  FOR(i, 0, m) {
    if (cnt[a[i]] > 0) {
      act++;
    }
    cnt[a[i]]--;
  }
  int ans = 0;
  if (act >= k) ans++;
  FOR(i, m, n) {
    if (impor.count(a[i - m]) && cnt[a[i - m]] >= 0) {
      act--;
    }
    if (impor.count(a[i - m])) {
      cnt[a[i - m]]++;
    }

    if (impor.count(a[i]) && cnt[a[i]] > 0) {
      act++;
    }
    if (impor.count(a[i])) cnt[a[i]]--;

    // cout << act << ENDL;
    if (act >= k) ans++;
  }
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}