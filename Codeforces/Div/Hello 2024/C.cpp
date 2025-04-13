#include <bits/stdc++.h>
using namespace std;
// AC2#
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ll((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define ROF(i, a, b) for (ll i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr ll MOD = 1e9 + 7;
constexpr ll MAXN = 1e5 + 5;
constexpr ll INF = 1e9;
constexpr ll LLINF = 1e18;

void solve() {
  ll n;
  cin >> n;
  vi a(n);
  for (auto &x : a) cin >> x;
  ll top1 = -1, top2 = INF, ans = 0;
  top1 = a[0];
  FOR(i, 1, n) {
    if (a[i] > top1) {
      if (top2 == INF) {
        top2 = a[i];
        continue;
      }
      if (a[i] > top2) {
        if (top1 < top2) {
          top1 = a[i];
          ans++;
        } else {
          top2 = a[i];
          ans++;
        }
      } else {
        top2 = a[i];
      }
    } else {
      if (top2 >= a[i] && top2 < top1) {
        top2 = a[i];
      } else {
        top1 = a[i];
      }
    }
  }
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}