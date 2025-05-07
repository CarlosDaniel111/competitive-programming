#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

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
    ll n, c;
    cin >> n >> c;
    vector<ll> s(n);
    ll area = 0;
    FOR(i, 0, n) {
        cin >> s[i];
        area += (s[i] * s[i]);
    }
    ll low = 0;
    ll high = sqrt(c - area);
    while (low < high) {
        ll mid = (low + high) / 2;
        ll posible = 0;
        FOR(i, 0, n) {
            posible += (2 * mid + s[i]) * (2 * mid + s[i]);
            if (posible > c) {
                break;
            }
        }
        if (posible == c) {
            cout << mid << ENDL;
            return;
        }
        if (posible > c) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << ENDL;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}