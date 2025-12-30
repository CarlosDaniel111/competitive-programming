#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

int diff(int d1, int h1, int m1, int d2, int h2, int m2) {
  int dx = d2 - d1;
  int hx = h2 - h1;
  if (hx < 0) {
    dx--;
    hx += 24;
  }
  int mx = m2 - m1;
  if (mx < 0) {
    hx--;
    mx += 60;
  }
  return dx * 24 * 60 + hx * 60 + mx;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  map<string, int> dton;
  dton["Mon"] = 0;
  dton["Tue"] = 1;
  dton["Wed"] = 2;
  dton["Thu"] = 3;
  dton["Fri"] = 4;
  dton["Sat"] = 5;
  dton["Sun"] = 6;
  string dia1, dia2;
  int h1, m1, h2, m2;
  char c;
  cin >> dia1 >> h1 >> c >> m1;
  cin >> dia2 >> h2 >> c >> m2;
  int d1 = dton[dia1], d2 = dton[dia2];

  if (d1 == d2 && h1 == h2 && m1 == m2) {
    cout << "7 days" << '\n';
    return 0;
  }
  int min = 0;
  if (d1 > d2 or (d1 == d2 && h1 > h2) or (d1 == d2 && h1 == h2 && m1 > m2)) {
    min = diff(d1, h1, m1, 7, 0, 0) + diff(0, 0, 0, d2, h2, m2);
  } else {
    min = diff(d1, h1, m1, d2, h2, m2);
  }

  int mans = min % 60;
  int hor = min / 60;
  int hans = hor % 24;
  int dans = hor / 24;

  if (dans) {
    cout << dans << " day";
    if (dans > 1) cout << "s";
    if ((hans && !mans) or (!hans && mans)) {
      cout << " and ";
    }
    if (hans && mans) {
      cout << ", ";
    }
  }
  if (hans) {
    cout << hans << " hour";
    if (hans > 1) cout << "s";
    if (mans && dans) cout << ", ";
    if (!dans && mans) {
      cout << " and ";
    }
  }
  if (mans) {
    cout << mans << " minute";
    if (mans > 1) cout << "s";
  }
  cout << '\n';

  return 0;
}