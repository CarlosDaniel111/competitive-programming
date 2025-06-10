#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using iii = tuple<int, int, int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
constexpr int N = 1e4 + 5;

bitset<N> sum, ans;
void solve(int L, int R, vector<iii> &ranges) {
  bitset<N> prev = sum;
  vector<iii> left, right;
  int mid = (L + R) >> 1;
  for (auto [l, r, x] : ranges) {
    if (l <= L && R <= r)
      sum |= (sum << x);
    else {
      if (l <= mid) left.pb({l, r, x});
      if (r > mid) right.pb({l, r, x});
    }
  }
  if (L == R) {
    ans |= sum;
    sum = prev;
    return;
  }
  solve(L, mid, left);
  solve(mid + 1, R, right);
  sum = prev;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vector<iii> ranges(m);
  FOR(i, 0, m) {
    int l, r, x;
    cin >> l >> r >> x;
    l--, r--;
    ranges[i] = {l, r, x};
  }
  sum.set(0);
  solve(0, n - 1, ranges);
  int cnt = 0;
  FOR(i, 1, n + 1) cnt += ans[i];
  cout << cnt << ENDL;
  FOR(i, 1, n + 1) {
    if (ans[i]) cout << i << " ";
  }
  cout << ENDL;

  return 0;
}