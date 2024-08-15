#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

struct Nodo {
  ll l, r, c;

  bool operator<(const Nodo &o) const {
    return l < o.l;
  }
};

signed
main() {
  cin.tie(0)->sync_with_stdio(0);

  ll L, C, N;
  cin >> L >> C >> N;
  set<Nodo> s;
  vi cnt(C + 1, 0);
  cnt[1] = L;
  s.insert({0, L - 1, 1});
  FOR(_, 0, N) {
    ll P, X, A, B;
    cin >> P >> X >> A >> B;
    ll S = cnt[P];
    ll m1 = (A + S * S) % L;
    ll m2 = (A + (S + B) * (S + B)) % L;
    if (m1 > m2) swap(m1, m2);
    cnt[X] += m2 - m1 + 1;
    Nodo i = {m1, m2, X};
    auto it1 = s.lower_bound(i);
    if (it1 != s.begin() && prev(it1)->r >= m1) it1--;
    auto it2 = next(it1);
    while (it2 != s.end() && it2->l <= m2) it2++;

    for (auto it = it1; it != it2; it++) {
      ll l = max(it->l, m1);
      ll r = min(it->r, m2);
      cnt[it->c] -= r - l + 1;
    }
    Nodo l = *it1;
    Nodo r = *prev(it2);
    s.erase(it1, it2);
    s.insert(i);
    if (l.l < m1) s.insert({l.l, m1 - 1, l.c});
    if (r.r > m2) s.insert({m2 + 1, r.r, r.c});
  }
  cout << *max_element(ALL(cnt)) << ENDL;

  return 0;
}