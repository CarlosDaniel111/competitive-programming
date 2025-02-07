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

  int k;
  cin >> k;
  k = (k - 1) / 2;
  vector<tuple<int, int, int, int>> ans;

  stack<int> st;
  while (k) {
    if (k == 1) {
      st.push(0);
      break;
    }
    if (k % 2 == 0) {
      st.push(0);
    }
    st.push(1);
    k = (k - 1) / 2;
  }

  int t = 1;
  while (SZ(st)) {
    int x = st.top();
    st.pop();
    if (x == 0) {
      // +1
      ans.pb({t, t + 1, t, t});
    } else {
      // *2+1
      ans.pb({t, t + 1, t, 1});
    }
    t++;
  }
  cout << SZ(ans) + 1 << ENDL;
  FOR(i, 0, SZ(ans)) {
    auto [a, b, c, d] = ans[i];
    cout << "POP " << a << " GOTO " << b << "; PUSH " << c << " GOTO " << d
         << ENDL;
  }
  cout << "HALT; PUSH 100 GOTO 1" << ENDL;

  return 0;
}