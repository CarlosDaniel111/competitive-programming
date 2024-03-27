#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vi a(n);
  vi b(m);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;

  ll ans = 0, j = 0, ant;
  FOR(i, 0, n) {
    int suma = 0;
    if (i != 0 && a[i - 1] == a[i]) {
      ans += ant;
      continue;
    }
    while (j < SZ(b)) {
      if (b[j] == a[i])
        j++, suma++;
      else if (b[j] < a[i])
        j++;
      else
        break;
    }
    ans += suma;
    ant = suma;
  }
  cout << ans << ENDL;

  return 0;
}