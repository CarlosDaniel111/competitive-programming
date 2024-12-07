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

  int k;
  string s;
  cin >> k >> s;
  int n = SZ(s);
  if (k == 2) {
    int case1 = 0, case2 = 0;
    FOR(i, 0, n) {
      if (i & 1) {
        case1 += (s[i] == '0');
        case2 += (s[i] == '1');
      } else {
        case1 += (s[i] == '1');
        case2 += (s[i] == '0');
      }
    }
    if (case1 < case2) {
      cout << case1 << " ";
      FOR(i, 0, n) {
        if (i & 1)
          cout << "1";
        else
          cout << "0";
      }
    } else {
      cout << case2 << " ";
      FOR(i, 0, n) {
        if (i & 1)
          cout << "0";
        else
          cout << "1";
      }
    }
    cout << ENDL;
    return 0;
  }

  int ans = 0;
  int l = 0, r = 0;
  while (l < n) {
    while (r < n && s[l] == s[r]) r++;
    ans += (r - l) / k;
    l = r;
  }
  cout << ans << " ";

  l = r = 0;
  while (l < n) {
    while (r < n && s[l] == s[r]) r++;
    if ((r - l) < k) {
      FOR(i, 0, r - l) cout << s[l];
      l = r;
      continue;
    }
    if ((r - l) % k) {
      int bloques = (r - l) / k;
      FOR(i, 0, bloques) {
        FOR(j, 0, k - 1) cout << s[l];
        cout << ((s[l] - '0') + 1) % 2;
      }
      int falta = (r - l) % k;
      FOR(i, 0, falta) { cout << s[l]; }
    } else {
      int bloques = (r - l) / k;
      FOR(i, 0, bloques - 1) {
        FOR(j, 0, k - 1) cout << s[l];
        cout << ((s[l] - '0') + 1) % 2;
      }
      FOR(i, 0, k - 2) cout << s[l];
      cout << ((s[l] - '0') + 1) % 2;
      cout << s[l];
    }
    l = r;
  }

  return 0;
}