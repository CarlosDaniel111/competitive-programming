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

ll cnt[10000][100];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> arr(n);
  FOR(i, 0, n) {
    string s;
    cin >> s;
    arr[i] = s;
    ll sum = 0;
    FOR(j, 0, SZ(s)) {
      sum += s[j] - '0';
    }
    cnt[sum][SZ(s)]++;
  }
  ll ans = 0;
  FOR(i, 0, n) {
    for (int j = 0; j <= (SZ(arr[i]) + 1) / 2; j++) {
      string s1 = arr[i].substr(0, j);
      string s2 = arr[i].substr(j);
      int val1 = 0, val2 = 0;
      FOR(k, 0, SZ(s1)) {
        val1 += s1[k] - '0';
      }
      FOR(k, 0, SZ(s2)) {
        val2 += s2[k] - '0';
      }

      if (val2 - val1 < 0) continue;
      if (val2 - val1 == 0 && SZ(arr[i]) % 2 == 0 && j == (SZ(arr[i]) / 2)) {
        cout << "-" << ENDL;
        ans++;
        continue;
      }
      // cout << val2 - val1 << " " << j << ENDL;
      ans += cnt[val2 - val1][SZ(arr[i]) - j * 2];
      cout << i << " " << val1 << " " << val2 << ENDL;
      cout << cnt[val2 - val1][SZ(arr[i]) - j * 2] << ENDL;
    }

    for (int j = ((SZ(arr[i]) + 1) / 2) + 1; j <= SZ(arr[i]); j++) {
      string s1 = arr[i].substr(0, j);
      string s2 = arr[i].substr(j);
      int val1 = 0, val2 = 0;
      FOR(k, 0, SZ(s1)) {
        val1 += s1[k] - '0';
      }
      FOR(k, 0, SZ(s2)) {
        val2 += s2[k] - '0';
      }

      if (val1 - val2 <= 0) continue;
      // cout << val1 - val2 << " " << j << ENDL;
      ans += cnt[val1 - val2][j * 2 - SZ(arr[i])];
      cout << i << " " << val1 << " " << val2 << ENDL;
      cout << cnt[val1 - val2][j * 2 - SZ(arr[i])] << ENDL;
    }
  }
  cout << ans - (n - 1) << ENDL;

  return 0;
}