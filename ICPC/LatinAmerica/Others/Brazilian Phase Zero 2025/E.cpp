#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

vector<ll> divisores(ll x){
  vi div;
  for(ll i=2;i*i<=x;i++){
    while(x%i == 0){
      div.push_back(i);
      x/=i;
    }
  }
  if(x!=1) div.push_back(x);
  return div;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  long long y,k,x=1;
  cin >> y >> k;
  vi divs = divisores(y);

  int m = (int)divs.size();
  for(int i=0;i<m;i++){
    if(divs[i]-1>k){
      cout << x+ x * k << '\n';
      return 0;
    }
    k-=divs[i]-1;
    x = x*divs[i];
  }
  cout << x + y*k << '\n';


  return 0;
}
// 500928565680
// 500928565680
// 110483
// 2 * 3^2 * 5 = 90
// 2 + 2*2 = 2 * 3
// 2 * 3 + 2 * 3 * k
// 2 * 3 * (1 + k) K = 2

// D = []
// dx % d0 == 0