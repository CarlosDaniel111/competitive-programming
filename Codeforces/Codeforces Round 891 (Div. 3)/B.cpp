#include <bits/stdc++.h>
using namespace std;
// AC2++
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

void solve() {
    string n;
    cin >> n;
    string original = n;
    bool carry = false;
    int ultimo = -1;
    ROF(i, SZ(n), 0) {
        if (carry) {
            n[i]++;
            ultimo = i;
            if (n[i] > '9') {
                n[i] = '0';
                carry = true;
            } else {
                carry = false;
            }
        }
        if (n[i] >= '5') {
            n[i] = '0';
            carry = true;
        }
    }

    if (carry) {
        cout << "1";
        FOR(i, 0, SZ(original)) {
            cout << "0";
        }
        cout << ENDL;
        return;
    }
    if (ultimo != -1) {
        FOR(i, 0, ultimo + 1) {
            cout << n[i];
        }
        FOR(i, ultimo + 1, SZ(original)) {
            cout << '0';
        }
        cout << ENDL;
    } else {
        cout << original << ENDL;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}