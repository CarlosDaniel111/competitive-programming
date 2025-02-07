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

vi Z(const string& S) {
  vi z(SZ(S));
  int l = -1, r = -1;
  FOR(i, 1, SZ(S)) {
    z[i] = i >= r ? 0 : min(r - i, z[i - l]);
    while (i + z[i] < SZ(S) && S[i + z[i]] == S[z[i]]) z[i]++;
    if (i + z[i] > r) l = i, r = i + z[i];
  }
  return z;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;
  vi z = Z(s);
  int n = SZ(s);
  set<int> st;
  FOR(i, 1, n) {
    int pr = z[i];
    if (i + pr == n && st.lower_bound(pr) != st.end()) {
      cout << s.substr(0, pr) << ENDL;
      return 0;
    }
    st.insert(pr);
  }
  cout << "Just a legend" << ENDL;

  return 0;
}