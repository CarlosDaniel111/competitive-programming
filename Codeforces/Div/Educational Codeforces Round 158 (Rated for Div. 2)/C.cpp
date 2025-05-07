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
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define ROF(i, a, b) for (ll i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;
constexpr ll INF = 1e15;
constexpr ll LLINF = 1e18;

void solve() {
  ll n;
  cin >> n;
  vi arr(n);
  ll minimo = INF;
  ll maximo = -1;
  FOR(i, 0, n) {
    cin >> arr[i];
    minimo = min(minimo, arr[i]);
    maximo = max(maximo, arr[i]);
  }
  ll diff = maximo - minimo;
  if (diff == 0) {
    cout << 0 << ENDL;
    return;
  }
  ll aux = log2(diff);
  aux++;
  if (aux > n) {
    cout << aux << ENDL;
    return;
  }
  vi ans;
  // cout << "---------------" << ENDL;
  while (minimo != maximo) {
    // cout << minimo << " " << maximo << ENDL;
    ll aux1 = (minimo + 1) / 2;
    ll aux2 = (maximo + 1) / 2;
    ll aux3 = minimo / 2;
    ll aux4 = maximo / 2;
    ll diff1 = aux2 - aux1;
    ll diff2 = aux4 - aux3;
    if (diff1 < diff2) {
      minimo = aux1;
      maximo = aux2;
      ans.pb(1);
    } else {
      minimo = aux3;
      maximo = aux4;
      ans.pb(0);
    }
  }
  // cout << "---------------" << ENDL;
  cout << SZ(ans) << ENDL;
  for (auto x : ans) {
    cout << x << " ";
  }
  cout << ENDL;
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