#include <bits/stdc++.h>
using namespace std;
// AC2#
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;
constexpr ll INF = 1e15;
constexpr ll LLINF = 1e18;

void solve() {
  ll n;
  cin >> n;
  vi arr(n);
  ll minimo = INF;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    minimo = min(arr[i], minimo);
  }
  ll ans = minimo - 1;
  bool sube = true;
  ll aux = minimo;
  ll ant = minimo;
  for (int i = 0; i < n; i++) {
    if (arr[i] >= aux && sube) {
      aux = arr[i];
      continue;
    }
    if (arr[i] < aux && sube) {
      ans += aux - ant;
      sube = false;
      aux = arr[i];
      continue;
    }
    if (arr[i] >= aux && !sube) {
      ant = aux;
      sube = true;
      aux = arr[i];
      continue;
    }
    if (arr[i] < aux && !sube) {
      aux = ant[i];
      continue;
    }
  }
  if (sube)
    ans += aux - ant;
  cout << ans << ENDL;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}