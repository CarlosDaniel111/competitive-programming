#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((ll)x.size())
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)

struct FT {
  vector<ll> s;
  FT(ll n) : s(n) {}
  void update(ll pos, ll dif) {
    for (; pos < SZ(s); pos |= pos + 1) {
      s[pos] += dif;
    }
  }
  ll query(ll pos) {
    ll res = 0;
    for (; pos > 0; pos &= pos - 1) {
      res += s[pos - 1];
    }
    return res;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, k;
  cin >> n >> k;
  int tot = (1 << n);
  vector<ll> a(tot);
  FOR(i, 0, tot) { cin >> a[i]; }
  vector<FT> bits;
  FOR(i, 0, n + 1) {
    FT ft((tot) + 5);
    bits.push_back(ft);
  }
  FOR(i, 1, n + 1) {
    int aux = 1 << i;
    FOR(j, 0, aux) { bits[i].update(a[j], 1); }
  }

  FOR(i, 0, 1 << n) {
    ll l = 0, r = n;
    while (l < r) {
      ll mid = (l + r + 1) / 2;
      if ((a[i] >= (1ll << mid) &&
           bits[mid].query(a[i] + 1) + k >= (1ll << mid))) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    cout << l << " ";

    // checar si i cambia de potencia 2**k con respecto a i+1
    if (i == (tot)-1) continue;
    FOR(k, 1, n) {
      int aux = 1 << k;
      if (((i + 1) % (aux)) != 0) {
        break;
      }

      FOR(j, i - (aux) + 1, i + 1) { bits[k].update(a[j], -1); }

      FOR(j, i + 1, i + (aux) + 1) { bits[k].update(a[j], 1); }
    }
  }

  return 0;
}