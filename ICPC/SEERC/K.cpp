#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

const int MX = 5e3 + 5;  // Tamano maximo del string S

inline int add(int a, int b, const int &mod) { return a + b >= mod ? a + b - mod : a + b; }
inline int sbt(int a, int b, const int &mod) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b, const int &mod) { return 1ll * a * b % mod; }

ll pw[MX];

struct hashing {
  vector<ll> f;

  hashing(string &s) {
    int n = SZ(s);
    f.assign(n + 1, 0);
    FOR(i, 1, n + 1) {
      f[i] = f[i - 1] * 31 + s[i - 1];
    }
  }
  // Hash del substring en el rango [i, j)
  ll value(int l, int r) {
    return f[r] - f[l] * pw[r - l];
  }
};

// Llamar la funcion antes del hashing
void calc_pow() {
  pw[0] = 1;
  FOR(i, 1, MX) {
    pw[i] = pw[i - 1] * 31;
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  calc_pow();
  string a, b;
  cin >> a >> b;
  int n = SZ(a);
  for (auto &c : a) c = tolower(c);
  for (auto &c : b) c = tolower(c);

  hashing ha(a);
  hashing hb(b);
  FOR(i, 1, n) {
    FOR(j, i + 1, n) {
      int l1 = i, l2 = j - i, l3 = n - j;
      ll a1 = ha.value(0, l1), a2 = ha.value(l1, l1 + l2), a3 = ha.value(l1 + l2, n);
      if (a1 == hb.value(0, l1) && a2 == hb.value(l1, l1 + l2) && a3 == hb.value(l1 + l2, n)) {
        cout << "YES" << ENDL;
        cout << a.substr(0, l1) << ENDL;
        cout << a.substr(l1, l2) << ENDL;
        cout << a.substr(l1 + l2) << ENDL;
        return 0;
      }
      if (a1 == hb.value(0, l1) && a3 == hb.value(l1, l1 + l3) && a2 == hb.value(l1 + l3, n)) {
        cout << "YES" << ENDL;
        cout << a.substr(0, l1) << ENDL;
        cout << a.substr(l1, l2) << ENDL;
        cout << a.substr(l1 + l2) << ENDL;
        return 0;
      }
      if (a2 == hb.value(0, l2) && a1 == hb.value(l2, l2 + l1) && a3 == hb.value(l2 + l1, n)) {
        cout << "YES" << ENDL;
        cout << a.substr(0, l1) << ENDL;
        cout << a.substr(l1, l2) << ENDL;
        cout << a.substr(l1 + l2) << ENDL;
        return 0;
      }
      if (a2 == hb.value(0, l2) && a3 == hb.value(l2, l2 + l3) && a1 == hb.value(l2 + l3, n)) {
        cout << "YES" << ENDL;
        cout << a.substr(0, l1) << ENDL;
        cout << a.substr(l1, l2) << ENDL;
        cout << a.substr(l1 + l2) << ENDL;
        return 0;
      }
      if (a3 == hb.value(0, l3) && a1 == hb.value(l3, l3 + l1) && a2 == hb.value(l3 + l1, n)) {
        cout << "YES" << ENDL;
        cout << a.substr(0, l1) << ENDL;
        cout << a.substr(l1, l2) << ENDL;
        cout << a.substr(l1 + l2) << ENDL;
        return 0;
      }
      if (a3 == hb.value(0, l3) && a2 == hb.value(l3, l3 + l2) && a1 == hb.value(l3 + l2, n)) {
        cout << "YES" << ENDL;
        cout << a.substr(0, l1) << ENDL;
        cout << a.substr(l1, l2) << ENDL;
        cout << a.substr(l1 + l2) << ENDL;
        return 0;
      }
    }
  }

  cout << "NO" << ENDL;

  return 0;
}