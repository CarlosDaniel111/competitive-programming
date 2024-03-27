#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

vector<ll> primes;
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

vi primeFactors(ll N) {
  vi factors;
  for (int i = 0; i < (int)primes.size() && primes[i] * primes[i] <= N; ++i) {
    if (N % primes[i] == 0)
      factors.push_back(primes[i]);
    while (N % primes[i] == 0) {
      N /= primes[i];
    }
  }
  if (N != 1) factors.push_back(N);
  return factors;
}

vector<vi> a;

vi mnr, mxl, ans;

bool solve(int l, int r, int padre) {
  if (l > r) return true;
  if (l == r) {
    ans[l] = padre;
    return true;
  }
  for (int i = l, j = r; i <= j; i++, j--) {
    if (mxl[i] < l && mnr[i] > r) {
      if (!solve(l, i - 1, i) || !solve(i + 1, r, i)) {
        // cout << i << " " << l << " " << r << ENDL;
        return false;
      }
      ans[i] = padre;
      return true;
    }

    if (mxl[j] < l && mnr[j] > r) {
      if (!solve(l, j - 1, j) || !solve(j + 1, r, j)) {
        return false;
      }
      ans[j] = padre;
      return true;
    }
  }
  return false;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  sieve(1e5 + 5);
  int n;
  cin >> n;
  a.assign(n, vi());
  ans.assign(n, 0);
  FOR(i, 0, n) {
    int x;
    cin >> x;
    a[i] = primeFactors(x);
  }

  vi pos(1e7, -1);
  mxl.assign(n, -1);
  FOR(i, 0, n) {
    for (auto x : a[i]) {
      mxl[i] = max(mxl[i], pos[x]);
      pos[x] = i;
    }
  }

  mnr.assign(n, n);
  pos.assign(1e7, n);
  ROF(i, n, 0) {
    for (auto x : a[i]) {
      mnr[i] = min(mnr[i], pos[x]);
      pos[x] = i;
    }
  }

  if (!solve(0, n - 1, -1)) {
    cout << "impossible" << ENDL;
    return 0;
  }

  FOR(i, 0, n) {
    cout << ans[i] + 1 << " ";
  }

  return 0;
}