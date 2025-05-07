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

constexpr ll MOD = 98765431;

ll be(ll a, ll b, ll m = MOD) {
  ll res = 1;
  a %= m;
  while (b) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

vi p1,p2;
set<vi> st;
ll n,m;

ll ans;

void solve(vi a){
  if(st.count(a)) return;
  st.insert(a);
  ll ciclos = 0;
  vi vis(n,0);

  FOR(i,0,n){
    if(!vis[i]){
      ciclos++;
      ll curr = i;
      do{
        vis[curr] = 1;
        curr = a[curr]; 
      }while(curr != i);
    }
  }

  ans += be(m,ciclos);
  ans%=MOD;

  vi opc1(n);
  FOR(i,0,n) opc1[i] = a[p1[i]];
  solve(opc1);
  vi opc2(n);
  FOR(i,0,n) opc2[i] = a[p2[i]];
  solve(opc2);
}

void solve(){
  st.clear();
  ans = 0;
  cin >> n >> m;
  p1.resize(n),p2.resize(n);
  FOR(i,0,n){
    cin >> p1[i];
    p1[i]--;
  } 
  FOR(i,0,n){
    cin >> p2[i];
    p2[i]--;
  } 

  vi arr(m);
  iota(ALL(arr),0);
  solve(arr);
  ans = ans * be(SZ(st),MOD-2) %MOD;
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll t;
  cin >> t;
  while(t--) solve();

  return 0;
}