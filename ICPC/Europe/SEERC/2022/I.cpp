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

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;
  vi a(n + 2, 0);
  FOR(i, 1, n + 1) cin >> a[i];

  vi gl(n + 1, 0);
  stack<ll> st;
  FOR(i, 1, n + 1) {
    while (!st.empty() && a[st.top()] > a[i]) st.pop();
    if (st.empty())
      gl[i] = 0;
    else
      gl[i] = st.top();
    st.push(i);
  }
  while (SZ(st)) st.pop();

  vi gr(n + 1, n + 1);
  ROF(i, n + 1, 1) {
    while (!st.empty() && a[st.top()] >= a[i]) st.pop();
    if (st.empty())
      gr[i] = n + 1;
    else
      gr[i] = st.top();
    st.push(i);
  }

  ll ans = 0;
  FOR(i, 1, n + 1) {
    ans += (gr[i] - gl[i]) / 2 * min(a[i] - a[gl[i]], a[i] - a[gr[i]]);
  }
  cout << ans << ENDL;

  return 0;
}