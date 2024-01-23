#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = __int128;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

vi fact;
int d, h;
set<ll> ans;

void solve(ll p, ll s, ll c, ll f) {
  if (p > d) {
    if (s != 0) return;
    ans.insert(fact[h - 1] / f);
    return;
  }
  FOR(i, c, s + 1)
  solve(p + 1, s - i, i, f * fact[i]);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  fact.resize(32);
  fact[0] = 1;
  FOR(i, 1, 32)
  fact[i] = fact[i - 1] * i;

  scanf("%d%d", &d, &h);

  solve(1, h - 1, 0, 1);

  for (auto x : ans) {
    printf("%lld\n", x);
  }

  return 0;
}