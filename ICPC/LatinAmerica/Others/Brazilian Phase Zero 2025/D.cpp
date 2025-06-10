#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  int c1 = 0, c2 = 0;
  string s1, s2;
  cin >> s1 >> s2;

  for (char c : s1) {
    c1 += (c == '*');
  }
  for (char c : s2) {
    c2 += (c == '*');
  }

  cout << fixed << setprecision(2);
  cout << double(c1 - c2) / c1 << '\n';

  return 0;
}