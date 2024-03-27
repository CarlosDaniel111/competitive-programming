#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  vi a(n);
  ll l = 0, r = 0;
  FOR(i, 0, n) {
    cin >> a[i];
    r = max(r, a[i]);
  }

  auto can = [&](ll x) -> bool {
    FOR(i, 0, n) {
      if (x >= a[i]) {
        bool paso = false;
        ll cnt = 0;
        ll l = i - 1, r = i + 1;
        ll sum = a[i] + x;
        if (l == -1) l = n - 1;
        if (r == n) {
          r = 0;
          paso = true;
        }

        while (a[l] <= sum || a[r] <= sum) {
          if (a[l] <= sum) {
            cnt++;
            sum += a[l];
            l--;
            if (l == -1) l = n - 1;
          }
          if (a[r] <= sum) {
            cnt++;
            sum += a[r];
            r++;
            if (r == n) {
              r = 0;
              paso = true;
            }
          }

          if (cnt >= n) return true;
        }

        if (paso) break;
        i = r;
      }
    }
    return 0;
  };

  while (l < r) {
    ll mid = (l + r) / 2;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << ENDL;

  return 0;
}