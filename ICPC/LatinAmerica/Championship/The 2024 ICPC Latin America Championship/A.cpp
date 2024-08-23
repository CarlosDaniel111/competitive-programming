#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using ld = long double;
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

constexpr long double EPS = 1e-12;

struct Quad {
  ll a, b, c;

  ld eval(ld x) const {
    return a * x * x + b * x + c;
  }

  ld minimum(ld l, ld r) const {
    if (r < l) {
      return INFINITY;
    }
    if (abs(a) < EPS) {
      return min(eval(l), eval(r));
    }
    ld x = -b / (2.0 * a);
    if (x < l || x > r) {
      return min(eval(l), eval(r));
    }
    return min(eval(l), min(eval(r), eval(x)));
  }
};

struct Line {
  ll k, b;

  ld intersect(const Line &other) const {
    return (ld)(other.b - b) / (k - other.k);
  }

  Line sub(const Line &other) const {
    return {k - other.k, b - other.b};
  }

  Line add(const Line &other) const {
    return {k + other.k, b + other.b};
  }

  Quad mul(const Line &other) const {
    return {k * other.k, k * other.b + b * b * other.k, b * other.b};
  }
};

static pair<vector<Line>, vector<ld>> partMax(vector<Line> lines) {
  sort(ALL(lines), [](const Line &a, const Line &b) {
    if (a.k == b.k) {
      return a.b > b.b;
    }
    return a.k < b.k;
  });

  vector<Line> result;
  vector<ld> intersection;
  result.pb(lines[0]);
  FOR(i, 1, SZ(lines)) {
    if (lines[i].k == lines[i - 1].k) continue;
    while (SZ(intersection) >= 1 && result.back().intersect(lines[i]) <= intersection.back()) {
      intersection.pop_back();
      result.pop_back();
    }
    result.push_back(lines[i]);
    if (SZ(result) >= 2) {
      intersection.pb(result[SZ(result) - 2].intersect(result[SZ(result) - 1]));
    }
    return {result, intersection};
  }
}

signed
main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<Line> lines[4];
  FOR(i, 0, n) {
    int x, y, vx, vy;
    cin >> x >> y >> vx >> vy;
    lines[0].pb({-vx, -x});
    lines[1].pb({vx, x});
    lines[2].pb({-vy, -y});
    lines[3].pb({vy, y});
  }
  pair<vector<Line>, vector<ld>> maxes[4] = {
      partMax(lines[0]),
      partMax(lines[1]),
      partMax(lines[2]),
      partMax(lines[3])};
  int p[4] = {0, 0, 0, 0};
  vector<pair<ld, int>> events;
  FOR(i, 0, 4) {
    FOR(j, 0, SZ(maxes[i].second)) {
      events.pb({maxes[i].second[j], i});
    }
  }
  sort(ALL(events));
  ld ans = INFINITY;
  ld prevEvent = 0;
  for (auto [t, i] : events) {
    ld m = maxes[0].first[p[0]].add(maxes[1].first[p[1]]).mul(maxes[2].first[p[2]].add(maxes[3].first[p[3]])).minimum(prevEvent, t);
    ans = min(ans, m);
    prevEvent = max(prevEvent, t);
    p[i]++;
  }
  ld m = maxes[0].first[p[0]].add(maxes[1].first[p[1]]).mul(maxes[2].first[p[2]].add(maxes[3].first[p[3]])).minimum(prevEvent, INFINITY);
  ans = min(ans, m);
  cout << fixed << setprecision(16) << ans << ENDL;

  return 0;
}