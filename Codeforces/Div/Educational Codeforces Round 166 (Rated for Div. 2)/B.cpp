#include <bits/stdc++.h>
using namespace std;

#define pi pair<long long, long long>;
#define vi vector<long long>;

#define pb push_back
#define SZ(x) ((long long)(x).size())
#define Along long(x) begin(x), end(x)
#define FOR(i, a, b) for (long long i = (long long)a; i < (long long)b; ++i)
#define ROF(i, a, b) \
  for (long long i = (long long)a - 1; i >= (long long)b; --i)
#define ENDL '\n'

void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n), b(n + 1);
  FOR(i, 0, n) { cin >> a[i]; }
  FOR(i, 0, n + 1) { cin >> b[i]; }

  long long ans = 0;
  FOR(i, 0, n) {
    if (a[i] <= b[n] && b[i] >= b[n]) {
      ans = 1;
      break;
    } else if (a[i] >= b[n] && b[i] <= b[n]) {
      ans = 1;
      break;
    }
  }
  pair<long long, long long> mn;
  mn = make_pair(30000000000, -1);
  if (ans == 0) {
    FOR(i, 0, n) {
      long long pasos = min(abs(a[i] - b[n]), abs(b[i] - b[n]));
      if (pasos < mn.first) {
        mn.first = pasos;
        mn.second = i;
      }
    }
    ans += mn.first + 1;
  }

  FOR(i, 0, n) { ans += abs(a[i] - b[i]); }
  cout << ans << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  long long t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}