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

vector<vi> dirs = {
  {0,1},{1,0},{0,-1},{-1,0},
  {1,0},{0,1},{-1,0},{0,-1}
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;
  vector<vi> a(n,vi(n));
  FOR(i,0,n){
    FOR(j,0,n) cin >> a[i][j];
  }

  auto spiral = [&](ll r,ll c,ll d,int cw) -> vi {
    vector<vi> vis(n,vi(n,0));
    vi res;
    FOR(i,0,n*n){
      res.pb(a[r][c]);
      vis[r][c] = 1;
      ll k = 0;
      while(k++<4){
        ll nr = r + dirs[cw ? d : d+4][0];
        ll nc = c + dirs[cw ? d : d+4][1];
        if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc]){
          r = nr,c = nc;
          break;
        }
        d = (d+1)%4;
      }
    }
    return res;
  };
  vector<tuple<ll,ll,ll>> starts = {{0,0,0},{0,n-1,1},{n-1,n-1,2},{n-1,0,3}};
  ll ans = 0;
  FOR(cw,0,2){
    for(auto [r,c,d]:starts){
      vi s = spiral(r,c,d,cw);
      ll res = s[0];
      ll mx = s[0];
      FOR(i,1,SZ(s)){
        mx = max(mx+s[i],s[i]);
        res = max(res,mx);
      }
      ans = max(ans,res);
    }
  }
  cout << ans << ENDL;

  return 0;
}