#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T>
using oset =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

template <class T>
struct STMin {
  vector<vector<T>> jmp;
  void init(const vector<T>& V) {
    if (SZ(jmp)) jmp.clear();
    jmp.emplace_back(V);
    for (int pw = 1, k = 1; pw * 2 <= SZ(V); pw *= 2, ++k) {
      jmp.emplace_back(SZ(V) - pw * 2 + 1);
      FOR(j, 0, SZ(jmp[k]))
      jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
    }
  }
  T query(int l, int r) {  // [a, b)
    int dep = 31 - __builtin_clz(r - l);
    return min(jmp[dep][l], jmp[dep][r - (1 << dep)]);
  }
};

template <class T>
struct STMax {
  vector<vector<T>> jmp;
  void init(const vector<T>& V) {
    if (SZ(jmp)) jmp.clear();
    jmp.emplace_back(V);
    for (int pw = 1, k = 1; pw * 2 <= SZ(V); pw *= 2, ++k) {
      jmp.emplace_back(SZ(V) - pw * 2 + 1);
      FOR(j, 0, SZ(jmp[k]))
      jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
    }
  }
  T query(int l, int r) {  // [a, b)
    int dep = 31 - __builtin_clz(r - l);
    return max(jmp[dep][l], jmp[dep][r - (1 << dep)]);
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  map<int, vi> cnt;
  cin >> n;
  vi a(n);
  FOR(i, 0, n) {
    cin >> a[i];
    cnt[a[i]].pb(i);
  }
  STMin<int> stmn;
  STMax<int> stmx;
  stmn.init(a);
  stmx.init(a);
  set<string> ans;
  for (auto& [x, pos] : cnt) {
    // 111
    if (SZ(pos) >= 3) ans.insert("111");

    if (SZ(pos) >= 2) {
      // 112
      int y = stmx.query(pos[1], n);
      if (y > x) ans.insert("112");

      // 121
      y = stmx.query(pos[0], pos.back());
      if (y > x) ans.insert("121");

      if (pos[SZ(pos) - 2] != 0) {
        // 122
        y = stmn.query(0, pos[SZ(pos) - 2]);
        if (y < x) ans.insert("122");

        // 211
        y = stmx.query(0, pos[SZ(pos) - 2]);
        if (y > x) ans.insert("211");
      }

      // 212
      y = stmn.query(pos[0], pos.back());
      if (y < x) ans.insert("212");

      // 221
      y = stmn.query(pos[1], n);
      if (y < x) ans.insert("221");
    }
  }

  // 123 321
  FOR(i, 1, n - 1) {
    // 123
    int l = stmn.query(0, i);
    int r = stmx.query(i, n);
    if (l < a[i] && a[i] < r) ans.insert("123");
    l = stmx.query(0, i);
    r = stmn.query(i, n);
    if (l > a[i] && a[i] > r) ans.insert("321");
  }

  oset<int> st;
  FOR(r, 0, 2) {
    st.clear();
    st.insert(a[0]);
    FOR(i, 1, n - 1) {
      st.insert(a[i]);
      int k = st.order_of_key(a[i]);

      // 231 y 132
      if (k != 0) {
        int y = *st.find_by_order(k - 1);
        int z;
        if (r == 0)
          z = stmn.query(i, n);
        else
          z = stmn.query(0, n - i - 1);
        if (y < a[i] && y > z) {
          if (r == 0)
            ans.insert("231");
          else
            ans.insert("132");
        }
      }

      // 213
      // 312
      int y = *st.find_by_order(k + 1);
      int z;
      if (r == 0)
        z = stmx.query(i, n);
      else
        z = stmx.query(0, n - i - 1);

      if (a[i] < y && y < z) {
        if (r == 0)
          ans.insert("213");
        else
          ans.insert("312");
      }
    }
    reverse(ALL(a));
  }

  for (auto s : ans) {
    cout << s << ENDL;
  }

  return 0;
}