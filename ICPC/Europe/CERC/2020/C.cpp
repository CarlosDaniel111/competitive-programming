#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define SZ(x) ((int)x.size())
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

inline int add(int x, int y, int m) { return x + y < m ? x + y : x + y - m; }

i64 f(int i, int j, string& s, vector<int>& val, const int mxVal,
      vector<int>& pw) {
  if (j == (int)pw.size() - 1) {
    return s[i] == '?' ? mxVal : val[s[i] - 'A'];
  }

  const int n = (int)s.size();

  set<char> st;
  for (int k = i; st.empty() || k != i; k = add(k, pw[j], n)) {  // 1
    st.insert(s[k]);
  }

  auto full = [&](char c) -> i64 {
    i64 x = c == '?' ? mxVal : val[c - 'A'];
    return x * (n / pw[j]) * ((int)pw.size() - j);
  };

  if ((int)st.size() == 1) {
    return full(*st.begin());
  }

  i64 ret = 0;
  if ((int)st.size() == 2 && *st.begin() == '?') {
    ret = max(ret, full(*st.rbegin()));
  }

  i64 alt = f(i, j + 1, s, val, mxVal, pw);
  for (int k = add(i, pw[j], n); k != add(i, pw[j + 1], n);
       k = add(k, pw[j], n)) {
    alt += f(k, j + 1, s, val, mxVal, pw);
  }
  ret = max(ret, alt);
  return ret;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  string s;
  int q;
  cin >> n >> s >> q;

  vector<int> val(26);
  while (q--) {
    char c;
    int v;
    cin >> c >> v;
    val[c - 'A'] = v;
  }

  if (n == 1) {
    if (s[0] == '?') {
      cout << *max_element(val.begin(), val.end()) << ENDL;
    } else {
      cout << val[s[0] - 'A'] << ENDL;
    }
    return 0;
  }

  int pr;
  for (pr = 2; n % pr; ++pr);
  vector<int> pw = {1};
  while (pw.back() != n) {
    pw.push_back(pw.back() * pr);
  }

  cout << f(0, 0, s, val, *max_element(val.begin(), val.end()), pw) << '\n';

  return 0;
}