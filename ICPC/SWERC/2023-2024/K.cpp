#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

struct FT {
  vector<ll> s;
  FT(int n) : s(n) {}
  void update(int pos, ll dif) {  // a[pos] += dif
    for (; pos < SZ(s); pos |= pos + 1) s[pos] += dif;
  }
  ll query(int pos) {  // sum of values in [0, pos)
    ll res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
    return res;
  }
  int lower_bound(ll sum) {  // min pos st sum of [0, pos] >= sum
    // Returns n if no sum is >= sum, or -1 if empty sum is.
    if (sum <= 0) return -1;
    int pos = 0;
    for (int pw = 1 << 25; pw; pw >>= 1)
      if (pos + pw <= SZ(s) && s[pos + pw - 1] < sum)
        pos += pw, sum -= s[pos - 1];
    return pos;
  }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; i += 2) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i += 2) {
    cin >> a[i];
  }
  FT ft(n + 5);
  FOR(i, 1, n + 1) {
    ft.update(i, 1);
  }
  vi ans1, ans2;
  FOR(i, 0, n) {
    int pos = ft.lower_bound(a[i]);
    if (i & 1)
      ans2.pb(pos);
    else
      ans1.pb(pos);
    ft.update(pos, -1);
  }
  for (auto x : ans1) {
    cout << x << " ";
  }
  cout << ENDL;

  for (auto x : ans2) {
    cout << x << " ";
  }
  cout << ENDL;

  return 0;
}