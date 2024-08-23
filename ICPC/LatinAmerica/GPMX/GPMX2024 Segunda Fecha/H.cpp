#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

struct FT {
  vector<ll> s;
  FT(ll n) : s(n) {}
  void update(ll pos, ll dif) {  // a[pos] += dif
    for (; pos < SZ(s); pos |= pos + 1) s[pos] += dif;
  }
  ll query(ll pos) {  // sum of values in [0, pos)
    ll res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
    return res;
  }
  ll lower_bound(ll sum) {  // min pos st sum of [0, pos] >= sum
    // Returns n if no sum is >= sum, or -1 if empty sum is.
    if (sum <= 0) return -1;
    ll pos = 0;
    for (ll pw = 1 << 25; pw; pw >>= 1)
      if (pos + pw <= SZ(s) && s[pos + pw - 1] < sum)
        pos += pw, sum -= s[pos - 1];
    return pos;
  }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll n, r, c;
  cin >> n >> r >> c;
  r--, c--;
  FT ft(n);
  FOR(i, 1, n + 1) { ft.update(i, 1); }
  ll s1 = 0, s2 = n - 1, vivos = n;
  set<ll> ans;
  while (vivos > 2) {
    s1 = (s1 + r) % vivos;
    s2 = (s2 - c + (vivos * 1000005)) % vivos;
    ll x = ft.lower_bound(s1 + 1), y = ft.lower_bound(s2 + 1);
    if (x == y) {
      ft.update(x, -1);
      vivos--;
      ans.insert(x);

    } else {
      ft.update(x, -1);
      ft.update(y, -1);
      vivos -= 2;
      if (x < y) {
        s2--;
      } else {
        s1--;
      }
    }
    s1 = (s1 + vivos) % vivos;
    s2 = (s2 - 1 + vivos) % vivos;
  }
  ans.insert(ft.lower_bound(1));
  if (vivos == 2) {
    ans.insert(ft.lower_bound(2));
  }
  for (auto x : ans) {
    cout << x << " ";
  }
  cout << ENDL;

  return 0;
}