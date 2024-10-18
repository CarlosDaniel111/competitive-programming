#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i,a,b) for(int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

signed main() {
    ll n;
    cin >> n;
    int first_bit;
    ROF (i, 64, 0) {
        if ((n >> i) & 1) {
            first_bit = i;
            break;
        }
    }
    ull low = (1ull << (first_bit + 1)) - 1;
    ROF (i, first_bit, 0) {
        if (!((n >> i) & 1)) {
            low ^= 1ull << (i + 1);
            cout << n - low + 1 << ENDL;
            return 0;
        }
    }
    cout << 1 << ENDL;
}