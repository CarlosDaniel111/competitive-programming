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
  SuffixArray(string& s, int lim = 256) : S(s), n(SZ(s) + 1) {  // O(n log n)
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

    FOR(i, 1, n) { rank[SA[i]] = i; }
    for (int i = 0, j; i < n - 1; LCP[rank[i++]] = k)
      for (k &&k--, j = SA[rank[i] - 1]; s[i + k] == s[j + k]; k++);
  }
};

#define NEUT 1000000000
struct STree {
  int n;
  vi st;
  STree(int n) : st(4 * n + 5, NEUT), n(n) {}
  int comb(int x, int y) { return min(x, y); }
  void init(int k, int s, int e, vi& a) {
    if (s + 1 == e) {
      st[k] = a[s];
      return;
    }
    int m = (s + e) / 2;
    init(2 * k + 1, s, m, a);
    init(2 * k + 2, m, e, a);
    st[k] = comb(st[2 * k + 1], st[2 * k + 2]);
  }
  int query(int k, int s, int e, int a, int b) {
    if (a <= s && e <= b) return st[k];
    if (e <= a || s >= b) return NEUT;
    int m = (s + e) / 2;
    return comb(query(2 * k + 1, s, m, a, b), query(2 * k + 2, m, e, a, b));
  }
  void upd(int k, int s, int e, int i, int v) {
    if (e <= i || s > i) return;
    if (s + 1 == e) {
      st[k] = v;
      return;
    }
    int m = (s + e) / 2;
    upd(2 * k + 1, s, m, i, v);
    upd(2 * k + 2, m, e, i, v);
    st[k] = comb(st[2 * k + 1], st[2 * k + 2]);
  }
  int query(int a, int b) { return query(0, 0, n, a, b); }
  void upd(int i, int v) { upd(0, 0, n, i, v); }
  void init(vi& a) { init(0, 0, n, a); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  getline(cin, s);
  int n = SZ(s);
  SuffixArray sa(s);
  vi rsa(n + 1, 0);
  FOR(i, 0, n + 1) { rsa[sa.SA[i]] = i; }

  STree st(n + 5);
  st.init(sa.LCP);
  set<int> ss;
  vi brinco(n, 0);
  FOR(i, 0, n) {
    int curr = rsa[i];
    auto it = ss.lower_bound(curr);
    if (it != ss.end()) {
      brinco[i] = max(brinco[i], st.query(curr + 1, *it + 1));
    }
    if (it != ss.begin()) {
      it--;
      brinco[i] = max(brinco[i], st.query(*it + 1, curr + 1));
    }
    ss.insert(curr);
  }

  vi dp(n + 1, 1e9);
  dp[0] = 0;
  FOR(i, 0, n) {
    dp[i + brinco[i]] = min(dp[i + brinco[i]], dp[i] + 3);
    dp[i + 1] = min(dp[i + 1], dp[i] + 1);
  }
  cout << dp[n] << ENDL;

  return 0;
}