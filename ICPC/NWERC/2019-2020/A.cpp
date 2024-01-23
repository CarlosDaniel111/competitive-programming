#include <bits/stdc++.h>
using namespace std;

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
constexpr int MAXN = 3e5 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

ll rk[MAXN], points[MAXN], cnt[MAXN], pre[MAXN], now[MAXN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  cnt[1] = n;
  FOR(i, 1, n + 1) {
    rk[i] = m, points[i] = 1;
  }
  FOR(i, 1, m + 1) {
    int k;
    cin >> k;
    while (k--) {
      ll x;
      cin >> x;
      rk[x] += now[points[x]] - pre[x];
      now[points[x]] += m - i + 1;
      cnt[points[x]]--;
      points[x]++;
      rk[x] -= cnt[points[x]] * (m - i + 1);
      pre[x] = now[points[x]];
      cnt[points[x]]++;
    }
  }
  FOR(i, 1, n + 1) {
    rk[i] += now[points[i]] - pre[i];
    cout << setprecision(10) << fixed;
    cout << double(rk[i]) / double(m) << ENDL;
  }

  return 0;
}