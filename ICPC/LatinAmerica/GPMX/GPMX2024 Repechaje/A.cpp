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

  int n;
  cin >> n;
  vector<pair<string, string>> a(n);
  FOR(i, 0, n) {
    string s, s2;
    cin >> s;
    s2 = s;
    sort(ALL(s));
    a[i] = {s, s2};
  }
  sort(ALL(a));
  int q;
  cin >> q;
  while (q--) {
    string s, s2;
    cin >> s;
    s2 = s;
    sort(ALL(s));
    cout << lower_bound(ALL(a), make_pair(s, s2)) - a.begin() << ENDL;
  }

  return 0;
}