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
  ll n;
  cin >> n;
  vi a(n);
  FOR(i, 0, n) {
    cin >> a[i];
  }
  a.push_back(0);
  sort(ALL(a));
  a.erase(unique(ALL(a)), a.end());
  ll cnt = 0;
  FOR(i, 0, SZ(a) - 1) {
    if (a[i + 1] - a[i] == 1) {
      cnt++;
    } else {
      break;
    }
  }
  if (cnt % 2 == 0) {
    if (cnt != SZ(a) - 1) {
      cout << "Alice" << ENDL;
    } else {
      cout << "Bob" << ENDL;
    }

  } else {
    if (cnt != SZ(a) - 1) {
      cout << "Bob" << ENDL;
    } else {
      cout << "Alice" << ENDL;
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}