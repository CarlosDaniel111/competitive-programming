#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

int g[200][200];

void solve() {
  int n;
  cin >> n;
  vector<int> mas1;
  while (n > 1) {
    mas1.push_back(n & 1);
    n /= 2;
  }
  memset(g, 0, sizeof(g));
  g[0][0] = 1;
  int curr = 1, ant = 0;
  for (int i = mas1.size() - 1; i >= 0; i--) {
    g[curr][curr] = g[curr][curr + 1] = g[curr + 1][curr] =
        g[curr + 1][curr + 1] = 1;
    g[ant][curr] = 1;
    ant = curr + 1;
    curr += 2;
    if (mas1[i]) {
      g[ant][curr] = g[curr][curr] = g[curr][0] = 1;
      curr++;
    }
  }
  cout << curr << '\n';
  for (int i = 0; i < curr; i++) {
    for (int j = 0; j < curr; j++) {
      cout << g[i][j];
    }
    cout << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}