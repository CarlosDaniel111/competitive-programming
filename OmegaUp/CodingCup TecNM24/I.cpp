#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;
using edge = tuple<int, int, int>;

#define pb push_back
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x), end(x)
#define ENDL '\n'
constexpr int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
constexpr int INF = 3e8;

int n, m, I, D;

bool isValid(int x, int y) { return (x >= 0 && x < n && y >= 0 && y < m); }

signed main() {
  pi ini, fin;

  cin >> n >> m;
  cin >> ini.first >> ini.second;
  cin >> fin.first >> fin.second;
  cin >> I >> D;

  string s;
  getline(cin, s);

  vector<pi> inWord, outWord;

  FOR(i, 0, n) {
    getline(cin, s);
    bool esp = true;
    FOR(j, 0, m) {
      if (s[j] >= 'a' && s[j] <= 'z' && esp) {
        inWord.pb({i, j});
        esp = false;
      }
      if ((j == m - 1 && s[j] >= 'a' && s[j] <= 'z') or
          (s[j + 1] == ' ' && !esp)) {
        outWord.pb({i, j});
        esp = true;
      }
    }
  }

  priority_queue<tuple<int, int, int>> pq;
  pq.push({0, ini.first, ini.second});
  vector<vi> dist(n, vi(m, INF));
  dist[ini.first][ini.second] = 0;

  while (SZ(pq)) {
    auto [du, ux, uy] = pq.top();
    du *= -1;
    pq.pop();

    if (make_pair(ux, uy) == fin) break;

    // mov
    FOR(k, 0, 4) {
      int vx = ux + dx[k], vy = uy + dy[k];
      if (!isValid(vx, vy)) continue;
      if (dist[vx][vy] > du + D) {
        dist[vx][vy] = du + D;
        pq.push({-dist[vx][vy], vx, vy});
      }
    }

    bool estoyIn = binary_search(ALL(inWord), make_pair(ux, uy));
    bool estoyOut = binary_search(ALL(outWord), make_pair(ux, uy));

    // press a
    auto it = lower_bound(ALL(inWord), make_pair(ux, uy));
    if (it != inWord.begin()) {
      // if(make_pair(ux,uy) == *it) continue;
      it = prev(it);
      auto [vx, vy] = *it;
      // if (vx != ux) continue;
      if (dist[vx][vy] > du + I) {
        dist[vx][vy] = du + I;
        pq.push({-dist[vx][vy], vx, vy});
      }
    }

    // press s
    auto it2 = lower_bound(ALL(outWord), make_pair(ux, uy));
    if (it2 != outWord.begin()) {
      it2 = prev(it2);
      auto [vx, vy] = *it2;
      // if (vx != ux) continue;
      if (dist[vx][vy] > du + I) {
        dist[vx][vy] = du + I;
        pq.push({-dist[vx][vy], vx, vy});
      }
    }

    // press d
    it = upper_bound(ALL(inWord), make_pair(ux, uy));
    if (it != inWord.end()) {
      auto [vx, vy] = *it;
      // if (vx != ux) continue;
      if (dist[vx][vy] > du + I) {
        dist[vx][vy] = du + I;
        pq.push({-dist[vx][vy], vx, vy});
      }
    }

    // press f
    it2 = upper_bound(ALL(outWord), make_pair(ux, uy));
    if (it2 != outWord.end()) {
      auto [vx, vy] = *it2;
      // if (vx != ux) continue;
      if (dist[vx][vy] > du + I) {
        dist[vx][vy] = du + I;
        pq.push({-dist[vx][vy], vx, vy});
      }
    }
  }

  // cout << "INICIOS" << ENDL;
  // for (auto [x, y] : inWord) {
  //   cout << x << " " << y << ENDL;
  // }
  // cout << "FINALES" << ENDL;
  // for (auto [x, y] : outWord) {
  //   cout << x << " " << y << ENDL;
  // }

  // FOR(i, 0, n) {
  //   FOR(j, 0, m) { cout << dist[i][j] << " "; }
  //   cout << ENDL;
  // }

  cout << dist[fin.first][fin.second] << ENDL;

  return 0;
}