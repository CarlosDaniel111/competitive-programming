#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve() {
  ll n, k;
  cin >> n >> k;
  ll piratas = n;
  ll rondas = 0;

  while (piratas >= 1) {
    ll avance = (piratas + k - 1) / k;
    ll veces = (piratas - (avance - 1) * k + avance - 1) / avance;
    rondas += veces;
    piratas -= avance * veces;
    if (piratas == 0) rondas--;
  }
  ll ans = 1;
  while (rondas) {
    ll avance = (ans + k - 2) / (k - 1);
    ll veces = ((k - 1) * avance - ans) / avance + 1;
    if (veces > rondas) veces = rondas;
    rondas -= veces;
    ans += avance * veces;
  }
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}