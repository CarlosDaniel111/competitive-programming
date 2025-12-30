#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

struct node {
  int a, b, c;
  bool operator<(node o) const {
    if (a != o.a) return a < o.a;
    if (b != o.b) return b < o.b;
    return c < o.c;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<node> a(n);
  FOR(i, 0, n) { cin >> a[i].a >> a[i].b >> a[i].c; }
  sort(ALL(a));
  vi dp(n, 1);
  FOR(i, 0, n) {
    FOR(j, 0, i) {
      if (a[j].a < a[i].a && a[j].b < a[i].b && a[j].c < a[i].c) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  cout << *max_element(ALL(dp)) << ENDL;

  return 0;
}