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

__int128 abs(__int128 a) {
  if (a >= 0)
    return a;
  else
    return -a;
}

struct Frac {
  __int128 a, b;

  Frac() {}
  Frac(__int128 _a, __int128 _b) {
    assert(_b > 0);
    if ((_a < 0 && _b < 0) || (_a > 0 && _b < 0)) {
      _a = -_a;
      _b = -_b;
    }
    __int128 GCD = __gcd(abs(_a), abs(_b));
    a = _a / GCD;
    b = _b / GCD;
  }

  Frac operator*(Frac f) const { return Frac(a * f.a, b * f.b); }
  Frac operator/(Frac f) const { return (*this) * Frac(f.b, f.a); }
  Frac operator+(Frac f) const { return Frac(a * f.b + b * f.a, b * f.b); }
  Frac operator-(Frac f) const { return Frac(a * f.b - b * f.a, b * f.b); }
  bool operator<(Frac& other) const { return a * other.b < other.a * b; }
  bool operator==(Frac& other) const { return a == other.a && b == other.b; }
  bool operator!=(Frac& other) const { return !(*this == other); }
};

__int128 dp[35][35][35];
int n, m, p;

__int128 solve(int i, int parcial, int faltan) {
  if (i > 0 && !faltan) return 0;
  if (i == 0) return !faltan;
  __int128& ans = dp[i][parcial][faltan];
  if (ans != -1) return ans;
  ans = 0;

  // sale uno parcial
  if (parcial) {
    ans += solve(i - 1, parcial - 1, faltan) * parcial;
  }

  // sale uno vacio
  if (faltan) {
    ans += solve(i - 1, parcial + 1, faltan - 1) * faltan * 2;
  }

  // sale otro numero que no esta en la lista
  int restantes = m - (p - i);
  if (restantes - (2 * faltan + parcial)) {
    ans += solve(i - 1, parcial, faltan) * (restantes - (2 * faltan + parcial));
  }

  return ans;
}

void print(__int128 x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}

// 11:18

signed main() {
  // ios_base::sync_with_stdio(0);
  // cin.tie(nullptr);

  memset(dp, -1, sizeof(dp));

  cin >> m >> n >> p;

  __int128 den = 1;
  FOR(i, 0, p)
  den *= (m - i);
  __int128 num = solve(p, 0, n);
  // print(num);
  Frac ans(num, den);
  print(ans.a);
  cout << "/";
  print(ans.b);
  cout << ENDL;

  return 0;
}