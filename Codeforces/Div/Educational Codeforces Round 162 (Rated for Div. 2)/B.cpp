#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ll((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define ROF(i, a, b) for (ll i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr ll MOD = 1e9 + 7;
constexpr ll MAXN = 1e5 + 5;
constexpr ll INF = 1e9;
constexpr ll LLINF = 1e18;

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<pi> izq, der;
  vector<pi> input(n);
  FOR(i, 0, n) {
    cin >> input[i].first;
  }
  FOR(i, 0, n) {
    cin >> input[i].second;
  }
  priority_queue<pi> q;
  FOR(i, 0, n) {
    if (input[i].second < 0)
      q.push({input[i].second, input[i].first});
    else
      q.push({-input[i].second, input[i].first});
  }

  ll sobra = 0, t = 0;
  while (SZ(q)) {
    auto [x, a] = q.top();
    q.pop();
    x *= -1;
    if (a <= sobra) {
      sobra -= a;
      continue;
    }
    a -= sobra;
    sobra = 0;
    ll pos = x - t;
    if (pos <= 0) {
      cout << "NO" << ENDL;
      return;
    }
    ll falta = ceil((double)a / (double)k);
    if (falta > pos) {
      cout << "NO" << ENDL;
      return;
    }
    sobra = (falta * k) - a;
    t += falta;
  }

  /*ll i = 0, j = 0, t = 0, sobra = 0;
  while (i < SZ(izq) || j < SZ(der)) {
    if (i == SZ(izq) || (j < SZ(der) && der[j].first <= izq[i].first)) {
      der[j].second -= sobra;

      if (der[j].second <= 0) {
        sobra = abs(der[j].second);
        j++;
        continue;
      }
      ll pos = der[j].first - t;
      if (pos < 0) {
        cout << "NO" << ENDL;
        return;
      }
      ll falta = ceil(der[j].second / k);

      if (falta > pos) {
        cout << "NO" << ENDL;
        return;
      }
      sobra = (falta * k) - der[i].second;
      t += falta;
      j++;
      continue;
    }
    if (j == SZ(der) || (i < SZ(izq) && izq[i].first <= der[j].first)) {
      izq[i].second -= sobra;
      if (izq[i].second <= 0) {
        sobra = abs(izq[i].second);
        i++;
        continue;
      }
      ll pos = izq[i].first - t;
      if (pos < 0) {
        cout << "NO" << ENDL;
        return;
      }
      ll falta = ceil(izq[i].second / k);
      if (falta > pos) {
        cout << "NO" << ENDL;
        return;
      }
      sobra = (falta * k) - izq[i].second;
      t += falta;
      i++;
      continue;
    }
  }*/
  cout << "YES" << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}