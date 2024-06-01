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

#define isOn(S, j) (S & (1 << j))

void solve() {
  int n;
  cin >> n;
  vi a(n);
  int xtotal = 0;
  FOR(i, 0, n) {
    cin >> a[i];
    xtotal |= a[i];
  }

  if (n == 1) {
    cout << 1 << ENDL;
    return;
  }

  int aux = 0;
  int k;
  vi cnt(30, 0);
  FOR(j, 0, n) {
    FOR(i, 0, 25) {
      if (isOn(a[j], i)) {
        cnt[i]++;
      }
    }
    aux |= a[j];
    if (aux == xtotal) {
      k = j + 1;
      break;
    }
  }

  FOR(j, k, n) {
    FOR(i, 0, 25) {
      if (isOn(a[j], i)) {
        cnt[i]++;
      }
    }
    bool error = false;
    FOR(i, 0, 25) {
      if (isOn(a[j - k], i)) {
        cnt[i]--;
        if (cnt[i] == 0) error = true;
      }
    }
    if (error) {
      FOR(i, 0, 25) {
        if (isOn(a[j - k], i)) {
          cnt[i]++;
        }
      }

      k++;
    }
  }

  cout << k << ENDL;
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