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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  string s;
  cin >> s;
  int cntA = 0, cntB = 0, cntC = 0;
  FOR(i, 0, 3 * n) {
    cntA += (s[i] == 'A');
    cntB += (s[i] == 'B');
    cntC += (s[i] == 'C');
  }

  if (cntA == n && cntB == n && cntC == n) {
    cout << 0 << ENDL;
    return 0;
  }

  char a, b, c;
  int cnt1, cnt2;

  if (cntA >= n && cntB >= n) {
    a = 'A', b = 'B', c = 'C';
    cnt1 = cntA, cnt2 = cntB;
  } else if (cntA >= n && cntC >= n) {
    a = 'A', b = 'C', c = 'B';
    cnt1 = cntA, cnt2 = cntC;
  } else if (cntB >= n && cntC >= n) {
    a = 'B', b = 'C', c = 'A';
    cnt1 = cntB, cnt2 = cntC;
  }

  vector<pi> cnt(3 * n + 1);
  FOR(i, 1, 3 * n + 1) {
    cnt[i] = {cnt[i - 1].first + (s[i - 1] == a),
              cnt[i - 1].second + (s[i - 1] == b)};
  }
  pi curr = {0, 0};
  FOR(i, 0, 3 * n) {
    pi p1 = {cnt1 - n + curr.first, cnt2 - n + curr.second};
    if (binary_search(ALL(cnt), p1)) {
      int r = lower_bound(ALL(cnt), p1) - cnt.begin();
      cout << 1 << ENDL;
      cout << i + 1 << " " << r << " " << c << ENDL;
      return 0;
    }
    curr.first += (s[i] == a);
    curr.second += (s[i] == b);
  }

  cntA = cntB = cntC = 0;
  cout << 2 << ENDL;
  FOR(i, 0, 3 * n) {
    cntA += (s[i] == 'A');
    cntB += (s[i] == 'B');
    cntC += (s[i] == 'C');

    if (cntA == n) {
      cout << i + 2 << " " << i + 1 + (n - cntB) << " B" << ENDL;
      cout << i + 2 + (n - cntB) << " " << n * 3 << " C" << ENDL;
      return 0;
    }

    if (cntB == n) {
      cout << i + 2 << " " << i + 1 + (n - cntA) << " A" << ENDL;
      cout << i + 2 + (n - cntA) << " " << n * 3 << " C" << ENDL;
      return 0;
    }

    if (cntC == n) {
      cout << i + 2 << " " << i + 1 + (n - cntA) << " A" << ENDL;
      cout << i + 2 + (n - cntA) << " " << n * 3 << " B" << ENDL;
      return 0;
    }
  }

  return 0;
}