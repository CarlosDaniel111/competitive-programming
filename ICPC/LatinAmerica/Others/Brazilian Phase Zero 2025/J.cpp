#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct STree {
  #define ls 2 * v + 1
  #define rs 2 * v + 2
  #define lp ls, tl, tm
  #define rp rs, tm, tr
  #define NEUT -1

  int n;
  vector<ll> st;
  
  STree (int n) : n(n), st(4*n) {}

  void upd(int v, int tl, int tr, int i, ll val) {
    if (tl + 1 == tr) { st[v] = val; return; }
    int tm = (tl + tr) / 2;
    if (i < tm) upd(lp, i, val);
    else upd(rp, i, val);
    st[v] = min(st[ls], st[rs]);
  }

  int query(int v, int tl, int tr, int l, int r, ll x) {
    if (tr <= l || r <= tl || st[v] >= x) return NEUT;
    if (tl + 1 == tr) return tl;
    int tm = (tl + tr) / 2;
    int ql = query(lp, l, r, x);
    return ql != -1 ? ql : query(rp, l, r, x);
  }

  void upd(int i, ll val) {
    upd(0, 0, n, i, val);
  }
  int query(int l, int r, ll x) {
    return query(0, 0, n, l, r, x);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  STree st(2 * n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    st.upd(i, a[i] - ll(i) * k);
    st.upd(i + n, a[i] - ll(i + n) * k);
  }

  for (int i = 0; i < n; ++i) {
    ll x = a[i] - ll(i) * k;
    ll bi = st.query(i, i + n + 1, x) % n + 1;
    cout << bi << " \n"[i == n - 1];
  }

  return 0;
}