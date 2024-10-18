#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

signed main() {

    int l,n;
    cin >> l>>n;
    vi a(n);
    FOR(i,0,n){
        cin >> a[i];
    }
    reverse(a.begin(),a.end());
    int par = 0,impar = 0;
    FOR(i,0,min(l,n)){
        if(a[i]%2 == 0){
            par++;
        }else{
            impar++;
        }
        if(par && impar){
            cout << i+1 << ENDL;
            return 0;
        }
    }
    if(l>=n){
        cout << "Do not worry Bob" << ENDL;
        return 0;
    }
    FOR(i,l,n){
        if(a[i-l] % 2 == 0){
            par--;
        }else{
            impar--;
        }
        if(a[i]%2 == 0){
            par++;
        }else{
            impar++;
        }
        if(par && impar){
            cout << i+1 << ENDL;
            return 0;
        }
    }
        cout << "Do not worry Bob" << ENDL;
        return 0;
    
}