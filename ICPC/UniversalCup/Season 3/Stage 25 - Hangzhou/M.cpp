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

void solve() {
  ll n, k;
  cin >> n >> k;
  vi a(n + 1);
  set<ll> aux;
  FOR(i, 1, n + 1) {
    cin >> a[i];
    aux.insert(a[i]);
  }
  if (SZ(aux) == 1) {
    cout << k << " " << k * (k + 1) / 2 << ENDL;
    return;
  }

  vi ls(n + 1, 0), rs(n + 1, 0), stk(n + 1, 0);
  ll top = 0;
  for (ll i = 1; i <= n; ++i) {
    ls[i] = rs[i] = 0;
    while (top && a[stk[top]] >= a[i]) {
      ls[i] = stk[top--];
    }
    if (top) rs[stk[top]] = i;
    stk[++top] = i;
  }

  vector<pi> b;
  FOR(i, 1, n + 1) {
    ll l = ls[i], r = rs[i];
    if (l && a[l] != a[i]) {
      b.pb({a[l] - a[i], a[i]});
    }
    if (r && a[r] != a[i]) {
      b.pb({a[r] - a[i], a[i]});
    }
  }
  sort(ALL(b));
  auto [x, y] = b[0];
  vi ans, pos;
  for (ll i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      ll cand = i - y;
      if (cand >= 1 && cand <= k) pos.pb(cand);
      if (x / i != i) {
        cand = x / i - y;
        if (cand >= 1 && cand <= k) pos.pb(cand);
      }
    }
  }
  b.erase(b.begin());

  auto can = [&](int x) -> bool {
    for (auto [diff, num] : b) {
      if (diff % (x + num) != 0) return false;
    }
    return true;
  };

  for (auto p : pos) {
    if (can(p)) ans.pb(p);
  }

  cout << SZ(ans) << " " << accumulate(ALL(ans), 0ll) << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}