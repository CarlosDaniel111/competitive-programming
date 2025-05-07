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
  string s;
  cin >> s;
  set<int> pat;
  int n = SZ(s);
  FOR(i, 0, n - 3) {
    if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
      pat.insert(i + 3);
  }
  auto print = [&]() -> void {
    if (SZ(pat))
      cout << "YES" << ENDL;
    else
      cout << "NO" << ENDL;
  };
  int q;
  cin >> q;
  while (q--) {
    int pos;
    char c;
    cin >> pos >> c;
    pos--;
    s[pos] = c;

    FOR(i, max(0, pos - 3), min(n - 3, pos + 1)) {
      if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0')
        pat.insert(i + 3);
      else
        pat.erase(i + 3);
    }
    print();
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}