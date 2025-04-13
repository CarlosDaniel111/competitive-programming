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
  vi a(n);
  FOR(i, 0, n) { cin >> a[i]; }
  if (n == k) {
    ll curr = 1;
    for (ll i = 1; i < n; i += 2) {
      if (a[i] != curr) {
        cout << curr << ENDL;
        return;
      }
      curr++;
    }
    cout << curr << ENDL;
    return;
  }
  ll dentro = n - k + 1;
  set<ll> st;
  FOR(i, 1, dentro + 1) { st.insert(a[i]); }
  if (*st.begin() != 1 or SZ(st) != 1) {
    cout << 1 << ENDL;
    return;
  }
  cout << 2 << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}