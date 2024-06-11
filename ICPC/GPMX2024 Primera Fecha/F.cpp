#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

struct SuffixArray {
  vi SA, LCP;
  string S;
  int n;
  SuffixArray(string &s, int lim = 256) : S(s), n(SZ(s) + 1) {  // O(n log n)
    int k = 0, a, b;
    vi x(ALL(s) + 1), y(n), ws(max(n, lim)), rank(n);
    SA = LCP = y, iota(ALL(SA), 0);

    // Calcular SA
    for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
      p = j, iota(ALL(y), n - j);
      FOR(i, 0, n) {
        if (SA[i] >= j) y[p++] = SA[i] - j;
      }
      fill(ALL(ws), 0);
      FOR(i, 0, n) { ws[x[i]]++; }
      FOR(i, 1, lim) { ws[i] += ws[i - 1]; }
      for (int i = n; i--;) SA[--ws[x[y[i]]]] = y[i];
      swap(x, y), p = 1, x[SA[0]] = 0;
      FOR(i, 1, n) {
        a = SA[i - 1];
        b = SA[i], x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
      }
    }
  }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  ll n2 = n * 4 + 1;
  string S = " " + t + t + "{" + s + s;
  SuffixArray sa(S);
  ll ans = 0, tmp = 0;
  for (int i = n2; i >= 1; i--) {
    if (sa.SA[i] >= 2 * n + 2 && sa.SA[i] <= 3 * n + 1) ans += tmp;
    if (sa.SA[i] >= 1 && sa.SA[i] <= n) tmp++;
  }
  cout << ans << ENDL;

  return 0;
}