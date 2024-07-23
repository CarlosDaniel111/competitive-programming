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
  vi a(n), leftSmaller(n, 0), rightSmaller(n, 0);
  FOR(i, 0, n) cin >> a[i];

  stack<ll> st;
  FOR(i, 0, n) {
    while (!st.empty() && a[st.top()] > a[i]) st.pop();
    if (st.empty())
      leftSmaller[i] = 0;
    else
      leftSmaller[i] = st.top() + 1;
    st.push(i);
  }

  while (SZ(st)) st.pop();
  ROF(i, n, 0) {
    while (!st.empty() && a[st.top()] >= a[i]) st.pop();
    if (st.empty())
      rightSmaller[i] = n - 1;
    else
      rightSmaller[i] = st.top() - 1;
    st.push(i);
  }

  ll Emax = 0;
  FOR(i, 0, n) {
    ll l = i - leftSmaller[i], r = rightSmaller[i] - i;
    Emax += (l + r + l * r) * a[i];
  }

  vi leftGreater(n), rightGreater(n);

  while (SZ(st)) st.pop();
  FOR(i, 0, n) {
    while (!st.empty() && a[st.top()] < a[i]) st.pop();
    if (st.empty())
      leftGreater[i] = 0;
    else
      leftGreater[i] = st.top() + 1;
    st.push(i);
  }

  while (SZ(st)) st.pop();
  ROF(i, n, 0) {
    while (!st.empty() && a[st.top()] <= a[i]) st.pop();
    if (st.empty())
      rightGreater[i] = n - 1;
    else
      rightGreater[i] = st.top() - 1;
    st.push(i);
  }

  ll Emin = 0;
  FOR(i, 0, n) {
    ll l = i - leftGreater[i], r = rightGreater[i] - i;
    Emin += (l + r + l * r) * a[i];
  }
  cout << abs(Emax - Emin) << ENDL;

  return 0;
}