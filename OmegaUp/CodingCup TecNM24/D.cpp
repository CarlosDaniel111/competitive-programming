#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a - 1; i >= (int)b; --i)
#define SZ(x) ((int)x.size())
#define pb push_back
#define ALL(x) begin(x),end(x)
#define ENDL '\n'

vector<int> cnt;
vector<vi> g(100005);
set<int> platillos;

bool cucking(int u){
    if(cnt[u]){
        return true;
    }
    if(!platillos.count(u)){
        if(cnt[u]){
            return true;
        }
        return false;
    }
    for(auto v:g[u]){
        if(!cucking(v)) return false;
    }
    return true;
}

signed main() {
    int n;
    cin >> n;
    map<string,int> mp;
    string _;


    
    getline(cin,_);
    FOR(i,0,n){
        string linea;
        getline(cin,linea);
        int ant = 0,pl;
        FOR(i,0,SZ(linea)){
            if(linea[i] == ' '){
                if(ant == 0){
                    string plat = linea.substr(0,i);
                    
                    if(!mp.count(plat)){
                        mp[plat] = SZ(mp);
                    }
                        
                    platillos.insert(mp[plat]);
                    pl = mp[plat];
                    ant = i+1;
                    continue;
                }
                string s = linea.substr(ant,i-ant);
                
                //cout << s << ENDL;
                if(!mp.count(s))
                    mp[s] = SZ(mp);
                g[pl].pb(mp[s]);
                ant = i+1;
            }
        }
        string s = linea.substr(ant);
        //cout << s << ENDL;
        if(!mp.count(s))
            mp[s] = SZ(mp);
        g[pl].pb(mp[s]);
    }
    cnt.assign(SZ(mp)+5,0);
    int m;
    cin >> m;
    FOR(i,0,m){
        string s;
        cin >> s;
        cnt[mp[s]]++;
    }
    string s;
    cin >> s;
    cout << (cucking(mp[s]) ? "OK" :"NO") << ENDL;
}