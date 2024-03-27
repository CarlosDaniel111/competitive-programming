#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

struct DSU {
  vector<int> e, mn, mx;
  DSU(int n) : e(n, -1), mn(n), mx(n) {
    iota(ALL(mn), 0);
    iota(ALL(mx), 0);
  }
  int size(int x) { return -e[get(x)]; }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  int getmn(int x) { return mn[get(x)]; }
  int getmx(int x) { return mx[get(x)]; }
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b)
      return false;
    if (e[a] > e[b])
      swap(a, b);
    e[a] += e[b];
    mn[a] = min(mn[a], mn[b]);
    mx[a] = max(mx[a], mx[b]);
    e[b] = a;
    return true;
  }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  DSU dsu(n + 5);
  while (m--) {
    string s;
    cin >> s;
    if (s[0] == 'u') {
      int x, y;
      cin >> x >> y;
      dsu.join(x, y);
    } else {
      int x;
      cin >> x;
      cout << dsu.getmn(x) << " " << dsu.getmx(x) << " " << dsu.size(x) << ENDL;
    }
  }

  return 0;
}