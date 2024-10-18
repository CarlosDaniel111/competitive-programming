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

struct DSU {
  vector<int> e;
  int x;
  void init(int n) { e = vi(n, -1), x = n; }
  int size(int x) { return -e[get(x)]; }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    x--;
    return true;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vi> cnt(n, vi(11, 0));
  FOR(i, 0, m) {
    int a, d, k;
    cin >> a >> d >> k;
    a--;
    cnt[a][d] = max(cnt[a][d], k);
  }
  DSU dsu;
  dsu.init(n);
  FOR(i, 0, n) {
    FOR(j, 0, 11) {
      if (cnt[i][j]) {
        dsu.join(i, i + j);
        cnt[i + j][j] = max(cnt[i + j][j], cnt[i][j] - 1);
      }
    }
  }
  cout << dsu.x << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}