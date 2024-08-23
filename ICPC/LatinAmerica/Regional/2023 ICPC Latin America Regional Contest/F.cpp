#include <bits/stdc++.h>
using namespace std;
// AC2++
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define ROF(i, a, b) for (ll i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;
vi arr;

bool checar(ll n, ll x) {
  arr.clear();
  while (n) {
    arr.pb(n % x);
    n /= x;
  }
  FOR(i, 0, SZ(arr)) {
    if (arr[i] != arr[SZ(arr) - i - 1])
      return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  vi ans;
  ll n;
  cin >> n;
  for (ll i = 1; i * i <= n; i++) {
    if (i != 1 && checar(n, i)) {
      ans.pb(i);
    }
    if (n % i == 0) {
      ll aux = n / i;
      if (i < aux - 1)
        ans.pb(aux - 1);
    }
  }

  if (SZ(ans) == 0) {
    cout << "*" << ENDL;
    return 0;
  }

  sort(ALL(ans));
  ans.resize(unique(ALL(ans)) - ans.begin());

  for (auto x : ans) {
    cout << x << " ";
  }

  return 0;
}