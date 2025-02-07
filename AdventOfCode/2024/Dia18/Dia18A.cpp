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
const int n = 71;
const int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ifstream file(
      "/Users/CarlosBeltran/Documents/ICPC/competitive-programming/"
      "AdventofCode/Dia19/input.txt");

  string line;
  vector<vi> block(n, vi(n, 0));
  queue<pi> sig;
  int cnt = 0;
  while (getline(file, line)) {
    int x = stoi(split(line, ',')[0]);
    int y = stoi(split(line, ',')[1]);
    if (cnt < 1024)
      block[y][x] = 1;
    else
      sig.push({x, y});
    cnt++;
  }

  while (SZ(sig)) {
    queue<pi> q;
    vector<vi> dist(n, vi(n, -1));
    q.push({0, 0});
    dist[0][0] = 0;
    auto [xx, yy] = sig.front();
    sig.pop();
    block[yy][xx] = 1;
    auto isValid = [&](int x, int y) -> bool {
      return (x >= 0 && x < n && y >= 0 && y < n && !block[x][y] &&
              dist[x][y] == -1);
    };

    while (SZ(q)) {
      auto [x, y] = q.front();
      q.pop();

      FOR(k, 0, 4) {
        int sigx = x + dx[k], sigy = y + dy[k];
        if (isValid(sigx, sigy)) {
          dist[sigx][sigy] = dist[x][y] + 1;
          q.push({sigx, sigy});
        }
      }
    }
    if (dist[70][70] == -1) {
      cout << xx << "," << yy << ENDL;
      return 0;
    }
  }

  return 0;
}