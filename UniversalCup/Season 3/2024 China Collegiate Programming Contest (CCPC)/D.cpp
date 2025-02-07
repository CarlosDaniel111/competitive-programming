#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

constexpr ll MOD = 998244353, MAX = 1050;
ll n;

int pop[MAX], popTo[MAX], push[MAX], pushTo[MAX];
vector<vector<pi>> dp;
int vis[MAX][MAX];

pi solve(ll u, ll a) {
  if (vis[u][a]) {
    cout << -1 << ENDL;
    exit(0);
  }

  pi &ans = dp[u][a];
  if (ans.first != -1) return ans;

  // HALT Y FUGA
  if (pop[u] == -1 && a == 0) {
    return (ans = {1, -1});
  }

  // POP
  if (pop[u] == a) {
    return (ans = {1, popTo[u]});
  }

  vis[u][a] = 1;
  pi sig = solve(pushTo[u], push[u]);
  pi elim = solve(sig.second, a);
  vis[u][a] = 0;
  return (ans = {(sig.first + elim.first + 1) % MOD, elim.second});
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;
  dp.assign(MAX, vector<pi>(MAX, {-1, -1}));

  FOR(i, 1, n + 1) {
    string s;
    cin >> s;
    if (s[0] == 'H') {
      string p, g;
      cin >> p >> push[i] >> g >> pushTo[i];
      pop[i] = -1;
    } else {
      string g1, p, g2, pg;
      cin >> pop[i] >> g1 >> pg >> p >> push[i] >> g2 >> pushTo[i];
      popTo[i] = stoll(pg);
    }
  }
  cout << solve(1, 0).first % MOD << ENDL;

  return 0;
}