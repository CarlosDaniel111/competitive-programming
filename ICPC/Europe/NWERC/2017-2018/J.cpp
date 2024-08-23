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

  string s;
  cin >> s;
  int n = SZ(s);
  set<int> st;
  FOR(i, 0, n) {
    if (s[i] == '0') {
      st.insert(i);
    }
  }
  st.insert(-1);
  st.insert(n);
  FOR(i, 0, n) {
    if (s[i] == '2') {
      int L = *(--st.lower_bound(i));
      int R = *st.lower_bound(i);
      int newZero = L + R - i;
      if (L != -1) {
        st.erase(L);
      }
      if (R != n) {
        st.erase(R);
      }
      st.insert(newZero);
    }
  }
  FOR(i, 0, n) {
    if (st.count(i)) {
      cout << "0";
    } else {
      cout << "1";
    }
  }

  return 0;
}