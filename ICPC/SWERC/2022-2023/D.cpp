#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

struct node {
  int x, y, z;
};

int t1, t2, t3;
vector<node> ans;

void add(int t, int v) {
  if (t1 >= v && (t1 <= t2 || t2 < v) && (t1 <= t3 || t3 < v))
    ans.pb({1, t - v, t}), t1 = 0;
  else if (t2 >= v && (t2 <= t1 || t1 < v) && (t2 <= t3 || t3 < v))
    ans.pb({2, t - v, t}), t2 = 0;
  else if (t3 >= v && (t3 <= t1 || t1 < v) && (t3 <= t2 || t2 < v))
    ans.pb({3, t - v, t}), t3 = 0;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int a, b, c, l;
  cin >> a >> b >> c >> l;
  FOR(i, 1, l + 1) {
    int mx = max({++t1, ++t2, ++t3});
    if (c && mx >= 4)
      add(i, 4), c--;
    else if (b && mx >= 3)
      add(i, 3), b--;
    else if (a && mx >= 2)
      add(i, 2), a--;
  }
  cout << SZ(ans) << ENDL;
  for (auto a : ans) {
    cout << a.x << " " << a.y << " " << a.z << ENDL;
  }

  return 0;
}