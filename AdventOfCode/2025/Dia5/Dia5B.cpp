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

const ll INF = 1e18;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ifstream file(
      "/Users/CarlosBeltran/Documents/ICPC/competitive-programming/"
      "AdventofCode/2025/Dia5/input.txt");

  string line;
  set<pair<ll, ll>> st;
  while (getline(file, line)) {
    if (SZ(line) == 0) break;
    ll num1 = stoll(split(line, '-')[0]);
    ll num2 = stoll(split(line, '-')[1]);
    st.insert({num2, num1});
  }
  while (true) {
    set<pair<ll, ll>> st2;
    bool change = false;
    for (auto [num2, num1] : st) {
      auto it = st2.lower_bound({num1, -INF});
      if (it != st2.end()) {
        pair<ll, ll> curr = *it;
        if (num2 >= curr.second) {
          curr.second = min(curr.second, num1);
          curr.first = max(curr.first, num2);
        } else {
          st2.insert({num2, num1});
          continue;
        }
        change = true;
        st2.erase(it);
        st2.insert(curr);
      } else {
        st2.insert({num2, num1});
      }
    }
    swap(st, st2);
    if (!change) break;
  }
  ll ans = 0;
  for (auto [r, l] : st) {
    ans += r - l + 1;
  }
  cout << ans << ENDL;

  return 0;
}