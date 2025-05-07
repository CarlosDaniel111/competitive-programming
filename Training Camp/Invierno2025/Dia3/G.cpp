#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

array<vi, 2> manacher(string s) {
  int n = SZ(s);
  array<vi, 2> p = {vi(n + 1), vi(n)};
  FOR(z, 0, 2)
  for (int i = 0, l = 0, r = 0; i < n; i++) {
    int t = r - i + !z;
    if (i < r) p[z][i] = min(t, p[z][l + t]);
    int L = i - p[z][i], R = i + p[z][i] - !z;
    while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1])
      p[z][i]++, L--, R++;
    if (R > r) l = L, r = R;
  }
  return p;
}

array<vi,2> man;

int solve(int l,int r){
    if((r-l) <= 2) return r-l;
    
    int ans = r-l;
    FOR(i,l,r){
      if(man[0][i]>=1){
        int m = (r-l)/2;
        int nl =max(i-man[0][i],i-m);
        int nr = i;
        int tam = nr-nl;
        //cout << nl << " "<<nr << ENDL;
        ans = min(ans,solve(nl,nr)+r-l-tam*2+1);
      }
    }
    return ans;
}

void caso(){
    string s;
    cin >> s;
    man =manacher(s);
    cout << solve(0,SZ(s))<<ENDL;
    //cout << "---"<<ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while(t--) caso();

  return 0;
}