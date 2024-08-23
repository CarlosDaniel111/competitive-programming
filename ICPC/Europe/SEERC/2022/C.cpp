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

constexpr int MAX = 1024;

bitset<MAX> test[18];
bitset<MAX> dp[1 << 15];

pair<bitset<MAX>, int> ans[MAX];

bool operator<(const bitset<MAX> &x, const bitset<MAX> &y) {
  for (int i = x.size() - 1; i >= 0; --i) {
    if (x[i] != y[i]) {
      return x[i] < y[i];
    }
  }
  return false;
}

bool cmp(pair<bitset<MAX>, int> &x, pair<bitset<MAX>, int> &y) {
  if (x.first == y.first) return x.second < y.second;
  return x.first < y.first;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  FOR(i, 0, m) {
    int k;
    cin >> k;
    while (k--) {
      int x;
      cin >> x;
      test[i][x] = 1;
    }
  }

  // 110010
  // 110000
  // 100010
  // 100000
  // 010010
  // 010000
  // 000010
  // 000000

  vi cnt(1 << m, 0);
  FOR(mask, 0, 1 << m) {
    bitset<MAX> posibles;
    FOR(i, 0, m) {
      if ((mask >> i) & 1) posibles |= test[i];
    }
    cnt[mask] = n - posibles.count();

    vi add, sub;
    for (int submask = mask; 1; submask = (submask - 1) & mask) {
      if (__builtin_parity(submask))
        sub.pb(cnt[submask]);
      else
        add.pb(cnt[submask]);
      if (submask == 0) break;
    }
    for (int x : add) {
      for (; dp[mask][x]; x++) dp[mask][x] = 0;
      dp[mask][x] = 1;
    }

    for (int x : sub) {
      for (; !dp[mask][x]; x++) dp[mask][x] = 1;
      dp[mask][x] = 0;
    }
  }
  FOR(i, 1, n + 1) {
    ll mask = 0;
    FOR(j, 0, m) if (test[j][i] == 0) mask |= (1 << j);
    ans[i] = {dp[mask], i};
  }
  sort(ans + 1, ans + 1 + n, cmp);

  FOR(i, 1, n + 1) cout << ans[i].second << " ";
  cout << ENDL;

  return 0;
}