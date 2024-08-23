#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

vector<ll> bit;

ll query(ll i) {
  ll sum = 0;
  while (i > 0) {
    sum += bit[i];
    i -= i & (-i);
  }
  return sum;
}

void add(ll i, ll val) {
  while (i < SZ(bit)) {
    bit[i] += val;
    i += i & (-i);
  }
}

ll n;
vector<vi> arr;
vi pos;

ll solve(ll x, ll y) {
  bit.assign(n + 5, 0);
  FOR(i, 1, n + 1) {
    pos[arr[x][i]] = i;
  }

  ll ans = 0;
  for (ll i = n; i; i--) {
    ans += query(pos[arr[y][i]]);
    add(pos[arr[y][i]], 1);
  }
  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n;
  arr.assign(5, vi(n + 5, 0));
  pos.assign(n + 5, 0);

  FOR(i, 0, 3) {
    FOR(j, 1, n + 1) {
      cin >> arr[i][j];
    }
  }

  ll tot = n * (n - 1) / 2;
  ll ans = (solve(0, 1) + solve(1, 2) + solve(2, 0)) / 2;
  ans = tot - ans;
  cout << ans << ENDL;

  return 0;
}