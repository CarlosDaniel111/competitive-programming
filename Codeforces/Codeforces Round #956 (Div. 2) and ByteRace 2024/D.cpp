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

void solve() {
  int n;
  cin >> n;
  vi a(n), b(n);
  FOR(i, 0, n) cin >> a[i];
  FOR(i, 0, n) cin >> b[i];
  vi aa(a), bb(b);
  sort(ALL(aa));
  sort(ALL(bb));
  FOR(i, 0, n) {
    if (aa[i] != bb[i]) {
      cout << "NO" << ENDL;
      return;
    }
  }

  map<int, int> toA, toB;
  FOR(i, 0, n) {
    toB[b[i]] = i;
    toA[a[i]] = i;
  }

  auto change = [](int i, int j, vi &v, map<int, int> &to) -> void {
    swap(v[i], v[j]);
    swap(to[v[i]], to[v[j]]);
  };

  FOR(i, 0, n - 2) {
    if (a[i] == b[i]) continue;
    int pos = toB[a[i]];

    if (pos != n - 1) {
      change(i, pos, b, toB);
      change(i + 1, pos + 1, a, toA);

      continue;
    }

    change(n - 1, n - 2, b, toB);
    change(i + 1, i + 2, a, toA);

    change(i, pos - 1, b, toB);
    change(i + 1, pos, a, toA);
  }

  if (a[n - 1] == b[n - 1]) {
    cout << "YES" << ENDL;
  } else {
    cout << "NO" << ENDL;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}