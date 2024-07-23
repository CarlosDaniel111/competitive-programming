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
  int n, m;
  cin >> n >> m;
  string s, s2;
  cin >> s;
  vi a(m);
  FOR(i, 0, m) cin >> a[i];
  cin >> s2;
  sort(ALL(a));
  sort(ALL(s2));
  a.resize(unique(ALL(a)) - a.begin());
  FOR(i, 0, SZ(a)) { s[a[i] - 1] = s2[i]; }
  cout << s << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}