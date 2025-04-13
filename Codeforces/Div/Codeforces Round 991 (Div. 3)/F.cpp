#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

template <class T>
struct SparseTable {
  vector<vector<T>> jmp;
  void init(const vector<T>& V) {
    if (SZ(jmp)) jmp.clear();
    jmp.emplace_back(V);
    for (ll pw = 1, k = 1; pw * 2 <= SZ(V); pw *= 2, ++k) {
      jmp.emplace_back(SZ(V) - pw * 2 + 1);
      FOR(j, 0, SZ(jmp[k]))
      jmp[k][j] = gcd(jmp[k - 1][j], jmp[k - 1][j + pw]);
    }
  }
  T query(int l, int r) {  // [a, b)
    int dep = 31 - __builtin_clz(r - l);
    return gcd(jmp[dep][l], jmp[dep][r - (1 << dep)]);
  }
};

void solve() {
  ll n, q;
  cin >> n >> q;
  vi a(n);
  SparseTable<ll> st;
  FOR(i, 0, n) { cin >> a[i]; }
  if (n == 1) {
    while (q--) {
      ll l, r;
      cin >> l >> r;
      cout << 0 << " ";
    }
    cout << ENDL;
    return;
  }
  vi b(n - 1);
  FOR(i, 0, n - 1) { b[i] = abs(a[i + 1] - a[i]); }
  st.init(b);
  while (q--) {
    ll l, r;
    cin >> l >> r;
    if (r - l == 0) {
      cout << 0 << " ";
      continue;
    }
    cout << st.query(l - 1, r - 1) << " ";
  }
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}