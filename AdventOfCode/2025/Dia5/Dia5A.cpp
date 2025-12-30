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

vector<string> split(string str, char pattern) {
  int posInit = 0;
  int posFound = 0;
  string splitted;
  vector<string> results;

  while (posFound >= 0) {
    posFound = str.find(pattern, posInit);
    splitted = str.substr(posInit, posFound - posInit);
    posInit = posFound + 1;
    results.push_back(splitted);
  }

  return results;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ifstream file(
      "/Users/CarlosBeltran/Documents/ICPC/competitive-programming/"
      "AdventofCode/2025/Dia5/input.txt");

  string line;
  vector<pair<ll, ll>> p;
  bool space = false;
  multiset<ll> st;
  while (getline(file, line)) {
    if (SZ(line) == 0) {
      space = true;
      continue;
    }
    if (space) {
      ll num = stoll(line);
      st.insert(num);
      continue;
    }
    ll num1 = stoll(split(line, '-')[0]);
    ll num2 = stoll(split(line, '-')[1]);
    p.pb({num1, num2});
  }
  int ans = 0;
  for (auto [l, r] : p) {
    while (SZ(st)) {
      auto it = st.lower_bound(l);
      if (it == st.end()) break;
      ll num = *it;
      if (num > r) break;
      ans++;
      st.erase(st.find(num));
    }
  }
  cout << ans << ENDL;

  return 0;
}