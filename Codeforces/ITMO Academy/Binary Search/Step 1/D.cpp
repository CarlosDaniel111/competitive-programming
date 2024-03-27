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

  int n;
  cin >> n;
  vi a(n);
  for (auto &x : a) cin >> x;
  sort(ALL(a));
  int k;
  cin >> k;
  while (k--) {
    int l, r;
    cin >> l >> r;
    cout << upper_bound(ALL(a), r) - lower_bound(ALL(a), l) << " ";
  }

  return 0;
}