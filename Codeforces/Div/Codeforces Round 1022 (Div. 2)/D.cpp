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

int ask(int i) {
  cout << "? " << i << endl;
  int x;
  cin >> x;
  return x;
}

// 1 2 1 2 1

void solve() {
  int n, k;
  cin >> n >> k;
  vi perm(k);
  FOR(i, 1, k + 1) { perm[i - 1] = ask(i); }

  int l = 1, r = n;
  while (r - l >= 5) {
    int mid = (l + r) / 2;
    int curr = ask(mid);
    if (perm[(mid - 1) % k] == curr) {
      l = mid;
    } else {
      r = mid;
    }
  }
  FOR(i, l, r + 1) {
    int curr = ask(i);
    if (perm[(i - 1) % k] != curr) {
      int a = i - 1, b = n - (i - 1);
      int falta = max(0, k - b);
      a -= falta;
      b = max(k, b);
      cout << "! " << a << " " << b << endl;
      return;
    }
  }
  if (k * 2 == n) {
    cout << "! " << k << " " << k << endl;
    return;
  }
  cout << "! -1" << endl;
}

signed main() {
  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}