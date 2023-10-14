#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<double>;
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>;

// pairs
#define mp make_pair
#define f first
#define s second

// vectors
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define tcT template <class T
tcT > int lwb(vector<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }

// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define R0F(i, a) ROF(i, a, 0)

#define ENDL '\n'
#define LSOne(S) ((S) & -(S))

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int INF = 1 << 28;
const ll LLINF = 1e18;
const int dx[4] = {1, 0, -1, 0},
          dy[4] = {0, 1, 0, -1};  // abajo, derecha, arriba, izquierda

template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

using pt = pair<double, double>;

double dist(pt a, pt b) {
  return sqrt((a.f - b.f) * (a.f - b.f) + (a.s - b.s) * (a.s - b.s));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int h[n];
  F0R(i, n) { cin >> h[i]; }
  sort(h, h + n);

  vector<pt> pts(n);
  double sep = (2 * 3.14159265359) / (n * 1.0), angles[n];
  angles[0] = 0;
  for (int i = 1; i < n; i++) {
    angles[i] = angles[i - 1] + sep;
  }

  pt pol[n];
  int cnt = 0;
  for (int i = n - 1; i >= 0; i -= 2) {
    pol[cnt] = make_pair(angles[cnt], h[i]);
    cnt++;
  }
  for (int i = n % 2; i < n; i += 2) {
    pol[cnt] = mp(angles[cnt], h[i]);
    cnt++;
  }

  pt rect[n];
  F0R(i, n) {
    rect[i] = mp(pol[i].s * cos(pol[i].f), pol[i].s * sin(pol[i].f));
  }

  double area = 0;
  for (int i = 0; i < n; i++) {
    double a, b, c;
    a = dist(mp(0, 0), rect[i]);
    b = dist(mp(0, 0), rect[(i + 1) % n]);
    c = dist(rect[i], rect[(i + 1) % n]);
    double s2 = (a + b + c) / 2;
    area += sqrt(s2 * (s2 - a) * (s2 - b) * (s2 - c));
  }
  cout << setprecision(3) << fixed;
  cout << area << ENDL;

  return 0;
}