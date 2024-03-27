#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define ROF(i, a, b) for (ll i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll n, k;
  cin >> n >> k;
  vi a(n);
  for (auto &x : a) cin >> x;

  ll l = 0;
  ll ans = 0, num = 0;
  map<ll, ll> mapa;
  FOR(r, 0, n) {
    mapa[a[r]]++;
    if (mapa[a[r]] == 1)
      num++;
    while (num > k) {
      mapa[a[l]]--;
      if (mapa[a[l++]] == 0)
        num--;
    }
    ans += r - l + 1;
  }
  cout << ans << ENDL;

  return 0;
}