#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
#define ENDL '\n'
#define FOR(x, n) for (long long x = 0; x < (long long)n; x++)
#define FOR1(x, n) for (long long x = 1; x <= (long long)n; x++)
#define FORR(x, n) for (long long x = n - 1; x >= 0; x--)
#define FORR1(x, n) for (long long x = n; x >= 1; x--)
const long long INF = 1 << 28, MOD = 1e9 + 7, MAXN = 1e5 + 5;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n, p, h;
    cin >> n >> p >> h;
    p--;
    h--;
    vector<int> w;
    string ans = "";

    for (int k = n - 1; k >= 0; k--) {
        w.push_back(h >= (1ll << k));
        if (w.back())
            h = (1ll << (k + 1)) - 1 - h;
    }

    for (int k = n - 1; k >= 0; k--) {
        if (w[k]) {
            if (p < (1ll << k)) {
                ans += 'L';
                p = (1ll << k) - 1 - p;
            } else {
                ans += 'R';
                p = (1ll << k + 1) - 1 - p;
            }
        } else {
            if (p < (1ll << k)) {
                ans += 'R';
            } else {
                ans += 'L';
                p -= (1ll << k);
            }
        }
    }

    cout << ans << ENDL;

    return 0;
}
