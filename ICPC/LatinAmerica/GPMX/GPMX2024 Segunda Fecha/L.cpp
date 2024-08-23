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

  int n;
  cin >> n;

  ll ans = 0;
  FOR(k, 0, 2) {
    int l[n], lp[n];
    FOR(i, 0, n) {
      cin >> lp[i];
      lp[i]--;
      l[lp[i]] = i;
    }
    FOR(i, 0, n) {
      ans += l[i] != i;
      int aux = lp[i], aux2 = l[i];
      swap(lp[l[i]], lp[i]);
      l[aux] = aux2;
    }
  }
  cout << ans << ENDL;
}