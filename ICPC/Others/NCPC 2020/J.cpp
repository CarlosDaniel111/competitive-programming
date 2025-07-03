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

struct node {
  ll t, l, r;

  bool operator<(node p) const { return tie(t, l, r) < tie(p.t, p.l, p.r); }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;

  vector<node> a(n);
  ll mnflow = 0;
  ll sum = 0;
  ll aporta = 0;
  FOR(i, 0, n) {
    cin >> a[i].t >> a[i].l >> a[i].r;
    mnflow += a[i].l;
    sum += a[i].l * a[i].t;
    aporta += a[i].r - a[i].l;
  }
  sort(ALL(a));
  ll q;
  cin >> q;
  while (q--) {
    ll temp, flow;
    cin >> temp >> flow;
    ll falta = temp * flow - sum;
    flow -= mnflow;
    if (flow < 0 or flow > aporta) {
      cout << "no" << ENDL;
      continue;
    }
    ll curr = flow;
    ll i = 0;
    ll l = 0;
    while (curr && i < n) {
      ll canAdd = a[i].r - a[i].l;
      l += min(curr, canAdd) * a[i++].t;
      curr -= min(curr, canAdd);
    }
    if (curr) {
      cout << "no" << ENDL;
      continue;
    }
    curr = flow;
    i = n - 1;
    ll r = 0;
    while (curr && i >= 0) {
      ll canAdd = a[i].r - a[i].l;
      r += min(canAdd, curr) * a[i--].t;
      curr -= min(canAdd, curr);
    }

    if (l <= falta && falta <= r) {
      cout << "yes" << ENDL;
    } else {
      cout << "no" << ENDL;
    }
  }

  return 0;
}