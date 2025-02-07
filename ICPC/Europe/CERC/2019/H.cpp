#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

struct AhoCorasick {
  enum { alpha = 26, first = 'a' };
  struct Node {
    ll back, next[alpha], start = -1, end = -1, nmatches = 0;
    Node(ll v) { memset(next, v, sizeof(next)); }
  };
  vector<Node> N;
  vi backp;
  void insert(string& s, ll j) {
    assert(!s.empty());
    ll n = 0;
    for (char c : s) {
      ll& m = N[n].next[c - first];
      if (m == -1) {
        n = m = SZ(N);
        N.emplace_back(-1);
      } else
        n = m;
    }
    if (N[n].end == -1) N[n].start = j;
    backp.push_back(N[n].end);
    N[n].end = j;
    N[n].nmatches++;
  }
  AhoCorasick(vector<string>& pat) : N(1, -1) {
    FOR(i, 0, SZ(pat))
    insert(pat[i], i);
    N[0].back = SZ(N);
    N.emplace_back(0);

    queue<ll> q;
    for (q.push(0); !q.empty(); q.pop()) {
      ll n = q.front(), prev = N[n].back;
      FOR(i, 0, alpha) {
        ll &ed = N[n].next[i], y = N[prev].next[i];
        if (ed == -1)
          ed = y;
        else {
          N[ed].back = y;
          (N[ed].end == -1 ? N[ed].end : backp[N[ed].start]) = N[y].end;
          N[ed].nmatches += N[y].nmatches;
          q.push(ed);
        }
      }
    }
  }

  vector<vi> getMatrix() {
    vector<vi> mat(SZ(N), vi(SZ(N), 0));
    FOR(i, 0, SZ(N)) {
      FOR(j, 0, 26) {
        if (!N[N[i].next[j]].nmatches) {
          mat[i][N[i].next[j]]++;
        }
      }
    }
    return mat;
  }
};

constexpr ll MOD = 1e9 + 7;

template <typename T>
struct Matrix {
  using VVT = vector<vector<T>>;

  VVT M;
  ll n;

  Matrix(VVT aux) : n(SZ(aux)), M(aux) {}

  Matrix operator*(Matrix& other) const {
    assert(SZ(M[0]) == SZ(other.M));
    ll k = SZ(other.M[0]);
    VVT C(n, vector<T>(k, 0));
    FOR(i, 0, SZ(M))
    FOR(j, 0, k)
    FOR(l, 0, SZ(M[0]))
    C[i][j] = (C[i][j] + M[i][l] * other.M[l][j] % MOD) % MOD;
    return Matrix(C);
  }

  Matrix operator^(ll p) const {
    assert(p >= 0);
    Matrix ret(VVT(n, vector<T>(n))), B(*this);
    FOR(i, 0, n) { ret.M[i][i] = 1; }
    while (p) {
      if (p & 1) ret = ret * B;
      p >>= 1;
      B = B * B;
    }
    return ret;
  }

  void prll() {
    cout << "--------------------" << ENDL;
    FOR(i, 0, n) {
      FOR(j, 0, n) { cout << M[i][j] << ' '; }
      cout << ENDL;
    }
    cout << "******************" << ENDL;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n, q;
  cin >> n >> q;
  vector<string> pat(q);
  FOR(i, 0, q) {
    ll x;
    cin >> x >> pat[i];
  }
  AhoCorasick aho(pat);
  vector<vi> m = aho.getMatrix();
  Matrix<ll> mat(m);
  mat = mat ^ n;
  ll ans = 0;
  FOR(i, 0, mat.n) { (ans += mat.M[0][i]) %= MOD; }
  cout << ans << ENDL;

  return 0;
}