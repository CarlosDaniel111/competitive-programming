#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;

#define pb push_back
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a - 1; i >= (int)b; --i)
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define ENDL '\n'

signed main() {
    int n;
    cin >> n;

    map<string, string> ant, sig;
    FOR (i, 0, n) {
        string a, b;
        cin >> a >> b;
        ant[b] = a;
        sig[a] = b;
    }

    map<string, pair<string, string>> ans;
    {
        vector<string> hojas;
        for (auto &[a, b] : sig) {
            if (!sig.count(b)) {
                hojas.pb(b);
            }
        }
        for (auto &u : hojas) {
            string curr = u;
            while (1) {
                ans[curr].second = u;
                if (!ant.count(curr)) break;
                curr = ant[curr];
            }
            string first = curr;
            while (1) {
                ans[curr].first = first;
                if (!sig.count(curr)) break;
                curr = sig[curr];
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        string a;
        cin >> a;
        cout << ans[a].first << ' ' << ans[a].second << ENDL;
    }
    return 0; 
}