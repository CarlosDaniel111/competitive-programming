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

  ll n, m, s, A, B;
  cin >> n >> m >> s >> A >> B;
  vi a(n);
  for (auto &x : a) cin >> x;
  vi b(m);
  for (auto &x : b) cin >> x;

  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());
  ll r = min(n, s / A) - 1, peso = (r + 1) * A;
  ll ans = 0;
  FOR(i, 0, r + 1)
  ans += a[i];
  ll actual = ans;
  FOR(l, 0, min(m, s / B)) {
    actual += b[l];
    peso += B;
    while (peso > s) {
      peso -= A;
      actual -= a[r--];
    }
    ans = max(ans, actual);
  }
  cout << ans << ENDL;

  return 0;
}