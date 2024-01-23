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

ll cnt[100][100];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> arr(n);
  vi sumas(n);
  FOR(i, 0, n) {
    string s;
    cin >> s;
    arr[i] = s;
    ll sum = 0;
    FOR(j, 0, SZ(s)) {
      sum += s[j] - '0';
    }
    sumas[i] = sum;
    cnt[sum][SZ(s)]++;
  }
  ll ans = 0;
  FOR(i, 0, n) {
    int val1 = 0, val2 = sumas[i];
    ans += cnt[val2][SZ(arr[i])];
    for (int j = 0; j < SZ(arr[i]) - 1; j++) {
      val1 += arr[i][j] - '0';
      val2 -= arr[i][j] - '0';
      if (((j + 1) * 2) == SZ(arr[i])) {
        continue;
      }
      if ((j + 1) * 2 < SZ(arr[i])) {
        if (val2 - val1 <= 0) continue;
        ans += cnt[val2 - val1][SZ(arr[i]) - ((j + 1) * 2)];
      } else {
        if (val1 - val2 <= 0) continue;
        ans += cnt[val1 - val2][((j + 1) * 2) - SZ(arr[i])];
      }
    }
  }
  cout << ans << ENDL;

  return 0;
}