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

string types[6] = {"BG", "BR", "BY", "GR", "GY", "RY"};

bool isValid(string a, string b) {
  FOR(i, 0, 2) {
    FOR(j, 0, 2) {
      if (a[i] == b[j]) return true;
    }
  }
  return false;
}

void solve() {
  int n, q;
  cin >> n >> q;
  map<string, vi> pos;
  vector<string> a(n);
  FOR(i, 0, n) {
    cin >> a[i];
    pos[a[i]].pb(i);
  }

  while (q--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (x > y) swap(x, y);
    if (isValid(a[x], a[y])) {
      cout << y - x << ENDL;
      continue;
    }

    int ans = 1e9;
    for (string type : types) {
      if (isValid(a[x], type) && isValid(a[y], type)) {
        auto it1 = lower_bound(ALL(pos[type]), x);
        if (it1 != pos[type].end() && *it1 <= y) {
          ans = y - x;
          break;
        }
        if (it1 != pos[type].begin()) {
          ans = min(ans, abs(*prev(it1) - x) + abs(*prev(it1) - y));
        }
        if (it1 != pos[type].end()) {
          ans = min(ans, abs(*it1 - x) + abs(*it1 - y));
        }
      }
    }
    if (ans == 1e9) ans = -1;
    cout << ans << ENDL;
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