#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n,m;
  cin >> n >> m;
  vi a(1<<n);
  iota(a.begin(),a.end(),0);
  auto applyCNot = [&](int c,int t) -> void {
    for(auto &x:a){
      if((x>>c) & 1){
        x^= (1<<t);
      }
    }
  };

  auto applyCCNot = [&](int c1,int c2,int t) -> void {
    for(auto &x:a){
      if(((x>>c1) & 1) && ((x>>c2)&1)){
        x^= (1<<t);
      }
    }
  };
  while(m--){
    int op;
    cin >> op;
    if(op == 1){
      int c,t;
      cin >> c >> t;
      applyCNot(c,t);
    }else{
      int c1,c2,t;
      cin >> c1>>c2 >>t;
      applyCCNot(c1,c2,t);
    }
  }

  for(auto x:a){
    for(int i=0;i<1<<n;i++){
      if(i == x) cout << 1;
      else cout << 0;
    }
    cout << '\n';
  }

  return 0;
}