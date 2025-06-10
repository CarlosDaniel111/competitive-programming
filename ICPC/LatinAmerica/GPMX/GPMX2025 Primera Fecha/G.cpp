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

void solve() {
  int n, A;
  cin >> n >> A;
  deque<pi> dq;
  dq.push_front({0, 1});
  dq.push_back({0, 0});

  n -= 2;
  int currX1 = 0, currY1 = 1;
  int currX2 = 0, currY2 = 0;
  int currA = 0;
  bool arriba = false;
  while (n > 2) {
    if (arriba) {
      currX1++, currY1++;
      currX2++, currY2++;
    } else {
      currX1++;
      currX2++;
    }
    dq.push_front({currX1, currY1});
    dq.push_back({currX2, currY2});
    arriba = !arriba;
    currA++;
    n -= 2;
  }
  if (currA >= A) {
    cout << "No" << ENDL;
    return;
  }

  int falta = A - currA;
  if (n == 1) {
    if (arriba) {
      dq.back().first++;
      falta *= 2;
      falta--;
      currY1 += falta;
    } else {
      falta *= 2;
      currX1 += falta;
    }
    dq.push_front({currX1, currY1});
  } else {
    if (arriba) {
      currX1 += falta;
      currX2 += falta;
      currY1 += falta;
      currY2 += falta;
    } else {
      currX1 += falta;
      currX2 += falta;
    }
    dq.push_front({currX1, currY1});
    dq.push_back({currX2, currY2});
  }

  cout << "Yes" << ENDL;
  for (auto [x, y] : dq) {
    cout << x << " " << y << ENDL;
  }
}
signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}