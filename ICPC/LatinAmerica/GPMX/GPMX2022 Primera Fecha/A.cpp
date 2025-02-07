#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

const int D = 60;
ll basis[D];
int dim;

// To check if an element is in the span, do the same
// but, if !basis[i] return false, otherwise true.
void insert_vector(ll k) {
  for (int i = D - 1; i >= 0; i--) {
    if (!(k >> i & 1)) continue;
    if (!basis[i]) {
      basis[i] = k;
      dim++;
      return;
    }
    k ^= basis[i];
  }
}

// k-th smallest in linspace
ll get_kth(ll k) {
  ll x = 0;
  int pref = dim;
  for (ll i = D - 1; i >= 0; i--) {
    if (!basis[i]) continue;
    ll p2 = 1ll << (pref - 1);
    ll mini_leq = 1;
    ll maxi_leq = p2;
    if (!(x >> i & 1)) mini_leq += p2, maxi_leq += p2;
    if (mini_leq <= k && maxi_leq >= k) {
      if (!(x >> i & 1)) k -= p2;
      x ^= basis[i];
    } else if (x >> i & 1)
      k -= p2;
    pref--;
  }
  return x;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  ull tot = 0;
  vector<ll> a(n);
  FOR(i, 0, n) {
    cin >> a[i];
    tot ^= a[i];
  }
  FOR(i, 0, n) { insert_vector(a[i] & (~tot)); }
  ll b = get_kth(1ll << dim);
  cout << b + (b xor tot) << ENDL;

  return 0;
}