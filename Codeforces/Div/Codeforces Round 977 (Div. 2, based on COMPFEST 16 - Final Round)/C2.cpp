#include <bits/stdc++.h>
using namespace std;

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
  int n, m, q;
  cin >> n >> m >> q;
  vi a(n), b(m);
  vector<set<int>> pos(n + 1);
  vi antia(n + 1);
  FOR(i, 0, n) {
    cin >> a[i];
    a[i]--;
    pos[i].insert(m);
    antia[a[i]] = i;
  }
  FOR(i, 0, m) {
    cin >> b[i];
    b[i]--;
    pos[b[i]].insert(i);
  }
  vi first(n + 1);
  FOR(i, 0, n) { first[i] = *pos[a[i]].begin(); }
  int f = 0;
  FOR(i, 0, n - 1) { f += first[i] > first[i + 1]; }
  cout << (f ? "TIDAK" : "YA") << ENDL;

  auto upd = [&](int i) {
    if (i) f -= first[i - 1] > first[i];
    if (i < n - 1) f -= first[i] > first[i + 1];
    first[i] = *pos[a[i]].begin();
    if (i) f += first[i - 1] > first[i];
    if (i < n - 1) f += first[i] > first[i + 1];
  };

  while (q--) {
    int i, v;
    cin >> i >> v;
    i--, v--;
    int ant = b[i];
    pos[ant].erase(i);
    b[i] = v;
    pos[v].insert(i);
    upd(antia[ant]);
    upd(antia[v]);
    cout << (f ? "TIDAK" : "YA") << ENDL;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}