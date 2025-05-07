#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
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

void solve() {
  ll xa, ya, xb, yb, h, w;
  cin >> h >> w >> xa >> ya >> xb >> yb;
  ll diff = xb - xa;
  if (diff <= 0) {
    cout << "Draw" << ENDL;
    return;
  }
  // Bob puede ganar
  if (diff % 2 == 0) {
    ll leftA = max(1LL, ya - diff / 2);
    ll rightA = min(w, ya + diff / 2);

    ll leftB = max(1LL, yb - diff / 2);
    ll rightB = min(w, yb + diff / 2);

    if (leftA >= leftB && rightA <= rightB) {
      cout << "Bob" << ENDL;
    } else {
      cout << "Draw" << ENDL;
    }
  } else {  // Alice puede ganar
    ll leftA = max(1LL, ya - (diff + 1) / 2);
    ll rightA = min(w, ya + (diff + 1) / 2);

    ll leftB = max(1LL, yb - diff / 2);
    ll rightB = min(w, yb + diff / 2);

    if (leftB >= leftA && rightB <= rightA) {
      cout << "Alice" << ENDL;
    } else {
      cout << "Draw" << ENDL;
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  ll t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}