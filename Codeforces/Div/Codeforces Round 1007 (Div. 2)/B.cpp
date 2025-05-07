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

set<ll> st;

void solve() {
  ll n;
  cin >> n;
  if (st.count(n)) {
    cout << -1 << ENDL;
    return;
  }
  FOR(i, 1, n + 1) {
    if (st.count(i)) {
      cout << i + 1 << " " << i << " ";
      i++;
      continue;
    }
    cout << i << " ";
  }
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  FOR(i, 1, 500001) {
    ll curr = i * (i + 1) / 2;
    ll r = sqrt(curr);
    if (r * r == curr) {
      st.insert(i);
    }
  }

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}