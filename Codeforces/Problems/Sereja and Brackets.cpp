#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using iii = tuple<int, int, int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

struct STree {
#define ls (k << 1) + 1
#define rs (k << 1) + 2
#define lp ls, s, m
#define rp rs, m, e

  int n;
  vector<iii> st;

  STree(int n) : n(n), st((n << 2) + 5) {}

  iii merge(iii x, iii y) {
    auto [a1, b1, c1] = x;
    auto [a2, b2, c2] = y;
    int t = min(b1, c2);
    return {a1 + a2 + t, b1 + b2 - t, c1 + c2 - t};
  }

  void pull(int k) { st[k] = merge(st[ls], st[rs]); }

  void build(int k, int s, int e, string& a) {
    if (s + 1 == e) {
      if (a[s] == '(')
        st[k] = {0, 1, 0};
      else
        st[k] = {0, 0, 1};
      return;
    }
    int m = (s + e) >> 1;
    build(lp, a);
    build(rp, a);
    pull(k);
  }

  iii query(int k, int s, int e, int a, int b) {
    if (a <= s && e <= b) {
      return st[k];
    }
    int m = (s + e) >> 1;
    if (a >= m) {
      return query(rp, a, b);
    }
    if (b <= m) {
      return query(lp, a, b);
    }
    return merge(query(lp, a, b), query(rp, a, b));
  }

  iii query(int a, int b) { return query(0, 0, n, a, b); }
  void build(string& a) { build(0, 0, n, a); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;
  STree st(SZ(s));
  st.build(s);
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    auto [ans, _, __] = st.query(l, r);
    cout << ans * 2 << ENDL;
  }

  return 0;
}