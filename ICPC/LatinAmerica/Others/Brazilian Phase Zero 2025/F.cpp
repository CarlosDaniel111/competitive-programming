#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 8010, OFFSET = N / 2;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<vector<ll>> prev(5, vector<ll>(N));
  prev[0][OFFSET] = 1;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;

    vector<vector<ll>> curr = prev;
    for (int c = 1; c <= 4; ++c) {
      for (int s = 0; s < N; ++s) {
        if (0 <= s - x && s - x < N) {
          curr[c][s] += prev[c - 1][s - x];
        }
      }
    }
    prev.swap(curr);
  }

  int q;
  cin >> q;

  while (q--) {
    int x;
    cin >> x;
    cout << prev[4][x + OFFSET] << '\n';
  }

  return 0;
}