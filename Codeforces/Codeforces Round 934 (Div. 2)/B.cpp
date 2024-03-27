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
  int n, k;
  cin >> n >> k;
  vi a(n + 5, 0);
  vi b(n + 5, 0);
  vi repetidos(n + 5, 0);
  FOR(i, 0, n) {
    int x;
    cin >> x;
    a[x] = 1;
  }

  FOR(i, 0, n) {
    int x;
    cin >> x;
    b[x] = 1;
    if (a[x]) {
      repetidos[x] = 1;
    }
  }

  vi ansa, ansb;
  int cnt = 0;
  int res = 0;
  FOR(i, 1, n + 1) {
    if (res == k) break;
    if (a[i] && !b[i]) {
      ansa.pb(i);
      ansa.pb(i);
      res++;
    }
  }

  int res2 = 0;
  FOR(i, 1, n + 1) {
    if (res2 == res) break;
    if (!a[i] && b[i]) {
      ansb.pb(i);
      ansb.pb(i);
      res2++;
    }
  }

  int faltan = (k - res) * 2;
  FOR(i, 1, n + 1) {
    if (!faltan) break;
    if (a[i] && b[i]) {
      ansa.pb(i);
      ansb.pb(i);
      faltan--;
    }
  }

  for (auto x : ansa) {
    cout << x << " ";
  }
  cout << ENDL;

  for (auto x : ansb) {
    cout << x << " ";
  }
  cout << ENDL;
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