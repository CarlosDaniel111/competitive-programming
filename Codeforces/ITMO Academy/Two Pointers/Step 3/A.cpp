#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ll((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define ROF(i, a, b) for (ll i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr ll MOD = 1e9 + 7;
constexpr ll MAXN = 1e5 + 5;
constexpr ll INF = 1e9;
constexpr ll LLINF = 1e18;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll n, p;
  cin >> n >> p;
  vi a(2 * n + 1, 0);
  FOR(i, 1, n + 1) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  vi sum(2 * n + 1, 0);
  FOR(i, 1, 2 * n + 1) {
    sum[i] = sum[i - 1] + a[i];
  }
  ll tot = 0;
  if (sum[n] < p) {
    tot += p / sum[n] * n;
    p %= sum[n];
  }

  ll l = 1, idx = -1;
  ll ans = LLINF, suma = 0;
  FOR(r, 1, n * 2 + 1) {
    suma += a[r];
    while (suma - a[l] >= p) {
      suma -= a[l++];
    }
    if (suma >= p) {
      if (r - l + 1 < ans) {
        ans = r - l + 1;
        idx = l;
      }
    }
  }
  if (idx > n) idx -= n;
  cout << idx << " " << tot + ans << ENDL;

  return 0;
}