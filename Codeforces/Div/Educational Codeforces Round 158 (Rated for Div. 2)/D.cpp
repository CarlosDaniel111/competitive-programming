#include <bits/stdc++.h>
using namespace std;
// AC2#
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;

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
  ll n;
  cin >> n;
  vi arr(n), arr1(n), arr2(n);
  FOR(i, 0, n) {
    cin >> arr[i];
  }
  FOR(i, 0, n) {
    arr1[i] = arr[i] + i;
    arr2[n - 1 - i] = arr[n - 1 - i] + i;
  }
  vi prefixRight(n);
  prefixRight[n - 1] = 0;
  FOR(i, 0, n - 1) {
    prefixRight[n - i - 1] = max(prefixRight[n - i], arr1[n - i - 1]);
  }
  vi prefixLeft(n);
  prefixLeft[0] = 0;
  FOR(i, 1, n) {
    prefixLeft = max(prefixLeft[i - 1], arr2[i]);
  }

  ll peor;
  FOR(i, 0, n) {
    ll aux = prefixRight[i] + i - 1;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  while (t--)
    solve();

  return 0;
}