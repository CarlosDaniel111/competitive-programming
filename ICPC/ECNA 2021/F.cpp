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

struct Circle {
  double x, y, r, s;

  bool operator==(Circle ot) { return tie(x, y, r, s) == tie(ot.x, ot.y, ot.r, ot.s); }
};

double dist(Circle a, Circle b) {
  return hypot(a.x - b.x, a.y - b.y) - a.r - b.r;
}

bool yaEsta(vector<Circle> &c, Circle a) {
  FOR(i, 0, SZ(c)) {
    if (c[i] == a) return true;
  }
  return false;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<Circle> c(n);
  FOR(i, 0, n) {
    cin >> c[i].x >> c[i].y >> c[i].r >> c[i].s;
  }

  while (SZ(c) > 1) {
    vector<Circle> chocan;
    double mn = DBL_MAX;
    set<int> usados;
    usados.clear();

    FOR(i, 0, SZ(c)) {
      FOR(j, i + 1, SZ(c)) {
        double t = max(dist(c[i], c[j]), 0.0) / (c[i].s + c[j].s);

        if (t < mn) {
          mn = t;
          chocan.clear();
          chocan.pb(c[i]), chocan.pb(c[j]);
          usados.clear();
          usados.insert(i), usados.insert(j);
        } else if (t == mn) {
          if (!usados.count(i)) {
            chocan.pb(c[i]);
            usados.insert(i);
          }
          if (!usados.count(j)) {
            usados.insert(j);
            chocan.pb(c[j]);
          }
        }
      }
    }
    double sumX = 0, sumY = 0, sumR = 0, vel = 0;

    for (auto cir : chocan) {
      sumX += cir.x;
      sumY += cir.y;
      cir.r += cir.s * mn;
      sumR += cir.r * cir.r;
      vel = max(vel, cir.s);
    }

    vector<Circle> nuevo;
    nuevo.pb({sumX / SZ(chocan), sumY / SZ(chocan), sqrt(sumR), vel});

    FOR(i, 0, SZ(c)) {
      if (!usados.count(i)) {
        c[i].r += c[i].s * mn;
        nuevo.pb(c[i]);
      }
    }

    c = nuevo;
  }
  cout << setprecision(9) << fixed;
  cout << c[0].x << " " << c[0].y << ENDL;
  cout << c[0].r << ENDL;

  return 0;
}