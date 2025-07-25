#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using iii = tuple<int, int, int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define Aint(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

int sz;
struct Data {
  int mn;

  Data(int mn) : mn(mn) {}

  Data operator+(Data other) const { return Data(min(mn, other.mn)); }
};

constexpr int INF = 1e9;

const Data NEUT(INF);

struct STree {
#define ls st[k].l
#define rs st[k].r
#define lp ls, s, m
#define rp rs, m, e

  struct Node {
    Data d;
    int l, r, lazy;

    Node(Data d, int l, int r, int lazy) : d(d), l(l), r(r), lazy(lazy) {}

    void apply(int v) {
      if (v > d.mn) {
        d.mn = lazy = v;
      }
    }
  };

  int n, root;
  vector<Node> st;

  void init(int nn) {
    n = nn;
    st.assign(1, Node(Data(0), 0, 0, 0));
  }

  int clone(Node node) {
    st.emplace_back(node.d, node.l, node.r, node.lazy);
    return (int)st.size() - 1;
  }

  bool push(int k) {
    if (!st[k].lazy) {
      return false;
    }
    ls = clone(st[ls]);
    rs = clone(st[rs]);
    st[ls].apply(st[k].lazy);
    st[rs].apply(st[k].lazy);
    st[k].lazy = 0;
    return true;
  }

  void pull(int k) { st[k].d = st[ls].d + st[rs].d; }

  int build(int k, int s, int e) {
    k = clone(st[k]);
    if (s + 1 == e) {
      st[k].d = Data(0);
      return k;
    }
    int m = (s + e) >> 1;
    ls = build(lp);
    rs = build(rp);
    pull(k);
    return k;
  }

  Data query(int k, int s, int e, int a, int b) {
    if (e <= a || s >= b) {
      return NEUT;
    }
    if (a <= s && e <= b) {
      return st[k].d;
    }
    push(k);
    int m = (s + e) >> 1;
    return query(lp, a, b) + query(rp, a, b);
  }

  int upd(int k, int s, int e, int a, int b, int v, bool isClone = false) {
    if (e <= a || s >= b || st[k].d.mn >= v) {
      return k;
    }
    if (!isClone) {
      k = clone(st[k]);
    }
    if (a <= s && e <= b) {
      st[k].apply(v);
      return k;
    }
    bool pushed = push(k);
    int m = (s + e) >> 1;
    ls = upd(lp, a, b, v, pushed);
    rs = upd(rp, a, b, v, pushed);
    pull(k);
    return k;
  }

  int build() { return root = build(0, 0, n); }
  Data query(int k, int a, int b) { return query(k, 0, n, a, b); }
  Data query(int a, int b) { return query(root, 0, n, a, b); }
  int upd(int k, int a, int b, int v) { return root = upd(k, 0, n, a, b, v); }
  int upd(int a, int b, int v) { return root = upd(root, 0, n, a, b, v); }
};
STree stp;
vector<pi> query;

struct Node {
  int l, r, h, s, e;
};

vector<Node> rect;

void solve(int L, int R, vector<iii> &ranges) {
  int prev = stp.root;
  int mid = (L + R) >> 1;
  vector<iii> left, right;
  for (auto [l, r, id] : ranges) {
    if (l <= L && R <= r)
      stp.upd(rect[id].l, rect[id].r, rect[id].h);
    else {
      if (l <= mid) left.pb({l, r, id});
      if (r > mid) right.pb({l, r, id});
    }
  }
  if (L == R) {
    if (query[L].first != -1)
      cout << stp.query(query[L].first, query[L].second).mn << ENDL;
    stp.root = prev;
    return;
  }
  solve(L, mid, left);
  solve(mid + 1, R, right);
  stp.root = prev;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vi addId;
  query.assign(n + 5, {-1, -1});
  vi nums;
  int cnt = 0;
  FOR(i, 0, n) {
    char c;
    cin >> c;
    if (c == '?') {
      int l, r;
      cin >> l >> r;
      nums.pb(l);
      nums.pb(r);
      query[i] = {l, r};
    } else if (c == '+') {
      int l, r, h;
      cin >> l >> r >> h;
      nums.pb(l);
      nums.pb(r);
      rect.pb({l, r, h, i, n});
      addId.pb(cnt++);
    } else {
      int x;
      cin >> x;
      rect[addId[x - 1]].e = i;
    }
  }

  nums.pb(0);
  sort(Aint(nums));
  nums.erase(unique(Aint(nums)), nums.end());
  sz = SZ(nums);
  FOR(i, 0, sz) nums.pb(nums[i]);
  sort(Aint(nums));
  auto get = [&](int x) -> int {
    return lower_bound(Aint(nums), x) - nums.begin();
  };

  // Compresion
  for (auto &[l, r] : query) {
    if (l == -1) continue;
    l = get(l);
    r = get(r);
  }
  for (auto &[l, r, _, s, e] : rect) {
    l = get(l);
    r = get(r);
  }

  sz = SZ(nums) + 10;
  stp.init(sz);
  stp.build();
  vector<iii> ranges;
  FOR(i, 0, SZ(rect)) { ranges.pb({rect[i].s, rect[i].e, i}); }
  solve(0, n - 1, ranges);

  return 0;
}