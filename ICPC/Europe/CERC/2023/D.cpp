#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

struct Sheet {
  ll d, tfast, tslow;
  bool operator<(Sheet o) const { return tslow < o.tslow; }
  bool operator==(Sheet o) const { return tslow == o.tslow; }
};

constexpr ll MAXL = 3e5 + 5;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, q;
  cin >> n >> q;
  vector<Sheet> a(n);
  FOR(i, 0, n) { cin >> a[i].d >> a[i].tfast >> a[i].tslow; }
  sort(ALL(a));

  vi suffmx(n + 1, 0);
  vi suffd(n + 1, 0);
  ROF(i, n, 0) {
    suffmx[i] = max(suffmx[i + 1], a[i].tfast);
    suffd[i] = suffd[i + 1] + a[i].d;
  }

  bitset<MAXL> dp;
  dp.set(0);
  ll sum = 0;
  vi best(n + 1);
  best[0] = 0;
  for (ll i = 0; i < n; i++) {
    sum += a[i].d;
    dp |= dp << a[i].d;
    best[i + 1] = dp._Find_next((sum + 1) / 2);
  }

  while (q--) {
    ll L;
    cin >> L;
    auto can = [&](ll time) -> bool {
      Sheet aux = {0, 0, time};
      ll cntslow = upper_bound(ALL(a), aux) - a.begin();
      // el tiempo rapido del resto es mayor a time
      if (suffmx[cntslow] > time) return false;
      ll sobra = L - suffd[cntslow];
      return sobra >= best[cntslow];
    };
    ll l = 0, r = 1e9 + 5;
    while (l < r) {
      ll mid = (l + r) / 2;
      if (can(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    if (l == 1e9 + 5) l = -1;
    cout << l << ENDL;
  }

  return 0;
}