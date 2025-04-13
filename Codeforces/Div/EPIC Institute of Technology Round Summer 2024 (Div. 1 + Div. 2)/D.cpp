#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

vi frec;
vector<vi> dp;

int solve(int idx, int f) {
  if (idx == SZ(frec)) return 0;
  int &ans = dp[idx][f];
  if (ans != -1) return ans;

  ans = 0;

  if (f >= frec[idx]) {
    ans = max(ans, solve(idx + 1, f - frec[idx]) + 1);
  }
  ans = max(ans, solve(idx + 1, f + 1));

  return ans;
}

void solve() {
  int n;
  cin >> n;
  vi a(n);
  FOR(i, 0, n) cin >> a[i];
  map<int, int> mapa;
  FOR(i, 0, n) mapa[a[i]]++;
  frec.clear();
  for (auto [num, f] : mapa) {
    frec.pb(f);
  }
  dp.assign(n + 1, vi(n + 1, -1));
  cout << SZ(frec) - solve(1, 1) << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}