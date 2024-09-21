#include <bits/stdc++.h>
using namespace std;
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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  vi cap(m);
  FOR(i, 0, m) cin >> cap[i];

  string _;
  getline(cin, _);
  vector<vi> cust(n);
  vector<vi> rest(m);
  FOR(i, 0, n) {
    string s;
    getline(cin, s);
    int j = 0;
    while (j != SZ(s)) {
      while (j < SZ(s) && isspace(s[j])) j++;
      int x = 0;
      while (j < SZ(s) && isdigit(s[j])) x = x * 10 + (s[j] - '0'), j++;
      x--;
      cust[i].pb(x);
      while (j < SZ(s) && isspace(s[j])) j++;
    }
  }

  vector<map<int, int>> mp(m);

  FOR(i, 0, m) {
    string s;
    getline(cin, s);
    int j = 0;
    while (j != SZ(s)) {
      while (j < SZ(s) && isspace(s[j])) j++;
      int x = 0;
      while (j < SZ(s) && isdigit(s[j])) x = x * 10 + (s[j] - '0'), j++;
      x--;
      rest[i].pb(x);
      mp[i][x] = SZ(rest[i]) - 1;
      while (j < SZ(s) && isspace(s[j])) j++;
    }
  }

  vi usado(n, 0);
  vector<priority_queue<int>> pq(m);
  queue<int> q;
  FOR(i, 0, n) q.push(i);
  while (SZ(q)) {
    int c = q.front();
    q.pop();
    if (usado[c] == SZ(cust[c])) continue;
    int r = cust[c][usado[c]];
    pq[r].push(mp[r][c]);
    if (SZ(pq[r]) > cap[r]) {
      int y = rest[r][pq[r].top()];
      pq[r].pop();
      usado[y]++;
      q.push(y);
    }
  }
  FOR(i, 0, n) {
    if (usado[i] < SZ(cust[i])) {
      cout << i + 1 << ENDL;
    }
  }

  return 0;
}