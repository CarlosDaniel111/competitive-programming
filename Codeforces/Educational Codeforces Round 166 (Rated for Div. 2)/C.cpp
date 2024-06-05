#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<long long, long long>;
using vi = vector<long long>;

#define pb push_back
#define SZ(x) ((long long)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (long long i = (long long)a; i < (long long)b; ++i)
#define ROF(i, a, b) \
  for (long long i = (long long)a - 1; i >= (long long)b; --i)
#define ENDL '\n'

void solve() {
  ll n, m;
  cin >> n >> m;
  ll tot = n + m + 1;
  vector<vi> a(tot, vi(2));
  FOR(i, 0, tot) { cin >> a[i][0]; }
  FOR(i, 0, tot) { cin >> a[i][1]; }

  ll malo = -1;
  ll tipoMalo = -1;
  ll ans = 0;
  vi cur(2, 0);
  ll limites[] = {n, m};
  vi tipos(tot, 0);
  FOR(i, 0, tot - 1) {
    ll tipoActual = 0;
    if (a[i][0] < a[i][1]) tipoActual = 1;
    if (cur[tipoActual] == limites[tipoActual]) {
      tipoActual = !tipoActual;
      if (malo == -1) {
        malo = i;
        tipoMalo = !tipoActual;
      }
    }
    tipos[i] = tipoActual;
    ans += a[i][tipoActual];
    cur[tipoActual]++;
  }

  vi res(tot);
  FOR(i, 0, tot - 1) {
    ll val = ans - a[i][tipos[i]];
    if (malo != -1 && i < malo && tipos[i] == tipoMalo) {
      val += a[malo][tipoMalo] - a[malo][!tipoMalo] + a[n + m][!tipoMalo];
    } else {
      val = val + a[n + m][tipos[i]];
    }
    res[i] = val;
  }

  FOR(i, 0, tot - 1) { cout << res[i] << " "; }
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  long long t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}