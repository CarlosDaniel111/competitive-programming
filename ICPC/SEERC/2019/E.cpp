#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

struct Persona {
  ll edad, sobraC, sobraM, faltaC, faltaM, sobra;
};

bool cmp(Persona p1, Persona p2) {
  return p1.edad > p2.edad;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, k, lc, pc, lm, pm, t, d;
  cin >> n >> k;
  cin >> lc >> pc >> lm >> pm;
  cin >> t >> d;
  ll mxdrivers = 0;
  vector<Persona> a(n + 1);
  FOR(i, 1, n + 1) {
    cin >> a[i].edad;
    mxdrivers += (a[i].edad + d >= lm);
  }
  sort(a.begin() + 1, a.end(), cmp);
  FOR(i, 1, n + 1) {
    a[i].sobra = a[i - 1].sobra + min(a[i].edad - 1, d);
    a[i].sobraC = a[i - 1].sobraC + max(0ll, min(a[i].edad - lc, d));
    a[i].sobraM = a[i - 1].sobraM + max(0ll, min(a[i].edad - lm, d));
    a[i].faltaC = a[i - 1].faltaC + max(0ll, lc - a[i].edad);
    a[i].faltaM = a[i - 1].faltaM + max(0ll, lm - a[i].edad);
  }

  ll ans = LLONG_MAX;
  FOR(nc, 0, n + 1) {
    ll drivers = max(nc, n - nc * k + nc);
    if (drivers > mxdrivers) continue;
    ll falta = a[nc].faltaC + a[drivers].faltaM - a[nc].faltaM;
    ll sobra = a[nc].sobraC + a[drivers].sobraM - a[nc].sobraM + a[n].sobra - a[drivers].sobra;
    if (sobra >= falta) {
      ans = min(ans, falta * t + nc * pc + (drivers - nc) * pm);
    }
  }
  if (ans == LLONG_MAX) ans = -1;
  cout << ans << ENDL;

  return 0;
}