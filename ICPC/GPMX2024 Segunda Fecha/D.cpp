#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define ALL(x) (x.begin(), x.end())
#define SZ(x) ((int)x.size())
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; i++)
#define ENDL '\n'

constexpr ll MOD = 1e9 + 7;

ll dp[805][14500];
map<int, int> dife, dife0;

ll solve(int n, int diff) {
  if (n == 0) return (diff == 7250);
  ll &ans = dp[n][diff];
  if (ans != -1) return ans;
  ans = 0;

  int aux = n * 9;
  if (aux + diff < 7250 || diff - aux > 7250) return 0;

  for (auto x : dife) {
    ans = (ans + solve(n - 1, diff + x.first) * x.second) % MOD;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  memset(dp, -1, sizeof(dp));

  FOR(i, 0, 10) {
    FOR(j, 0, 10) {
      if (i == j) continue;
      if (i != 0 && j != 0) dife0[i - j]++;
      dife[i - j]++;
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int n;
    ll ans = 0;
    cin >> n;
    for (auto x : dife0) {
      ans = (ans + solve(n - 1, 7250 + x.first) * x.second) % MOD;
    }
    cout << ans << ENDL;
  }
}