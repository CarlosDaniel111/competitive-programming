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
constexpr ll MOD = 1000000007;

struct node {
  ll opc, l, r, x;
};

vi sum, pre, suf, len, val;
vector<node> nodos;

ll solve(ll id, ll x) {
  if (id == 0) {
    if (x == 0) return 0;
    return sum[x - 1] % MOD;
  }

  ll ans = 0;
  if (nodos[id].opc == 1) {
    ans = solve(nodos[id].x, nodos[id].l + x);
    ans -= pre[id];
    ans += MOD;
    ans %= MOD;
    return ans;
  } else {
    if (x <= len[nodos[id].l])
      return solve(nodos[id].l, x) % MOD;
    else
      return (val[nodos[id].l] + solve(nodos[id].r, x - len[nodos[id].l])) % MOD;
  }
}

signed
main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll n;
  string s;
  cin >> n >> s;

  len.assign(n, 0);
  sum.assign(SZ(s), 0);
  nodos.resize(n);
  val.assign(n, 0);
  pre.assign(n, 0);
  suf.assign(n, 0);

  len[0] = SZ(s);
  sum[0] = s[0];
  FOR(i, 1, SZ(s)) {
    sum[i] = sum[i - 1] + s[i];
  }
  val[0] = sum[SZ(s) - 1];

  FOR(i, 1, n) {
    cin >> s;
    if (s[0] == 'S') {
      cin >> nodos[i].x >> nodos[i].l >> nodos[i].r;
      nodos[i].opc = 1;
      pre[i] = solve(nodos[i].x, nodos[i].l);
      suf[i] = solve(nodos[i].x, nodos[i].r);

      val[i] = (suf[i] - pre[i]) % MOD;
      len[i] = nodos[i].r - nodos[i].l;
    } else {
      cin >> nodos[i].l >> nodos[i].r;
      nodos[i].opc = 2;
      val[i] = (val[nodos[i].l] + val[nodos[i].r]) % MOD;
      len[i] = len[nodos[i].l] + len[nodos[i].r];
    }
  }

  cout << (val[n - 1] + MOD) % MOD << ENDL;

  return 0;
}