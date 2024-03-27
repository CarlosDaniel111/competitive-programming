#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ll((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define ROF(i, a, b) for (ll i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr ll MOD = 1e9 + 7;
constexpr ll MAXN = 1e5 + 5;
constexpr ll INF = 1e9;
constexpr ll LLINF = 1e18;

struct pila {
  vector<ll> s, smin = {LLONG_MAX}, smax = {LLONG_MIN};
  void push(ll x) {
    s.pb(x);
    smin.pb(min(smin.back(), x));
    smax.pb(max(smax.back(), x));
  }

  ll pop() {
    ll res = s.back();
    s.pop_back();
    smin.pop_back();
    smax.pop_back();
    return res;
  }

  bool empty() {
    return s.empty();
  }

  ll minimo() {
    return smin.back();
  }

  ll maximo() {
    return smax.back();
  }
};

pila s1, s2;

void add(ll x) {
  s2.push(x);
}

void remove() {
  if (s1.empty()) {
    while (!s2.empty())
      s1.push(s2.pop());
  }
  s1.pop();
}

ll k;

bool good() {
  ll mn = ::min(s1.minimo(), s2.minimo());
  ll mx = ::max(s1.maximo(), s2.maximo());
  return mx - mn <= k;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll n;
  cin >> n >> k;
  vi a(n);
  for (auto &x : a) cin >> x;

  ll l = 0;
  ll ans = 0;

  FOR(r, 0, n) {
    add(a[r]);

    while (!good()) {
      remove();
      l++;
    }

    ans += r - l + 1;
  }
  cout << ans << ENDL;

  return 0;
}