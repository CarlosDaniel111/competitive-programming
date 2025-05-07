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

vi a, vis;
int n, cnt = 0;

int get(int k) {
  cnt++;
  int squads = 0, ans = 0;
  FOR(i, 0, n) {
    if (vis[a[i]] != cnt) {
      vis[a[i]] = cnt;
      squads++;
    }
    if (squads > k) {
      ans++;
      squads = 1;
      vis[a[i]] = ++cnt;
    }
  }
  return ans;
}
vi res;

void solve(int l, int r) {
  int lans = get(l), rans = get(r);
  if (lans == rans) {
    FOR(i, l, r + 1) { res[i] = lans; }
  } else {
    int mid = (l + r) / 2;
    solve(l, mid);
    solve(mid + 1, r);
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n;
  a.resize(n + 5);
  vis.resize(n + 5);
  res.resize(n + 1);
  FOR(i, 0, n) { cin >> a[i]; }

  solve(1, n);
  FOR(i, 1, n + 1) { cout << res[i] + 1 << " "; }

  cout << ENDL;
  return 0;
}