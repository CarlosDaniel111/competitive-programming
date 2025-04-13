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
  int n;
  cin >> n;
  vector<pi> dolls(n);
  for (auto &d : dolls) {
    cin >> d.first >> d.second;
    d.second *= -1;
  }
  sort(ALL(dolls));

  for (auto &d : dolls) {
    d.second *= -1;
  }

  deque<int> dq;
  FOR(i, 0, n) {
    int pos = lower_bound(ALL(dq), dolls[i].second) - dq.begin();
    if (pos == 0)
      dq.push_front(dolls[i].second);
    else
      dq[pos - 1] = dolls[i].second;
  }
  cout << SZ(dq) << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}