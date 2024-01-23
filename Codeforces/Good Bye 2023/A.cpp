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
  ll n, k, tot = 1;
  cin >> n >> k;
  FOR(i, 0, n) {
    ll x;
    cin >> x;
    tot *= x;
  }
  if (2023 % tot == 0) {
    cout << "YES" << ENDL;
    cout << 2023 / tot << " ";
    FOR(i, 1, k) {
      cout << 1 << " ";
    }
    cout << ENDL;
  } else {
    cout << "NO" << ENDL;
  }
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