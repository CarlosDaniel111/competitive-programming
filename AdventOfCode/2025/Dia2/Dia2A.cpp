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
      "AdventofCode/2025/Dia2/input.txt");

  vector<ll> st;
  FOR(i, 1, 1000000) {
    string orig = to_string(i);
    string s = orig + orig;
    while (SZ(s) < 18) {
      st.pb(stoll(s));
      s += orig;
    }
  }
  sort(ALL(st));
  st.erase(unique(st.begin(), st.end()), st.end());
  string line;
  getline(file, line);
  vector<string> ss = split(line, ',');
  ll ans = 0;
  for (auto s : ss) {
    string s1 = split(s, '-')[0];
    string s2 = split(s, '-')[1];
    auto p1 = lower_bound(ALL(st), stoll(s1));
    auto p2 = upper_bound(ALL(st), stoll(s2));
    while (p1 != p2) {
      ans += *p1;
      p1++;
    }
  }
  cout << ans << ENDL;

  return 0;
}