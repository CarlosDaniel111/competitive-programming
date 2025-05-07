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
  int n, k;
  cin >> n >> k;
  multiset<int> st;
  FOR(i, 0, n) {
    int x;
    cin >> x;
    st.insert(x);
  }
  int ans = 0;
  while (SZ(st)) {
    auto it = st.begin();
    int x = *it;
    st.erase(it);
    if (k > x)
      it = st.find(k - x);
    else
      it = st.find(x - k);
    if (it == st.end()) continue;
    ans++;
    st.erase(it);
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