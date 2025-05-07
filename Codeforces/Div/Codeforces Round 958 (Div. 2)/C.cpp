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
  ll n;
  cin >> n;
  vi aux;
  ROF(i, 63, 0) {
    if ((1ll << i) & n) aux.pb(i);
  }
  if (SZ(aux) == 1) {
    cout << "1" << ENDL << n << ENDL;
    return;
  }
  cout << SZ(aux) + 1 << ENDL;
  FOR(i, 0, SZ(aux)) {
    cout << n - (1ll << aux[i]) << " ";
  }
  cout << n << ENDL;
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