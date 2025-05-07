#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve() {
  ll n, c, d;
  cin >> n >> c >> d;
  multiset<ll> numeros;
  numeros.clear();
  ll menor = 3e10;
  FOR(i, 0, n * n) {
    ll x;
    cin >> x;
    numeros.insert(x);
    menor = min(menor, x);
  }
  FOR(i, 0, n) {
    FOR(j, 0, n) {
      ll act = menor + (i * c) + (j * d);
      if (numeros.count(act)) {
        numeros.erase(numeros.find(act));
      } else {
        cout << "NO" << ENDL;
        return;
      }
    }
  }
  cout << "YES" << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}