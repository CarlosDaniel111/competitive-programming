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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;
  map<int, int> m;
  FOR(i, 0, n) {
    int x;
    cin >> x;
    m[x]++;
  }

  for (auto x : m) {
    if (x.second % 2 == 1) {
      cout << "Conan" << ENDL;
      return 0;
    }
  }
  cout << "Agasa" << ENDL;

  return 0;
}