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
  vi a(n);
  int zeros = 0;
  FOR(i, 0, n) {
    cin >> a[i];
    zeros += (a[i] == 0);
  }
  if (!zeros) {
    FOR(i, 0, n) cout << a[i] << " ";
    cout << ENDL;
    return 0;
  }
  if (zeros == n) {
    ROF(i, n + 1, 1) cout << i << " ";
    cout << ENDL;
    return 0;
  }
  bool ok = true;
  int l = 0, r = n - 1, sigL = 0, sigR = n - 1, curr = 1;
  while (l <= r) {
    if (a[sigL] == 0 or sigL <= l) {
      sigL++;
      continue;
    }
    if (a[sigR] == 0 or sigR >= r) {
      sigR--;
      continue;
    }
    if (a[l] == curr)
      l++, curr++;
    else if (a[r] == curr)
      r--, curr++;
    else if (a[l] && a[r] == 0) {
      a[r] = curr;
      r--, curr++;
    } else if (a[r] && a[l] == 0) {
      a[l] = curr;
      l++, curr++;
    } else if (a[l] == 0 && a[r] == 0) {
      if (a[sigL] < a[sigR] or
          (a[sigL] == a[sigR] && (sigL - l) < (r - sigR))) {
        a[l] = curr;
        l++, curr++;
      } else {
        a[r] = curr;
        r--, curr++;
      }
    } else {
      cout << "*" << ENDL;
      return 0;
    }
  }

  for (auto x : a) cout << x << " ";
  cout << ENDL;

  return 0;
}