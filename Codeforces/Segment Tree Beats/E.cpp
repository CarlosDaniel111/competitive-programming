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

constexpr ll INF = 2e18;

struct Node {
  ll sum, mx1, mx2, mxcnt, mn1, mn2, mncnt, lazySum = 0, lazyEq = -1,
                                            diffGcd = 0;

  Node(ll v)
      : sum(v),
        mx1(v),
        mn1(v),
        mxcnt(1),
        mncnt(1),
        mx2(-INF),
        mn2(INF),
        lazySum(0),
        lazyEq(-1),
        diffGcd(0) {}
  Node() : lazySum(0), lazyEq(-1), diffGcd(0) {}
};

struct STree {
#define ls (k << 1) + 1
#define rs (k << 1) + 2
#define lp ls, s, m
#define rp rs, m, e

  int n;
  vector<Node> st;

  STree(int n) : n(n), st((n << 2) + 5) {}

  void merge(Node &curr, Node l, Node r) {
    curr.sum = l.sum + r.sum;

    // MAX
    if (l.mx1 == r.mx1) {
      curr.mx1 = l.mx1;
      curr.mxcnt = l.mxcnt + r.mxcnt;
      curr.mx2 = max(l.mx2, r.mx2);
    } else {
      if (l.mx1 > r.mx1) {
        curr.mx1 = l.mx1;
        curr.mxcnt = l.mxcnt;
        curr.mx2 = max(l.mx2, r.mx1);
      } else {
        curr.mx1 = r.mx1;
        curr.mxcnt = r.mxcnt;
        curr.mx2 = max(r.mx2, l.mx1);
      }
    }

    // MIN
    if (l.mn1 == r.mn1) {
      curr.mn1 = l.mn1;
      curr.mncnt = l.mncnt + r.mncnt;
      curr.mn2 = min(l.mn2, r.mn2);
    } else {
      if (l.mn1 < r.mn1) {
        curr.mn1 = l.mn1;
        curr.mncnt = l.mncnt;
        curr.mn2 = min(l.mn2, r.mn1);
      } else {
        curr.mn1 = r.mn1;
        curr.mncnt = r.mncnt;
        curr.mn2 = min(r.mn2, l.mn1);
      }
    }

    // GCD
    /*
    curr.diffGcd = gcd(l.diffGcd, r.diffGcd);
    ll anyL = l.mx2;
    ll anyR = r.mx2;
    if (anyL != -INF && anyL != l.mn1 && anyR != -INF && anyR != r.mn1) {
      curr.diffGcd = gcd(curr.diffGcd, anyL - anyR);
    }
    ll any = -1;
    if (anyL != -INF && anyL != l.mn1)
      any = anyL;
    else if (anyR != INF && anyR != r.mn1)
      any = anyR;
    for (ll val : {l.mn1, l.mx1, r.mn1, r.mx1}) {
      if (val != curr.mn1 && val != curr.mx1) {
        if (any != -1)
          curr.diffGcd = gcd(curr.diffGcd, val - any);
        else
          any = val;
      }
    }
      */

    if ((l.mx2 < (ll)-1e18 || l.mx2 == l.mn1) &&
        (r.mx2 < (ll)-1e18 || r.mx2 == r.mn1)) {
      if (l.mx2 < (ll)-1e18 || r.mx2 < (ll)-1e18 || l.mx1 == r.mx1 ||
          l.mx2 == r.mx2) {
        curr.diffGcd = 0;
        return;
      }
    }

    ll anyValue = 0;
    vector<ll> c = {l.mx1, l.mn1, l.mn2, l.mx2, r.mx2, r.mn2, r.mx1, r.mn1};
    for (ll x : c) {
      if (abs(x) < (ll)1e18 && x != curr.mn1 && x != curr.mx1) {
        anyValue = x;
        break;
      }
    }
    curr.diffGcd = gcd(l.diffGcd, r.diffGcd);
    for (ll x : c) {
      if (abs(x) < (ll)1e18 && x != curr.mn1 && x != curr.mx1) {
        curr.diffGcd = gcd(curr.diffGcd, anyValue - x);
        // cout << x << " " << curr.diffGcd << endl;
      }
    }
  }

  void pull(int k) { merge(st[k], st[ls], st[rs]); }

  void applyEq(int k, int s, int e, ll v) {
    st[k].mn1 = st[k].mx1 = st[k].lazyEq = v;
    st[k].mxcnt = st[k].mncnt = (e - s);
    st[k].mn2 = INF;
    st[k].mx2 = -INF;
    st[k].sum = (e - s) * v;
    st[k].lazySum = st[k].diffGcd = 0;
  }

  void applyAdd(int k, int s, int e, ll v) {
    if (st[k].mn1 == st[k].mx1) {
      applyEq(k, s, e, st[k].mn1 + v);
      return;
    }
    st[k].sum += (e - s) * v;
    st[k].mx1 += v;
    if (st[k].mx2 != -INF) st[k].mx2 += v;
    st[k].mn1 += v;
    if (st[k].mn2 != INF) st[k].mn2 += v;
    st[k].lazySum += v;
  }

  void applyChMin(int k, int s, int e, ll v) {
    if (st[k].mn1 >= v) {
      applyEq(k, s, e, v);
      return;
    }
    if (v >= st[k].mx1) return;
    if (st[k].mn2 == st[k].mx1) st[k].mn2 = v;
    st[k].sum -= (st[k].mx1 - v) * st[k].mxcnt;
    st[k].mx1 = v;
  }

  void applyChMax(int k, int s, int e, ll v) {
    if (st[k].mx1 <= v) {
      applyEq(k, s, e, v);
      return;
    }
    if (v <= st[k].mn1) return;
    if (st[k].mx2 == st[k].mn1) st[k].mx2 = v;
    st[k].sum += (v - st[k].mn1) * st[k].mncnt;
    st[k].mn1 = v;
  }

  void push(int k, int s, int e) {
    int m = (s + e) >> 1;
    if (st[k].lazyEq != -1) {
      applyEq(lp, st[k].lazyEq);
      applyEq(rp, st[k].lazyEq);
      st[k].lazyEq = -1;
      return;
    }

    applyAdd(lp, st[k].lazySum);
    applyAdd(rp, st[k].lazySum);
    st[k].lazySum = 0;

    applyChMin(lp, st[k].mx1);
    applyChMin(rp, st[k].mx1);

    applyChMax(lp, st[k].mn1);
    applyChMax(rp, st[k].mn1);
  }

  void build(int k, int s, int e, vector<ll> &a) {
    if (s + 1 == e) {
      st[k] = Node(a[s]);
      return;
    }
    int m = (s + e) >> 1;
    build(lp, a);
    build(rp, a);
    pull(k);
  }

  ll querySum(int k, int s, int e, int a, int b) {
    if (a <= s && e <= b) return st[k].sum;
    push(k, s, e);
    int m = (s + e) >> 1;
    if (a >= m) return querySum(rp, a, b);
    if (b <= m) return querySum(lp, a, b);
    return querySum(lp, a, b) + querySum(rp, a, b);
  }

  ll queryMax(int k, int s, int e, int a, int b) {
    if (a <= s && e <= b) return st[k].mx1;
    push(k, s, e);
    int m = (s + e) >> 1;
    if (a >= m) return queryMax(rp, a, b);
    if (b <= m) return queryMax(lp, a, b);

    return max(queryMax(lp, a, b), queryMax(rp, a, b));
  }

  ll queryMin(int k, int s, int e, int a, int b) {
    if (a <= s && e <= b) return st[k].mn1;
    push(k, s, e);
    int m = (s + e) >> 1;
    if (a >= m) return queryMin(rp, a, b);
    if (b <= m) return queryMin(lp, a, b);
    return min(queryMin(lp, a, b), queryMin(rp, a, b));
  }

  ll queryGcd(int k, int s, int e, int a, int b) {
    if (a <= s && e <= b) {
      ll res = st[k].diffGcd;
      ll x = st[k].mx2;
      if (x < -1e18 || x == st[k].mn1) x = 0;
      res = gcd(res, st[k].mx1 - x);
      res = gcd(res, x - st[k].mn1);
      res = gcd(res, st[k].mx1);
      return abs(res);
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    if (a >= m) return queryGcd(rp, a, b);
    if (b <= m) return queryGcd(lp, a, b);
    return gcd(queryGcd(lp, a, b), queryGcd(rp, a, b));
  }

  void updEq(int k, int s, int e, int a, int b, ll v) {
    if (a <= s && e <= b) {
      applyEq(k, s, e, v);
      return;
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    if (a < m) updEq(lp, a, b, v);
    if (b > m) updEq(rp, a, b, v);
    pull(k);
  }

  void updAdd(int k, int s, int e, int a, int b, ll v) {
    if (a <= s && e <= b) {
      applyAdd(k, s, e, v);
      return;
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    if (a < m) updAdd(lp, a, b, v);
    if (b > m) updAdd(rp, a, b, v);
    pull(k);
  }

  void updChMin(int k, int s, int e, int a, int b, ll v) {
    if (v >= st[k].mx1) return;
    if (a <= s && e <= b && v > st[k].mx2) {
      applyChMin(k, s, e, v);
      return;
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    if (a < m) updChMin(lp, a, b, v);
    if (b > m) updChMin(rp, a, b, v);
    pull(k);
  }

  void updChMax(int k, int s, int e, int a, int b, ll v) {
    if (v <= st[k].mn1) return;
    if (a <= s && e <= b && v < st[k].mn2) {
      applyChMax(k, s, e, v);
      return;
    }
    push(k, s, e);
    int m = (s + e) >> 1;
    if (a < m) updChMax(lp, a, b, v);
    if (b > m) updChMax(rp, a, b, v);
    pull(k);
  }

  void build(vector<ll> &a) { build(0, 0, n, a); }
  ll querySum(int a, int b) { return querySum(0, 0, n, a, b); }
  ll queryMax(int a, int b) { return queryMax(0, 0, n, a, b); }
  ll queryMin(int a, int b) { return queryMin(0, 0, n, a, b); }
  ll queryGcd(int a, int b) { return queryGcd(0, 0, n, a, b); }
  void updEq(int a, int b, ll v) { updEq(0, 0, n, a, b, v); }
  void updAdd(int a, int b, ll v) { updAdd(0, 0, n, a, b, v); }
  void updChMin(int a, int b, ll v) { updChMin(0, 0, n, a, b, v); }
  void updChMax(int a, int b, ll v) { updChMax(0, 0, n, a, b, v); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n;
  vector<ll> a(n);
  FOR(i, 0, n) cin >> a[i];
  STree st(n);
  st.build(a);
  cin >> q;
  while (q--) {
    ll opc, l, r, x;
    cin >> opc;
    if (opc == 1) {
      cin >> l >> r >> x;
      st.updChMin(l - 1, r, x);
    } else if (opc == 2) {
      cin >> l >> r >> x;
      st.updChMax(l - 1, r, x);
    } else if (opc == 3) {
      cin >> l >> r >> x;
      st.updEq(l - 1, r, x);
    } else if (opc == 4) {
      cin >> l >> r >> x;
      st.updAdd(l - 1, r, x);
    } else if (opc == 5) {
      cin >> l >> r;
      cout << st.querySum(l - 1, r) << ENDL;
    } else if (opc == 6) {
      cin >> l >> r;
      cout << st.queryMin(l - 1, r) << ENDL;
    } else if (opc == 7) {
      cin >> l >> r;
      cout << st.queryMax(l - 1, r) << ENDL;
    } else {
      cin >> l >> r;
      cout << st.queryGcd(l - 1, r) << ENDL;
    }
  }

  return 0;
}