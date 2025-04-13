#include <bits/stdc++.h>
using namespace std;
// AC2#
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

void solve() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  vector<bool> h(30, false);
  int i = 0, ans = 0;
  FOR(i, 0, SZ(s)) {
    if (i + (s[i] - 'A') <= n && !h[s[i] - 'A']) {
      ans++;
      i += (s[i] - 'A');
      h[(s[i] - 'A')] = true;
    }
  }
  cout << ans << ENDL;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}