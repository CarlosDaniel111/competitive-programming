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
  bool adelante = true;
  string t = "";
  while (SZ(t) < n) {
    if (adelante)
      t += "0";
    else
      t = "0" + t;
    cout << "? " << t << endl;
    int can;
    cin >> can;
    if (can) continue;
    if (adelante) {
      t[SZ(t) - 1] = '1';
      cout << "? " << t << endl;
      cin >> can;
      if (!can) {
        adelante = false;
        t = t.substr(0, SZ(t) - 1);
      }
    } else
      t[0] = '1';
  }
  cout << "! " << t << endl;
}

signed main() {
  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}