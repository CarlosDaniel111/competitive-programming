#include <bits/stdc++.h>
using namespace std;
// AC2++
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

  map<int, int> mapa;
  int n;
  cin >> n;
  FOR(i, 0, n * 3) {
    int x;
    cin >> x;
    mapa[x]++;
  }

  for (auto [a, c] : mapa) {
    if (c % 3 != 0) {
      cout << "Y" << ENDL;
      return 0;
    }
  }
  cout << "N" << ENDL;

  return 0;
}