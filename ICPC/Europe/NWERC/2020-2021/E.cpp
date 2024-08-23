#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

pi operator+(pi a, pi b) {
  return pi(a.first + b.first, a.second + b.second);
}

pi operator-(pi a, pi b) {
  return pi(a.first - b.first, a.second - b.second);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  srand(time(NULL));
  int n;
  cin >> n;
  pi a, b;
  cin >> a.first >> a.second;
  cin >> b.first >> b.second;
  vector<pi> moves(n + 1, {0, 0});
  FOR(i, 0, n) {
    cin >> moves[i].first >> moves[i].second;
  }
  auto random = [&]() -> int {
    return 1ll * rand() * rand() % n + 1;
  };
  auto isValid = [&](pi x) -> bool {
    return (x.first > 0 && x.first <= n && x.second > 0 && x.second <= n);
  };

  auto check = [&](pi a, pi b) -> bool {
    vector<pi> p;
    FOR(i, 0, n) {
      if (isValid(a + moves[i])) {
        p.pb(a + moves[i]);
      }
    }
    sort(ALL(p));
    FOR(i, 0, n + 1) {
      pi t = b - moves[i];
      if (binary_search(ALL(p), t)) return true;
    }
    return false;
  };

  if (check(a, b)) {
    cout << "Alice wins" << ENDL;
    return 0;
  }
  pi ans;
  bool ok = false;
  FOR(i, 0, 100) {
    ans = {random(), random()};
    while (ans == b) ans = {random(), random()};
    if (!check(b, ans)) {
      cout << "tie " << ans.first << " " << ans.second << ENDL;
      return 0;
    }
  }
  cout << "Bob wins" << ENDL;

  return 0;
}