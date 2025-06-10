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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;
  set<int> st;
  int ans = 0;
  FOR(i, 0, n) {
    int x;
    cin >> x;
    st.insert(x);
    if (SZ(st) > k) {
      ans++;
      st.clear();
      st.insert(x);
    }
  }
  cout << ans + 1 << ENDL;

  return 0;
}