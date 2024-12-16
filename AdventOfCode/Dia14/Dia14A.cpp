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
      "AdventofCode/Dia14/input.txt");

  string line;
  int c1, c2, c3, c4;
  c1 = c2 = c3 = c4 = 0;
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

    const int N = 103, M = 101;

    FOR(_, 0, 100) {
      posX = (posX + velX + M) % M;
      posY = (posY + velY + N) % N;
    }
    if (posX < M / 2 && posY < N / 2) c1++;
    if (posX > M / 2 && posY < N / 2) c2++;
    if (posX < M / 2 && posY > N / 2) c3++;
    if (posX > M / 2 && posY > N / 2) c4++;
  }
  cout << c1 * c2 * c3 * c4 << ENDL;

  return 0;
}