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
  FOR(i, 0, n)
  cin >> a[i];
  int m;
  cin >> m;
  FOR(_, 0, m) {
    string s;
    cin >> s;
    if (SZ(s) != n) {
      cout << "NO" << ENDL;
      continue;
    }
    bool can = true;
    map<int, char> mapa;
    FOR(i, 0, n) {
      if (mapa.count(a[i])) {
        if (mapa[a[i]] != s[i]) {
          can = false;
          break;
        }
      } else {
        mapa[a[i]] = s[i];
      }
    }

    map<char, int> mapa2;
    FOR(i, 0, n) {
      if (mapa2.count(s[i])) {
        if (mapa2[s[i]] != a[i]) {
          can = false;
          break;
        }
      } else {
        mapa2[s[i]] = a[i];
      }
    }
    cout << (can ? "YES" : "NO") << ENDL;
  }
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