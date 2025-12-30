#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> m >> n;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      a[i][j]--;
    }
  }

  set<vector<int>> st;

  for (int i = 0; i < n; i++) {
    set<vector<int>> nxt;
    for (auto vec : st) {
      vector<int> aux(m);
      for (int j = 0; j < m; j++) aux[j] = vec[a[i][j]];
      nxt.insert(aux);
    }
    for (auto vec : nxt) st.insert(vec);
    st.insert(a[i]);
  }

  cout << st.size() << '\n';

  return 0;
}