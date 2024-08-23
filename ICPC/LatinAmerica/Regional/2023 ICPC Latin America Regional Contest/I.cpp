#include <bits/stdc++.h>
using namespace std;
// AC2++
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr ll MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

ll modpow(ll a, ll b) {
  ll res = 1;
  a %= MOD;
  while (b) {
    if (b & 1)
      res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}

ll modInverse(ll b) { return modpow(b, MOD - 2) % MOD; }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  string s;
  cin >> s;
  ll n;
  cin >> n;
  vi cnts(26, 0);
  ll ans = 0;
  for (auto c : s) {
    int idx = c - 'a';
    for (int i = idx + 1; i < 26; i++)
      ans = (ans + cnts[i]) % MOD;
    cnts[idx]++;
  }
  n %= MOD;
  ans *= n;
  ans %= MOD;
  ll g = 0;
  FOR(i, 0, 26) {
    FOR(j, i + 1, 26) {
      g += (cnts[i] * cnts[j]) % MOD;
      g %= MOD;
    }
  }
  g *= n;
  g %= MOD;
  g *= (n - 1);
  g %= MOD;
  g *= modInverse(2);
  ans += g;
  ans %= MOD;
  cout << ans << ENDL;

  return 0;
}