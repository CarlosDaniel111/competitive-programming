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

vi PI(const string& s) {
  vi p(SZ(s));
  FOR(i, 1, SZ(s)) {
    int g = p[i - 1];
    while (g && s[i] != s[g]) g = p[g - 1];
    p[i] = g + (s[i] == s[g]);
  }
  return p;
}

int KMP(const string& s, const string& pat) {
  vi phi = PI(pat);
  int matches = 0;
  for (int i = 0, j = 0; i < SZ(s); ++i) {
    while (j > 0 && s[i] != pat[j]) j = phi[j - 1];
    if (s[i] == pat[j]) ++j;
    if (j == SZ(pat)) {
      matches++;
      j = phi[j - 1];
    }
  }
  return matches;
}

void solve() {
  string a, s, t;
  cin >> a >> s >> t;
  if (SZ(s) < SZ(t)) swap(s, t);

  auto check = [&](string A) -> bool {
    A = A + A.substr(0, SZ(s) - 1);
    int vS = KMP(A, s), vT = KMP(A, t);
    return (vS <= vT);
  };
  queue<string> q;
  q.push(s);
  FOR(i, 0, 1000) {
    string A = q.front();
    q.pop();
    if (check(A)) {
      for (auto c : a) q.push(A + c);
    } else {
      cout << 0 << ENDL;
      return;
    }
  }
  cout << 1 << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}