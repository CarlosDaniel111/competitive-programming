#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    int x;
    cin >> x;
    for(int i=1;i<n;i++){
        int curr = abs(a[i]-a[i-1]);
        if(curr > x){
            cout << "Inseguro" << "\n";
            return 0;
        }
    }
    cout << "Seguro" << "\n";
}