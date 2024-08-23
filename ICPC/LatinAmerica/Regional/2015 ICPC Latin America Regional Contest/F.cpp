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

struct FT {
  vector<ll> s;
  FT(int n) : s(n) {}
  void update(int pos, ll dif) {  // a[pos] += dif
    for (; pos < SZ(s); pos |= pos + 1) s[pos] += dif;
  }
  ll query(int pos) {  // sum of values in [0, pos)
    ll res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos - 1];
    return res;
  }
};

struct Vertical {
  int x, y1, y2;
};

struct Planta {
  int x, y, id;
};

bool cmpPlanta(Planta p1, Planta p2) {
  return tie(p1.x, p1.y, p1.id) < tie(p2.x, p2.y, p2.id);
}

bool cmpVertical(Vertical v1, Vertical v2) {
  return tie(v1.x, v1.y1, v1.y2) < tie(v2.x, v2.y1, v2.y2);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int p, v;
  cin >> p >> v;
  vi x(p + v);
  vi y(p + v);
  vector<Planta> plantas(p);
  FOR(i, 0, p) {
    cin >> x[i] >> y[i];
    plantas[i] = {x[i], y[i], i + 1};
  }
  vector<pi> poly(v);
  FOR(i, 0, v) {
    cin >> poly[i].first >> poly[i].second;
    x[i + p] = poly[i].first, y[i + p] = poly[i].second;
  }
  vector<Vertical> vertical;
  FOR(i, 0, v) {
    if (poly[i].first == poly[(i + 1) % v].first) {
      vertical.pb({poly[i].first, min(poly[i].second, poly[(i + 1) % v].second),
                   max(poly[i].second, poly[(i + 1) % v].second)});
    }
  }
  sort(ALL(x));
  sort(ALL(y));
  sort(ALL(vertical), cmpVertical);
  sort(ALL(plantas), cmpPlanta);

  // MAPEO
  map<int, int> mx, my;
  mx[x[0]] = 1;
  int cnt = 2;
  FOR(i, 1, p + v) {
    if (x[i] != x[i - 1]) mx[x[i]] = cnt++;
  }
  my[y[0]] = 1;
  cnt = 3;
  FOR(i, 1, p + v) {
    if (y[i] != y[i - 1]) {
      my[y[i]] = cnt;
      cnt += 2;
    }
  }
  FT ft(cnt + 10);
  int curr = 0;
  ll ans = 0;
  FOR(i, 0, p) {
    int x1 = mx[plantas[i].x], y1 = my[plantas[i].y];
    while (curr < SZ(vertical)) {
      int xl = mx[vertical[curr].x], v1 = my[vertical[curr].y1],
          v2 = my[vertical[curr].y2];
      if (xl >= x1) {
        int aux = ft.query(y1 + 2);
        if (aux % 2 == 0) ans += plantas[i].id;
        break;
      } else {
        ft.update(v1, 1);
        ft.update(v2 + 1, -1);
        curr++;
      }
    }
    if (curr == SZ(vertical)) ans += plantas[i].id;
  }
  cout << ans << ENDL;

  return 0;
}