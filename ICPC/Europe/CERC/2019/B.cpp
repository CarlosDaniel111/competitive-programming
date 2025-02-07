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

constexpr ll MOD = 1e9 + 7;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;
  vi a(n + 5, 0);
  FOR(i, 1, n + 1) { cin >> a[i]; }
  vector<vi> gcdL(n + 5);
  FOR(i, 1, n + 1) {
    gcdL[i].pb(i);
    ll curr = a[i];
    for (auto j : gcdL[i - 1]) {
      if (gcd(curr, a[j]) == curr) continue;
      curr = gcd(curr, a[j]);
      gcdL[i].pb(j);
    }
  }

  vector<vi> gcdR(n + 5);
  ROF(i, n + 1, 1) {
    gcdR[i].pb(i);
    ll curr = a[i];
    for (auto j : gcdR[i + 1]) {
      if (gcd(curr, a[j]) == curr) continue;
      curr = gcd(curr, a[j]);
      gcdR[i].pb(j);
    }
  }

  vi leftGreater(n + 5);
  stack<ll> st;
  for (ll i = 1; i <= n; ++i) {
    while (!st.empty() && a[st.top()] < a[i]) {
      st.pop();
    }
    leftGreater[i] = st.empty() ? 0 : st.top();
    st.push(i);
  }
  while (SZ(st)) st.pop();
  vi rightGreater(n + 5);
  for (ll i = n; i >= 1; i--) {
    while (!st.empty() && a[st.top()] <= a[i]) {
      st.pop();
    }
    rightGreater[i] = st.empty() ? n + 1 : st.top();
    st.push(i);
  }

  ll ans = 0;
  FOR(i, 1, n + 1) {
    while (SZ(gcdL[i]) && gcdL[i].back() <= leftGreater[i]) gcdL[i].pop_back();
    gcdL[i].pb(leftGreater[i]);
    while (SZ(gcdR[i]) && gcdR[i].back() >= rightGreater[i]) gcdR[i].pop_back();
    gcdR[i].pb(rightGreater[i]);
    ll currGCDL = a[i], prevL = i;
    for (auto l : gcdL[i]) {
      ll currGCDR = a[i], prevR = i;
      for (auto r : gcdR[i]) {
        (ans += (prevL - l) * (r - prevR) % MOD * gcd(currGCDL, currGCDR) %
                MOD * a[i] % MOD) %= MOD;
        currGCDR = gcd(currGCDR, a[r]);
        prevR = r;
      }
      currGCDL = gcd(currGCDL, a[l]);
      prevL = l;
    }
  }
  cout << ans << ENDL;

  return 0;
}