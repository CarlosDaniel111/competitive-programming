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

ll pot2(ll x) {
  if (x == -1) return 1;
  return 1ll << x;
}

void solve() {
  ll N, k;
  cin >> N >> k;

  stack<ll> tail;
  queue<ll> frente;
  ll num = 1, ant = 0;
  ll n = N;
  while (num <= N) {
    ll aux = min(60ll, n - 2);
    ll curr = 0;
    while (curr + pot2(aux) < k) {
      curr += pot2(aux);
      aux--;
      num++;
    }
    k -= curr;
    if (num > N) {
      cout << -1 << ENDL;
      return;
    }
    frente.push(num);
    FOR(i, ant + 1, num) tail.push(i);
    n = N - num;
    ant = num;
    num++;
  }
  while (SZ(frente)) {
    cout << frente.front() << " ";
    frente.pop();
  }
  while (SZ(tail)) {
    cout << tail.top() << " ";
    tail.pop();
  }
  cout << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}