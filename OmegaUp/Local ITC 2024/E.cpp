#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000;
int W, H;
map<pair<int, int>, int> dp;

// Función de DP con Memoización
int solve(int col, int mask) {
  if (col == W) return mask == 0;
  if (dp.count({col, mask})) return dp[{col, mask}];

  int &res = dp[{col, mask}];
  res = 0;

  // Generamos transiciones
  function<void(int, int)> generate = [&](int pos, int new_mask) {
    if (pos >= H) {
      res = (res + solve(col + 1, new_mask)) % MOD;
      return;
    }

    // Si la celda ya está ocupada, continuar al siguiente
    if (mask & (1 << pos)) {
      generate(pos + 1, new_mask);
    } else {
      // Colocar una enchilada horizontalmente (3 posiciones en la fila)
      if (pos + 2 < H) {
        generate(pos + 3, new_mask);
      }
      // Colocar una enchilada verticalmente (solo en esta columna)
      generate(pos + 1, new_mask | (1 << pos));
    }
  };

  generate(0, 0);
  return res;
}

int main() {
  cin >> H >> W;
  // if (H > W) swap(H, W);  // Siempre asumimos H <= W para optimizar

  dp.clear();
  cout << solve(0, 0) << "\n";
  return 0;
}
