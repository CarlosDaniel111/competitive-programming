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

vi a;
vi QL, QR;
vi ans;
vi izq, der;

void solve(int l, int r, vi id) {
  if (!SZ(id)) return;
  if (l == r) {
    for (auto i : id) ans[i] = a[l];
    return;
  }
  int m = (l + r) / 2;
  izq[m] = a[m];
  ROF(i, m, l) izq[i] = min(a[i], izq[i + 1]);
  der[m + 1] = a[m + 1];
  FOR(i, m + 2, r + 1) der[i] = min(der[i - 1], a[i]);
  vi idl, idr;
  for (auto i : id) {
    int ql = QL[i], qr = QR[i];
    if (ql <= m && m < qr)
      ans[i] = min(izq[ql], der[qr]);
    else {
      if (ql <= m)
        idl.pb(i);
      else
        idr.pb(i);
    }
  }
  solve(l, m, idl);
  solve(m + 1, r, idr);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  a.resize(n), izq.resize(n), der.resize(n);
  FOR(i, 0, n) cin >> a[i];
  QL.resize(q), QR.resize(q);
  FOR(i, 0, q) {
    cin >> QL[i] >> QR[i];
    QL[i]--, QR[i]--;
  }
  vi id(q, 0);
  iota(ALL(id), 0);
  ans.resize(q);
  solve(0, n - 1, id);
  FOR(i, 0, q) { cout << ans[i] << ENDL; }

  return 0;
}