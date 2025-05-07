#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
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

void solve() {
  cout.flush();
  int n, m;
  cin >> n >> m;
  cout.flush();
  cout.flush();
  cout << "? 1 1";
  cout.flush();
  int d, d2, d3;
  cin >> d;
  cout.flush();
  if (d == 0) {
    cout << "! 1 1";
    cout.flush();
    return;
  }
  pi lado1, lado2;
  if (d < n) {
    lado1.first = d + 1;
    lado1.second = 1;
    cout << "? " << lado1.first << " " << lado1.second;
    cout.flush();
    cin >> d2;
    cout.flush();
  } else {
    lado1.first = n;
    lado1.second = d - n + 2;
    cout << "? " << lado1.first << " " << lado1.second;
    cout.flush();
    cin >> d2;
    cout.flush();
  }
  if (d2 == 0) {
    cout << "! " << lado1.first << " " << lado1.second;
    cout.flush();
    return;
  }

  if (d < m) {
    lado2.first = 1;
    lado2.second = d + 1;
    cout << "? " << lado2.first << " " << lado2.second;
    cout.flush();
    cin >> d3;
    cout.flush();
  } else {
    lado2.first = d - m + 2;
    lado2.second = m;
    cout << "? " << lado2.first << " " << lado2.second;
    cout.flush();
    cin >> d3;
    cout.flush();
  }
  if (d3 == 0) {
    cout << "! " << lado2.first << " " << lado2.second;
    cout.flush();
    return;
  }

  int aux = d2 / 2;
  pi prueba;
  prueba.first = lado1.first - aux;
  prueba.second = lado1.second - aux;
  int d4;
  cout << "? " << prueba.first << " " << prueba.second;
  cout.flush();
  cin >> d4;
  cout.flush();
  if (d4 == 0) {
    cout << "! " << prueba.first << " " << prueba.second;
    cout.flush();
    return;
  }
  prueba.first = lado2.first - aux;
  prueba.second = lado2.second - aux;
  cout << "! " << prueba.first << " " << prueba.second;
  cout.flush();
  return;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  cout.flush();
  while (t--)
    solve();

  return 0;
}