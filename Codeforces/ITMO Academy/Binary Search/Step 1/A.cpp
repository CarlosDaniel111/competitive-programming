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

  set<ll> s;
  int n, k;
  cin >> n >> k;
  FOR(i, 0, n) {
    ll x;
    cin >> x;
    s.insert(x);
  }
  while (k--) {
    ll x;
    cin >> x;
    if (s.count(x))
      cout << "YES" << ENDL;
    else
      cout << "NO" << ENDL;
  }

  return 0;
}