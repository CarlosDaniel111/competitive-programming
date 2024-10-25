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

void print(__int128 x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}

signed main() {
  string sa;
  cin >> sa;
  ll bll, cll, dll;
  cin >> bll >> cll >> dll;
  ll g = gcd(cll, dll);
  __int128_t b = bll, c = cll / g, d = dll / g;

  int n = SZ(sa);
  FOR(msk, 1, (1ll << n)) {
    string curr = "";
    vi elim(10, 0);
    FOR(i, 0, n) {
      if ((msk >> i) & 1) {
        curr += sa[i];
      } else {
        elim[sa[i] - '0']++;
      }
    }
    ll All = stoll(curr);
    __int128_t A = All;
    if (A * d % c != 0) continue;
    __int128_t B = A * d / c;
    __int128_t ans = B;
    __int128_t currb = b;
    bool ok = true;
    while (B) {
      if (B % 10 == currb % 10) {
        B /= 10;
        currb /= 10;
      } else {
        if (elim[currb % 10]) {
          elim[currb % 10]--;
          currb /= 10;
        } else {
          ok = false;
          break;
        }
      }
    }

    if (!ok) continue;
    while (currb) {
      if (elim[currb % 10]) {
        elim[currb % 10]--;
        currb /= 10;
      } else {
        ok = false;
        break;
      }
    }
    if (!ok) continue;
    FOR(i, 0, 10) {
      if (elim[i]) {
        ok = false;
        break;
      }
    }
    if (!ok) continue;
    cout << "possible" << ENDL;
    print(A);
    cout << " ";
    print(ans);
    cout << ENDL;
    return 0;
  }
  cout << "impossible" << ENDL;

  return 0;
}