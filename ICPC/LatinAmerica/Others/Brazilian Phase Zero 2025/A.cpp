#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int C, G;
  cin >> C >> G;

  if (C) {
    cout << "vivo e morto\n";
  } else {
    if (G) {
      cout << "vivo\n";
    } else {
      cout << "morto\n";
    }
  }

  return 0;
}