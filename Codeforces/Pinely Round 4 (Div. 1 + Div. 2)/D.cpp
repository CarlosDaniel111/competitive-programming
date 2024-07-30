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

ll sieve_size;
vi primes;
void sieve(int n) {
  vector<bool> is_prime(n + 1, 1);

  is_prime[0] = is_prime[1] = 0;
  for (ll p = 2; p <= n; p++) {
    if (is_prime[p]) {
      for (ll i = p * p; i <= n; i += p) is_prime[i] = 0;
      primes.push_back(p);
    }
  }
}

int N = 15;
vi c(N + 1);
vector<vi> g(N + 1);
vi a = {1, 2, 2, 3, 1, 4, 4, 3};
bool back(int pos, int mx) {
  if (pos == N + 1) {
    FOR(i, 1, N + 1) {
      for (auto x : g[i]) {
        if (c[i] == c[x]) {
          return false;
        }
      }
    }
    return true;
  }

  FOR(i, 1, mx) {
    c[pos] = i;
    if (back(pos + 1, mx)) {
      return true;
    }
  }
  return false;
}

void solve() {
  FOR(i, 1, N + 1) {
    for (auto x : primes) {
      if ((i xor x) <= N && (i xor x)) g[i].pb(i xor x);
    }
  }

  FOR(i, 0, N + 1) {
    cout << i << ": ";
    for (auto x : g[i]) {
      cout << x << " ";
    }
    cout << ENDL;
  }
  FOR(i, 0, 10) {
    c.assign(N + 1, 0);
    if (back(1, i)) {
      FOR(i, 1, N + 1) { cout << c[i] << " " << ENDL; }
      return;
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  sieve(N + 10000);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}