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

  ifstream file(
      "/Users/CarlosBeltran/Documents/ICPC/competitive-programming/"
      "AdventofCode/Dia3/input.txt");

  string line;
  ll ans = 0;
  bool can = true;
  while (getline(file, line)) {
    line += "@@@@@@@@@@@@@@@@@@@@@@@";
    FOR(i, 0, SZ(line)) {
      if (line[i] == 'd' && line.substr(i, 4) == "do()") {
        can = true;
        continue;
      }
      if (line[i] == 'd' && line.substr(i, 7) == "don't()") {
        can = false;
        continue;
      }
      if (can && line[i] == 'm' && line.substr(i, 4) == "mul(") {
        int j = i + 4;
        string num1 = "";
        bool ok = false;
        for (int ii = 0; ii < 4; ii++, j++) {
          if (isnumber(line[j])) {
            num1 += line[j];
          } else if (line[j] == ',') {
            j++;
            ok = true;
            break;
          } else {
            break;
          }
        }

        if (!ok or SZ(num1) == 0) continue;
        string num2 = "";
        ok = false;
        for (int ii = 0; ii < 4; ii++, j++) {
          if (isnumber(line[j])) {
            num2 += line[j];
          } else if (line[j] == ')') {
            j++;
            ok = true;
            break;
          } else {
            break;
          }
        }
        if (!ok or SZ(num2) == 0) continue;
        ans += stoi(num1) * stoi(num2);
      }
    }
  }
  cout << ans << ENDL;

  return 0;
}