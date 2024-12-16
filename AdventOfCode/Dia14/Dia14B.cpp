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
  ifstream file(
      "/Users/CarlosBeltran/Documents/ICPC/competitive-programming/"
      "AdventofCode/Dia14/input.txt");

  string line;
  vector<pi> robots;
  vector<pi> velo;
  while (getline(file, line)) {
    stringstream ss(line);
    string pos, vel;
    ss >> pos;
    ss >> vel;
    pos = split(pos, '=')[1];
    vel = split(vel, '=')[1];
    int posX = stoi(split(pos, ',')[0]);
    int posY = stoi(split(pos, ',')[1]);
    int velX = stoi(split(vel, ',')[0]);
    int velY = stoi(split(vel, ',')[1]);

    robots.pb({posX, posY});
    velo.pb({velX, velY});
  }

  const int N = 103, M = 101;

  auto print = [&]() -> void {
    vector<vector<char>> grid(N, vector<char>(M, ' '));
    for (auto [y, x] : robots) {
      grid[x][y] = '*';
    }
    FOR(i, 0, N) {
      FOR(j, 0, M) { cout << grid[i][j]; }
      cout << ENDL;
    }
    cout << ENDL;
  };
  FOR(_, 0, 10000) {
    cout << "Segundo " << _ << ENDL;
    print();
    FOR(i, 0, SZ(robots)) {
      robots[i].first = (robots[i].first + velo[i].first + M) % M;
      robots[i].second = (robots[i].second + velo[i].second + N) % N;
    }
  }
  print();

  return 0;
}