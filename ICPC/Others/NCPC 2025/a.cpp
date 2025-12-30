#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int s;
  cin >> s;

  if (s == 999) {
    cout << "998 1" << '\n';
    return 0;
  }
  if (s == -1) {
    cout << "2 -3" << '\n';
    return 0;
  }
  cout << s + 1 << " " << -1 << '\n';

  return 0;
}