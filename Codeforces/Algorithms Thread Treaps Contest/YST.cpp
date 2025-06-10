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

struct STree {
#define ls (k << 1) + 1
#define rs (k << 1) + 2
#define lp ls, s, m
#define rp rs, m, e

  int n;
  vector<int> lazy;
  vi mx0, mx1, pref0, pref1, suff0, suff1, len;

  STree(int n)
      : n(n),
        mx0((n << 2) + 5),
        mx1((n << 2) + 5),
        pref0((n << 2) + 5),
        pref1((n << 2) + 5),
        suff0((n << 2) + 5),
        suff1((n << 2) + 5),
        len((n << 2) + 5),
        lazy((n << 2) + 5) {}

  int merge(int x, int y) { return max(x, y); }

  void pull(int k) {
    mx0[k] = merge(mx0[ls], mx0[rs]);
    mx0[k] = max(mx0[k], suff0[ls] + pref0[rs]);

    mx1[k] = merge(mx1[ls], mx1[rs]);
    mx1[k] = max(mx1[k], suff1[ls] + pref1[rs]);

    pref0[k] = (pref0[ls] == len[ls] ? pref0[ls] + pref0[rs] : pref0[ls]);
    pref1[k] = (pref1[ls] == len[ls] ? pref1[ls] + pref1[rs] : pref1[ls]);

    suff0[k] = (suff0[rs] == len[rs] ? suff0[rs] + suff0[ls] : suff0[rs]);
    suff1[k] = (suff1[rs] == len[rs] ? suff1[rs] + suff1[ls] : suff1[rs]);
  }

  void apply(int k, int s, int e) {
    swap(mx0[k], mx1[k]);
    swap(pref0[k], pref1[k]);
    swap(suff0[k], suff1[k]);
    lazy[k] ^= 1;
  }

  void push(int k, int s, int e) {
    if (lazy[k]) {
      int m = (s + e) >> 1;
      apply(lp);
      apply(rp);
      lazy[k] = 0;
    }
  }

  // Puro 0
  void build(int k, int s, int e) {
    mx0[k] = e - s;
    pref0[k] = e - s;
    suff0[k] = e - s;
    len[k] = e - s;
    if (s + 1 == e) return;
    int m = (s + e) >> 1;
    build(lp);
    build(rp);
    pull(k);
  }

  void upd(int k, int s, int e, int a, int b) {
    if (a <= s && e <= b) {
      apply(k, s, e);
      return;
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    if (a < m) {
      upd(lp, a, b);
    }
    if (b > m) {
      upd(rp, a, b);
    }
    pull(k);
  }

  int get() { return max(mx0[0], mx1[0]); }
  void upd(int a, int b) { upd(0, 0, n, a, b); }
  void build() { build(0, 0, n); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  STree st(n);
  st.build();
  FOR(i, 0, n) {
    char c;
    cin >> c;
    if (c == '1') st.upd(i, i + 1);
  }
  while (q--) {
    int opc, l, r;
    cin >> opc >> l >> r;
    l--;
    st.upd(l, r);
    cout << st.get() << ENDL;
  }

  return 0;
}