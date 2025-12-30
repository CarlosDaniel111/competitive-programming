#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

constexpr int MAX_N = 100, MAX_W = 900, MAX_H = 350;

bool dp[MAX_N + 1][MAX_W + 1][MAX_H + 1];

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int N, H, W;
  cin >> N >> H >> W;

  vector<pair<int, int>> a(N);
  for (auto& [h, t] : a) {
    cin >> h >> t;
  }

  vector<int> p(N);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int i, int j) { return a[i] < a[j]; });

  dp[0][0][0] = true;
  for (int i = 0; i < N; ++i) {
    int t = a[p[i]].second;
    for (int j = 0; j <= W; ++j) {
      for (int k = 0; k <= H; ++k) {
        if (!dp[i][j][k]) {
          continue;
        }
        if (j + t <= W) {
          dp[i + 1][j + t][k] = true;
        }
        if (k + t <= H) {
          dp[i + 1][j][k + t] = true;
        }
      }
    }
  }

  int ansI = -1, ansJ = -1, ansK = -1;
  vector<int> upright, stacked;
  if (a[p.back()].first > H) {
    int l = N - 1;
    while (l && a[p[l - 1]].first > H) {
      --l;
    }

    int rW = W - a[p.back()].first, rH = H;
    for (int i = l; i < N; ++i) {
      rH -= a[p[i]].second;
    }

    if (rW <= 0 || rH < 0) {
      cout << "impossible\n";
      return 0;
    }

    for (int j = 1; j <= rW && ansI == -1; ++j) {
      for (int k = 0; k <= rH; ++k) {
        if (dp[l][j][k]) {
          ansI = l, ansJ = j, ansK = k;
          break;
        }
      }
    }

    if (ansI == -1) {
      cout << "impossible\n";
      return 0;
    }

    for (int i = N - 1; i >= l; --i) {
      stacked.push_back(p[i]);
    }
  } else {
    int sT = 0;
    for (int i = N - 1; i >= 0 && ansI == -1; sT += a[p[i--]].second) {
      int rW = W - a[p[i]].first - sT, rH = H - a[p[i]].second;
      for (int j = i == N - 1; j <= rW && ansI == -1; ++j) {
        for (int k = 0; k <= rH; ++k) {
          if (dp[i][j][k]) {
            ansI = i, ansJ = j, ansK = k;
            break;
          }
        }
      }
    }

    if (ansI == -1) {
      cout << "impossible\n";
      return 0;
    }

    stacked.push_back(p[ansI]);
    for (int i = ansI + 1; i < N; ++i) {
      upright.push_back(p[i]);
    }
  }

  for (int i = ansI, j = ansJ, k = ansK; i; --i) {
    int t = a[p[i - 1]].second;
    if (j >= t && dp[i - 1][j - t][k]) {
      upright.push_back(p[i - 1]);
      j -= t;
    } else {
      stacked.push_back(p[i - 1]);
      k -= t;
    }
  }

  cout << "upright";
  for (int i : upright) {
    cout << ' ' << i + 1;
  }
  cout << '\n';
  cout << "stacked";
  for (int i : stacked) {
    cout << ' ' << i + 1;
  }
  cout << '\n';
}

// dp[i][j][k] = usando los primeros i elementos puedes formar 2 grupos, uno con
// thickness j y otro con k? if dp[i-1][j][k] dp[i][j+t[x]][k] = true
// dp[i][j][k+t[x]] = true