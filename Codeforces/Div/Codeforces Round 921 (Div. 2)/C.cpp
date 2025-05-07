#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
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
  int n, k, m;
  cin >> n >> k >> m;
  string s;
  cin >> s;
  int mask = 0;
  string t = "";
  for (char c : s) {
    mask |= 1 << (c - 'a');
    if (mask == (1 << k) - 1) {
      t += c;
      mask = 0;
      if (SZ(t) == n) break;
    }
  }
  if (SZ(t) == n) {
    cout << "YES" << ENDL;
    return;
  }
  cout << "NO" << ENDL;
  FOR(i, 0, k) {
    if (!(mask & (1 << i))) {
      t += ('a' + i);
      FOR(i, SZ(t), n) {
        t += 'a';
      }
      cout << t << ENDL;
      return;
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}