#include <bits/stdc++.h>
using namespace std;
#define ENDL '\n'

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> termina(n, 1);
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1]) {
      termina[i] = termina[i - 1] + 1;
    }
  }
  vector<int> empieza(n, 1);
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] < a[i + 1]) {
      empieza[i] = empieza[i + 1] + 1;
    }
  }

  vector<int> mn(n + 5, 1e9);
  int ans = 1;
  for (int i = 0; i < n; i++) {
    int lenizq = lower_bound(mn.begin(), mn.end(), a[i]) - mn.begin() - 1;
    mn[termina[i]] = min(mn[termina[i]], a[i]);
    ans = max(ans, empieza[i] + lenizq);
  }
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}