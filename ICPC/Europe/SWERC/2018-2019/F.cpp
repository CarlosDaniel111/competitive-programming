#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

typedef ll T;

ll sgn(T x) { return (T(0) < x) - (x < T(0)); }

struct Poll {
  T x, y;

  // Operaciones Punto - Punto
  Poll operator+(Poll p) const { return {x + p.x, y + p.y}; }
  Poll operator-(Poll p) const { return {x - p.x, y - p.y}; }
  Poll operator*(Poll b) const { return {x * b.x - y * b.y, x * b.y + y * b.x}; }

  // Operaciones Punto - Numero
  Poll operator*(T d) const { return {x * d, y * d}; }
  Poll operator/(T d) const { return {x / d, y / d}; }  // Solo para punto flotante

  // Operaciones de comparacion para enteros
  bool operator<(Poll p) const { return tie(x, y) < tie(p.x, p.y); }
  bool operator==(Poll p) const { return tie(x, y) == tie(p.x, p.y); }

  T sq() { return x * x + y * y; }
  double norm() { return sqrt(sq()); }
  Poll unit() { return *this / norm(); }

  T dot(Poll p) { return x * p.x + y * p.y; }
  T cross(Poll p) const { return x * p.y - y * p.x; }
  T cross(Poll a, Poll b) const { return (a - *this).cross(b - *this); }

  friend ostream& operator<<(ostream& os, Poll p) {
    return os << "(" << p.x << "," << p.y << ")";
  }
};

ll half(Poll p) { return p.y > 0 || (p.y == 0 && p.x < 0); }

void polarSortAround(Poll o, vector<Poll>& v) {
  sort(ALL(v), [&o](Poll v, Poll w) {
    return make_tuple(half(v - o), 0) < make_tuple(half(w - o), (v - o).cross(w - o));
  });
}

bool half2(Poll v, Poll p) {
  return v.cross(p) < 0 || (v.cross(p) == 0 && v.dot(p) < 0);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll n;
  cin >> n;
  vector<Poll> pts(n);
  ll tot = 0;
  vi val(n);
  map<pi, ll> mapa;
  FOR(i, 0, n) {
    cin >> pts[i].x >> pts[i].y >> val[i];
    tot += val[i];
    mapa[{pts[i].x, pts[i].y}] = i;
  }
  ll ans = 3e15;
  FOR(k, 0, n) {
    vector<Poll> pts2;
    FOR(i, 0, n) {
      if (i == k) continue;
      pts2.pb(pts[i]);
    }
    polarSortAround(pts[k], pts2);
    cout << pts2[1] << ENDL;
    ll j = 1;
    ll left = 0;
    FOR(i, 0, n - 1) {
      if (i != 0) {
        left -= val[mapa[{pts2[i].x, pts2[i].y}]];
      }
      while (i != j && !half2(pts2[i], pts2[j])) {
        left += val[mapa[{pts2[j].x, pts2[j].y}]];
        j = (j + 1) % (n - 1);
      }
      // left -= val[mapa[{pts2[i].x, pts2[i].y}]];
      ll right = tot - left - val[k];
      cout << left << " " << right << ENDL;
      ans = min(ans, abs(left - right));
    }
  }

  cout << ans << ENDL;

  return 0;
}