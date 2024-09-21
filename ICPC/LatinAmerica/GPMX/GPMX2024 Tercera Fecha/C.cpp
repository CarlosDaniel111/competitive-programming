#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

struct SuffixArray {
  vector<int> SA, LCP;
  vector<int> S;
  ll n;
  SuffixArray(vector<int> &s, ll lim = 1e5 + 5) : S(s), n(SZ(s) + 1) {
    ll k = 0, a, b;
    vector<int> x(ALL(s)), y(n), ws(max(n, lim)), rank(n);
    x.pb(0);
    SA = LCP = y, iota(ALL(SA), 0);

    // Calcular SA
    for (ll j = 0, p = 0; p < n; j = max(1ll, j * 2), lim = p) {
      p = j, iota(ALL(y), n - j);
      FOR(i, 0, n) {
        if (SA[i] >= j) y[p++] = SA[i] - j;
      }
      fill(ALL(ws), 0);
      FOR(i, 0, n) { ws[x[i]]++; }
      FOR(i, 1, lim) { ws[i] += ws[i - 1]; }
      for (ll i = n; i--;) SA[--ws[x[y[i]]]] = y[i];
      swap(x, y), p = 1, x[SA[0]] = 0;
      FOR(i, 1, n) {
        a = SA[i - 1];
        b = SA[i], x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
      }
    }

    // Calcular LCP (longest common prefix)
    FOR(i, 1, n) { rank[SA[i]] = i; }
    for (ll i = 0, j; i < n - 1; LCP[rank[i++]] = k)
      for (k &&k--, j = SA[rank[i] - 1]; s[i + k] == s[j + k]; k++);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;
  vector<int> a(n);
  FOR(i, 0, n) { cin >> a[i]; }
  SuffixArray sa(a);

  ll ans = 0;
  map<ll, ll> lcps;
  ll curr = 0;
  ROF(i, n + 1, 0) {
    ll quito = 0;
    for (auto it = lcps.upper_bound(sa.LCP[i]); it != lcps.end(); it++)
      quito += it->second, curr -= it->second * it->first;
    lcps.erase(lcps.upper_bound(sa.LCP[i]), lcps.end());
    lcps[sa.LCP[i]] += quito + 1;
    curr += (quito + 1) * sa.LCP[i];
    ans += curr;
  }
  ans = ans * 2 + n * (n + 1) / 2;
  ll de = n * n;
  ll g = gcd(de, ans);
  cout << ans / g << "/" << de / g << ENDL;

  return 0;
}