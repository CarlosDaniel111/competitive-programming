#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

template <typename T>
pair<T, vi> hungarian(const vector<vector<T>> &a) {
#define INF numeric_limits<T>::max()
  if (a.empty()) return {0, {}};
  int n = SZ(a) + 1, m = SZ(a[0]) + 1;
  vi p(m), ans(n - 1);
  vector<T> u(n), v(m);
  FOR(i, 1, n) {
    p[0] = i;
    int j0 = 0;  // agregar trabajador "dummy" 0
    vector<T> dist(m, INF);
    vi pre(m, -1);
    vector<bool> done(m + 1);
    do {  // dijkstra
      done[j0] = true;
      int i0 = p[j0], j1;
      T delta = INF;
      FOR(j, 1, m)
      if (!done[j]) {
        auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
        if (cur < dist[j]) dist[j] = cur, pre[j] = j0;
        if (dist[j] < delta) delta = dist[j], j1 = j;
      }
      FOR(j, 0, m) {
        if (done[j])
          u[p[j]] += delta, v[j] -= delta;
        else
          dist[j] -= delta;
      }
      j0 = j1;
    } while (p[j0]);
    while (j0) {  // actualizar camino alternativo
      int j1 = pre[j0];
      p[j0] = p[j1], j0 = j1;
    }
  }
  FOR(j, 1, m)
  if (p[j]) ans[p[j] - 1] = j - 1;
  return {-v[0], ans};
}

pair<int, int> matA[55][55];
pair<int, int> matB[55][55];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;
  FOR(i, 0, n) {
    FOR(j, 0, n) { cin >> matA[i][j].first >> matA[i][j].second; }
  }

  FOR(i, 0, n) {
    FOR(j, 0, n) { cin >> matB[i][j].first >> matB[i][j].second; }
  }

  int ans = 3e8, cambio;
  vi ansA, ansB;
  FOR(i, 0, n + 1) {
    vector<vi> mat(n, vi(n, 0));
    FOR(ii, 0, n) {
      FOR(jj, 0, n) {
        mat[ii][jj] = (jj < i ? matA[ii][jj].first : matA[ii][jj].second);
      }
    }
    pair<int, vi> A = hungarian<int>(mat);
    FOR(ii, 0, n) {
      FOR(jj, 0, n) {
        mat[ii][jj] = (jj < i ? matB[ii][jj].first : matB[ii][jj].second);
      }
    }
    pair<int, vi> B = hungarian<int>(mat);
    if (A.first + B.first < ans) {
      ans = A.first + B.first;
      ansA = A.second;
      ansB = B.second;
      cambio = i;
    }
  }
  cout << ans << ENDL;
  vi antiansB(n);
  FOR(i, 0, n) { antiansB[ansB[i]] = i; }

  FOR(i, 0, n) {
    cout << i + 1 << " " << ansA[i] + 1;
    if (ansA[i] < cambio)
      cout << "A ";
    else
      cout << "B ";
    cout << antiansB[ansA[i]] + 1 << ENDL;
  }

  return 0;
}