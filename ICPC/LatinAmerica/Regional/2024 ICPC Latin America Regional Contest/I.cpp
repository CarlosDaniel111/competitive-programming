#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define All(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

constexpr ll INF = 4e18 + 5;
ll nc2(ll n) { return 1ll * n * (n - 1) / 2; }

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
  cin.tie(0)->sync_with_stdio(0);

  ll n, k;
  cin >> n >> k;
  vector<vi> f(n + 1, vi(300, 0));
  f[0][0] = 1;
  ll veces = 0;
  FOR(i, 0, n) {
    ll suma = 0;
    FOR(j, 0, 300) {
      suma += f[i][j];
      if (j > i) suma -= f[i][j - i - 1];
      if (suma < k + 1)
        f[i + 1][j] = suma;
      else
        f[i + 1][j] = k + 1;
    }
  }

  FT ft(n + 5);
  FOR(i, 0, n + 5) ft.update(i, 1);
  ll suma = 0, inv = -1;
  FOR(i, 0, SZ(f[n])) {
    if (suma + f[n][i] >= k) {
      inv = i;
      break;
    }
    suma += f[n][i];
  }
  k -= suma;

  auto get = [&](ll x) -> ll {
    ll pos = ft.lower_bound(x);
    ft.update(pos, -1);
    return pos;
  };

  ROF(i, n + 1, 1) {
    ll curr = 0;
    FOR(j, 0, i) {
      if (inv - j < 0 or inv - j >= SZ(f[i - 1])) continue;
      ll val = f[i - 1][inv - j];
      if (curr + val >= k) {
        cout << get(j + 1) + 1 << " ";
        inv -= j;
        k -= curr;
        break;
      }
      curr += val;
    }
  }

  return 0;
}