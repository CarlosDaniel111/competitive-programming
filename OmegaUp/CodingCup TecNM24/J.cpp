#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;

#define pb push_back
#define FOR(i,a,b) for(ll i = (ll)a; i < (ll)b; i++)
#define ROF(i,a,b) for(ll i = (ll)a - 1; i >= (ll)b; --i)
#define SZ(x) ((ll)x.size())
#define ALL(x) begin(x),end(x)
#define ENDL '\n'

signed main() {
    ll o, e, p;
    cin >> o >> e >> p;
    vector<ll> a(o + e);
    FOR (i, 0, o) cin >> a[i];
    FOR (i, 0, e) {
        cin >> a[o + i];
        a[o + i] *= -1;
    }
    ll n = o + e;
    set<ll> left;
    ll mitad = n / 2;
    FOR (msk, 0, (1 << mitad)) {
        ll s = 0;
        FOR (i, 0, mitad) if ((msk >> i) & 1) s += a[i];
        left.insert(s);
    }
    while (p--) {
        ll x;
        cin >> x;
        bool can = 0;
        FOR (msk, 0, (1 << (n - mitad))) {
            ll s = 0;
            FOR (i, mitad, n) if ((msk >> (i - mitad)) & 1) s += a[i];
            if (left.count(x - s)) {
                can = 1;
                break;
            }
        }
        cout << (can ? "Merece ser finalista" : "Hizo trampa") << ENDL;
    }
    return 0; 
}