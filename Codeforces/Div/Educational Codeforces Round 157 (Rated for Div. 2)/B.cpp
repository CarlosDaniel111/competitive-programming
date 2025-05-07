#include <bits/stdc++.h>
using namespace std;
// AC2++
using ll = long long;
using pi = pair<ll, ll>;
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

ll dist(pi p1, pi p2) {
  return (abs(p1.first - p2.first) + abs(p1.second - p2.second));
}

vector<pi> points;

void solve() {
  int n;
  cin >> n;
  points = vector<pi>(n);
  vi arr(2 * n);
  FOR(i, 0, 2 * n) {
    cin >> arr[i];
  }
  sort(ALL(arr));
  FOR(i, 0, n) {
    points[i] = {arr[i], arr[n + i]};
  }
  /*FOR(i, 0, n) {
    FOR(j, i + 1, n) {
      ll w = dist(points[i], points[j]);
      graph[i][j] = w;
      graph[j][i] = w;
    }
  }*/

  sort(ALL(points));
  ll ans = 0;
  FOR(i, 0, n - 1) {
    ans += dist(points[i], points[i + 1]);
  }
  cout << ans << ENDL;
  FOR(i, 0, n) {
    cout << points[i].first << " " << points[i].second << ENDL;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}