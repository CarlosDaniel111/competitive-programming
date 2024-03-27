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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  vi a(n);
  for (auto &x : a) cin >> x;
  ll gcd = 0, ans = INF;
  ll j = 0;
  FOR(i, 0, n) {
    if (a[i] == 1) ans = 1;
    if (ans == 1) break;
    gcd = __gcd(gcd, a[i]);
    if (gcd != 1) continue;
    ll lo = j, hi = i, cnt = a[i];
    while (__gcd(cnt, a[hi - 1]) != 1)
      cnt = __gcd(cnt, a[--hi]);
    j = hi;
    ans = min(ans, i - (j - 1) + 1);
    gcd = cnt;
  }
  if (ans == INF) ans = -1;
  cout << ans << ENDL;

  return 0;
}