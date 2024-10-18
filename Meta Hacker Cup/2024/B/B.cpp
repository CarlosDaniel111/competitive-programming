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

vector<bool> is_prime;
vi primes;

void sieve(int n = 1e7 + 10) {
  is_prime.assign(n + 1, 1);
  is_prime[0] = is_prime[1] = 0;
  for (ll p = 2; p <= n; p++) {
    if (!is_prime[p]) continue;
    for (ll i = p * p; i <= n; i += p) is_prime[i] = 0;
    primes.push_back(p);
  }
}
vi ans, inp;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  inp.resize(t);
  int mx = 0;
  FOR(i, 0, t) {
    cin >> inp[i];
    mx = max(mx, inp[i]);
  }

  sieve(mx + 10);

  ans.assign(mx + 10, 0);
  ans[1] = 0;
  set<int> usados;
  FOR(i, 2, mx + 5) {
    ans[i] = ans[i - 1];
    if (!is_prime[i]) continue;
    for (int p : primes) {
      if (p >= i) break;
      if (is_prime[i - p] && !usados.count(i - p)) {
        usados.insert(i - p);
        ans[i]++;
      }
    }
  }

  FOR(i, 1, t + 1) {
    cout << "Case #" << i << ": ";
    cout << ans[inp[i - 1]] << ENDL;
  }

  return 0;
}