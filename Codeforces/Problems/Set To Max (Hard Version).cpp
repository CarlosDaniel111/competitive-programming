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

const int INF = 1e9;

struct Node {
  int mn, mx;
};

struct STree {
#define ls 2 * v + 1
#define rs 2 * v + 2
#define lp ls, tl, tm
#define rp rs, tm, tr
#define NEUT {INF, 0}

  int n;
  vector<Node> st;

  STree(int n) : n(n), st(4 * n) {}

  Node merge(Node a, Node b) { return {min(a.mn, b.mn), max(a.mx, b.mx)}; }

  void build(int v, int tl, int tr, vector<int> &a) {
    if (tl + 1 == tr) {
      st[v] = {a[tl], a[tl]};
      return;
    }
    int tm = (tl + tr) / 2;
    build(lp, a);
    build(rp, a);
    st[v] = merge(st[ls], st[rs]);
  }

  Node query(int v, int tl, int tr, int l, int r) {
    if (tr <= l || r <= tl) return NEUT;
    if (l <= tl && tr <= r) return st[v];
    int tm = (tl + tr) / 2;
    return merge(query(lp, l, r), query(rp, l, r));
  }

  Node query(int l, int r) { return query(0, 0, n, l, r); }
  void build(vector<int> &a) { build(0, 0, n, a); }
};

void solve() {
  int n;
  cin >> n;
  vi a(n), b(n);
  FOR(i, 0, n) {
    cin >> a[i];
    a[i]--;
  }
  FOR(i, 0, n) {
    cin >> b[i];
    b[i]--;
  }

  STree st(n);
  STree st2(n);
  st.build(a);
  st2.build(b);
  vi can(n, 0);
  vi last(n, -1);
  FOR(i, 0, n) {
    last[a[i]] = i;
    if (a[i] == b[i]) {
      can[i] = 1;
      continue;
    }
    if (last[b[i]] == -1) continue;
    Node resa = st.query(last[b[i]], i + 1);
    Node resb = st2.query(last[b[i]], i + 1);
    if (resb.mn == b[i] && resa.mx == a[last[b[i]]]) can[i] = 1;
  }
  last.assign(n, -1);
  ROF(i, n, 0) {
    last[a[i]] = i;
    if (a[i] == b[i]) {
      can[i] = 1;
      continue;
    }
    if (last[b[i]] == -1) continue;
    Node resa = st.query(i, last[b[i]] + 1);
    Node resb = st2.query(i, last[b[i]] + 1);
    if (resb.mn == b[i] && resa.mx == a[last[b[i]]]) can[i] = 1;
  }
  FOR(i, 0, n) {
    if (!can[i]) {
      cout << "NO" << ENDL;
      return;
    }
  }
  cout << "YES" << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}