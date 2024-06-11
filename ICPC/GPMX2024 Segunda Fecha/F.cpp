#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define ALL(x) (x.begin(), x.end())
#define SZ(x) ((int)x.size())
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; i++)
#define ENDL '\n'

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, p;
  cin >> n >> p;
  int ans = 0;
  FOR(i, 0, n) {
    int x;
    cin >> x;
    if (p >= x) ans = max(ans, x);
  }
  cout << ans << ENDL;
}