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

static char buf[450 << 20];
void* operator new(size_t s) {
  static size_t i = sizeof buf;
  assert(s < i);
  return (void*)&buf[i -= s];
}
void operator delete(void*) {}

const int inf = 0;
struct Node {
  Node *l = 0, *r = 0;
  int lo, hi, mset = inf, madd = 0, val = -inf;
  Node(int lo, int hi) : lo(lo), hi(hi) {}  // Large interval of -inf
  Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
    if (lo + 1 < hi) {
      int mid = lo + (hi - lo) / 2;
      l = new Node(v, lo, mid);
      r = new Node(v, mid, hi);
      val = l->val + r->val;
    } else
      val = v[lo];
  }
  int query(int L, int R) {
    if (R <= lo || hi <= L) return -inf;
    if (L <= lo && hi <= R) return val;
    push();
    return l->query(L, R) + r->query(L, R);
  }
  void set(int L, int R, int x) {
    if (R <= lo || hi <= L) return;
    if (L <= lo && hi <= R)
      mset = val = x, madd = 0;
    else {
      push(), l->set(L, R, x), r->set(L, R, x);
      val = l->val + r->val;
    }
  }
  void add(int L, int R, int x) {
    if (R <= lo || hi <= L) return;
    if (L <= lo && hi <= R) {
      if (mset != inf)
        mset += x;
      else
        madd += x;
      val += x;
    } else {
      push(), l->add(L, R, x), r->add(L, R, x);
      val = l->val + r->val;
    }
  }
  void push() {
    if (!l) {
      int mid = lo + (hi - lo) / 2;
      l = new Node(lo, mid);
      r = new Node(mid, hi);
    }
    if (mset != inf)
      l->set(lo, hi, mset), r->set(lo, hi, mset), mset = inf;
    else if (madd)
      l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
  }
};

void solve() {
  int n, d, k;
  cin >> n >> d >> k;

  vi aux(n + 1, 0);
  Node st(aux, 0, SZ(aux));
  FOR(i, 0, k) {
    int l, r;
    cin >> l >> r;
    l--;
    st.add(l, r, 1);
    cout << l << " " << r << ENDL;
  }
  int mn = 1e9, mnd = 0, mx = -1, mxd = 0;
  cout << st.query(0, n) << ENDL;
  FOR(i, 0, n - d + 1) {
    int curr = st.query(i, i + d);
    cout << curr << ENDL;
    if (curr < mn) {
      mn = curr;
      mnd = i + 1;
    }
    if (curr > mx) {
      mx = curr;
      mxd = i + 1;
    }
  }
  cout << mxd << " " << mnd << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}