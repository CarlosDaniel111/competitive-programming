#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ll((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define ROF(i, a, b) for (ll i = (a) - 1; i >= (b); --i)
#define ENDL '\n'

constexpr ll MOD = 1e9 + 7;
constexpr ll MAXN = 1e5 + 5;
constexpr ll INF = 1e9;
constexpr ll LLINF = 1e18;

struct SuffixArray {
  vi SuffixArr, lcp;
  string S;
  ll n;
  SuffixArray(string &s, ll lim = 256) : S(s), n(SZ(s) + 1) {  // O(n log n)
    ll k = 0, a, b;
    vi x(ALL(s) + 1), y(n), ws(max(n, lim)), rank(n);
    SuffixArr = lcp = y, iota(ALL(SuffixArr), 0);

    // Calcular SuffixArr
    for (ll j = 0, p = 0; p < n; j = max(1ll, j * 2), lim = p) {
      p = j, iota(ALL(y), n - j);
      FOR(i, 0, n) {
        if (SuffixArr[i] >= j) y[p++] = SuffixArr[i] - j;
      }
      fill(ALL(ws), 0);
      FOR(i, 0, n) { ws[x[i]]++; }
      FOR(i, 1, lim) { ws[i] += ws[i - 1]; }
      for (ll i = n; i--;) SuffixArr[--ws[x[y[i]]]] = y[i];
      swap(x, y), p = 1, x[SuffixArr[0]] = 0;
      FOR(i, 1, n) {
        a = SuffixArr[i - 1];
        b = SuffixArr[i],
        x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
      }
    }

    // Calcular lcp (longest common prefix)
    FOR(i, 1, n) { rank[SuffixArr[i]] = i; }
    for (ll i = 0, j; i < n - 1; lcp[rank[i++]] = k)
      for (k &&k--, j = SuffixArr[rank[i] - 1]; s[i + k] == s[j + k]; k++);
  }

  ll lower(string &sub) {
    ll l = 0, r = n - 1;
    while (l < r) {
      ll mid = (l + r) / 2;
      ll res = S.compare(SuffixArr[mid], SZ(sub), sub);
      (res >= 0) ? r = mid : l = mid + 1;
    }
    return l;
  }

  ll upper(string &sub) {
    ll l = 0, r = n - 1;
    while (l < r) {
      ll mid = (l + r) / 2;
      ll res = S.compare(SuffixArr[mid], SZ(sub), sub);
      (res > 0) ? r = mid : l = mid + 1;
    }
    if (S.compare(SuffixArr[r], SZ(sub), sub) != 0) --r;
    return r;
  }

  bool subStringSearch(string &sub) {  // O(|sub| log n)
    ll L = lower(sub);
    if (S.compare(SuffixArr[L], SZ(sub), sub) != 0) return 0;
    return 1;
  }

  ll countSubString(string &sub) {  // O(|sub| log n)
    return upper(sub) - lower(sub) + 1;
  }

  ll countDistinctSubstring() {  // O(n)
    ll result = 0;
    FOR(i, 1, n) { result += ll(n - SuffixArr[i] - 1 - lcp[i]); }
    return result;
  }

  string longestCommonSubstring(ll lenS, ll lenT) {  // O(n)
    ll maximo = -1, indice = -1;
    FOR(i, 2, n) {
      if ((SuffixArr[i] > lenS && SuffixArr[i - 1] < lenS) ||
          (SuffixArr[i] < lenS && SuffixArr[i - 1] > lenS)) {
        if (lcp[i] > maximo) {
          maximo = lcp[i];
          indice = SuffixArr[i];
        }
      }
    }
    return S.substr(indice, maximo);
  }

  ll solve() {
    ll he[n];
    FOR(i, 1, n) { he[i - 1] = lcp[i]; }
    ll ans = 0;
    stack<pair<ll, ll>> st;
    he[n - 1] = 0;
    FOR(i, 0, n) {
      ll ne = he[i], pos = i;
      while (!st.empty() && st.top().first >= ne) {
        ll res = i - st.top().second;
        pos = st.top().second;
        ll nn = st.top().first;
        st.pop();
        ll nw = st.empty() ? 0 : st.top().first;
        if (nn > ne) ans += ll(res * (res + 1) / 2 * (nn - max(nw, ne)));
      }
      st.emplace(ne, pos);
    }
    return ans;
  }

  void prllLCP() {
    FOR(i, 0, n) { cout << lcp[i] << " "; }
    cout << ENDL;
  }
};

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  string s;
  cin >> s;
  SuffixArray SA(s);
  // SA.prllLCP();
  ll n = SZ(s);
  ll ans = ll(n * (n + 1) / 2);

  ans += ll(SA.solve());
  cout << ans << ENDL;
  return 0;
}