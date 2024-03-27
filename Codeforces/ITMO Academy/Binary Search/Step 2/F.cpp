#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

string s, t;
int n;
vi a;
bool good(ll x) {
  string s2(s);
  FOR(i, 0, x) {
    s2[a[i] - 1] = '*';
  }
  int cursor = 0;
  for (char c : t) {
    while (cursor < n && s2[cursor] != c) {
      cursor++;
    }
    if (cursor >= n) {
      return false;
    }
    cursor++;
  }
  return true;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> s >> t;
  n = SZ(s);
  a.resize(n);
  FOR(i, 0, n) {
    cin >> a[i];
  }

  ll l = 0, r = n;
  while (l < r - 1) {
    ll mid = (l + r) / 2;
    if (good(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << l << ENDL;

  return 0;
}