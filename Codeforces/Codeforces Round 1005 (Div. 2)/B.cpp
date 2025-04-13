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
  set<int> st;
  vi cnt(n + 1, 0);
  FOR(i, 0, n) {
    cin >> a[i];
    st.insert(a[i]);
    cnt[a[i]]++;
  }
  if (n == 1) {
    cout << "1 1" << ENDL;
    return;
  }
  if (SZ(st) == 1) {
    cout << "0" << ENDL;
    return;
  }

  int l = -1, r = -1;
  FOR(i, 0, n) {
    if (cnt[a[i]] == 1) {
      int currl = i, currr = i;
      while (currr < n && cnt[a[currr]] == 1) currr++;
      if (r - l < currr - currl) {
        r = currr;
        l = currl + 1;
      }
      i = currr - 1;
    }
  }
  if (l == -1) {
    cout << 0 << ENDL;
    return;
  }
  cout << l << " " << r << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}