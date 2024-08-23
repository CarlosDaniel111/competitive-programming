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

constexpr ll MAX = 1e5 + 5, MOD = 1e9 + 7;

bool NAND(ll a, ll b) {
  if (a && b) return 0;
  return 1;
}

vector<tuple<ll, ll, ll>> a;
ll dp[MAX][2][2];

ll solve(ll gate, ll correcto, ll curr) {
  if (gate == 0) return correcto == curr;
  ll &ans = dp[gate][correcto][curr];
  if (ans != -1) return ans;
  auto [le, ri, f] = a[gate];
  ans = 0;
  if (f != -1 && f != curr) return 0;
  FOR(i, 0, 2)
  FOR(j, 0, 2)
  FOR(k, 0, 2)
  FOR(l, 0, 2)
  if (f == -1 && NAND(i, k) == correcto && NAND(j, l) == curr)
    (ans += solve(le, i, j) * solve(ri, k, l) % MOD) %= MOD;
  else if (f != -1 && NAND(i, k) == correcto)
    (ans += solve(le, i, j) * solve(ri, k, l) % MOD) %= MOD;

  return ans % MOD;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;
  a.resize(n + 1);
  FOR(i, 1, n + 1) {
    ll l, r, f;
    cin >> l >> r >> f;
    a[i] = {l, r, f};
  }

  memset(dp, -1, sizeof(dp));

  cout << (solve(1, 0, 1) + solve(1, 1, 0)) % MOD << ENDL;

  return 0;
}