#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  map<ll, pair<set<ll>, set<pi>>> mp;
  FOR(i, 0, n) {
    ll a, b, c;
    cin >> a >> b >> c;
    mp[a].first.insert(b);
    mp[a].second.insert({b, c});
  }
  for (auto &[id, par] : mp) {
    cout << id << " " << SZ(par.first) << " " << SZ(par.second) << ENDL;
  }

  return 0;
}