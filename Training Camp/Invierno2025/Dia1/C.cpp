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

vi a,b;
ll ans = 0;
ll n;

set<tuple<int,int,int>> st;

void solve(ll i,ll currL,ll currR){
    if(i == n){
        ans = max(ans,lcm(currL,currR));
        return;
    }
    if(st.count({i,currL,currR})) return;
    st.insert({i,currL,currR});

    solve(i+1,gcd(currL,a[i]),gcd(currR,b[i]));
    solve(i+1,gcd(currL,b[i]),gcd(currR,a[i]));
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;
  a.resize(n),b.resize(n);
  FOR(i,0,n) cin >> a[i] >> b[i];

  solve(0,0,0);
  cout << ans << ENDL;

  return 0;
}