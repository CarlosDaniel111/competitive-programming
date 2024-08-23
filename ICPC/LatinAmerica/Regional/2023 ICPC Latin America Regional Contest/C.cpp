#include <bits/stdc++.h>
using namespace std;
// AC2++
using ll = long long;
using ull = unsigned long long;
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

mt19937 mt19937random(std::chrono::system_clock::now().time_since_epoch().count());
ll getRandom(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(mt19937random); }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vi a(n + 5, 0), s(n + 5, 0);
  FOR(i, 2, k + 1) {
    a[i] = getRandom(0, 1e10);
    a[1] -= a[i];
  }
  map<ull, int> mapa;
  mapa[0] = 0;
  int ans = 0;
  FOR(i, 1, n + 1) {
    int x;
    cin >> x;
    s[i] = s[i - 1] + a[x];
    if (!mapa.count(s[i])) {
      mapa[s[i]] = i;
    } else {
      ans = max(ans, i - mapa[s[i]]);
    }
  }
  cout << ans << ENDL;

  return 0;
}