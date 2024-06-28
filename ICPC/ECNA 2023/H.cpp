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
  string a, s, t;
  cin >> a >> s >> t;
  if (SZ(s) < SZ(t)) swap(s, t);

  auto check = [&](string A) -> bool {
    int N = SZ(A);
    A = A + A;
    int vS = 0, vT = 0;
    FOR(i, 0, N) {
      if (A.substr(i, SZ(s)) == s) vS++;
      if (A.substr(i, SZ(t)) == t) vT++;
    }
    return (vS <= vT);
  };
  queue<string> q;
  q.push(s);
  FOR(i, 0, 1000) {
    string A = q.front();
    q.pop();
    if (check(A)) {
      for (auto c : a) q.push(A + c);
    } else {
      cout << 0 << ENDL;
      return;
    }
  }
  cout << 1 << ENDL;
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