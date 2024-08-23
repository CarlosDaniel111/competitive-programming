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

ll c[MAXN], F;

ll pack(int s, ll sum) {
    if (s < 2 || sum % s != 0) return 0;
    ll mod = (c[0] - s - s / F) % s;
    ll menor = INF;
    FOR(i, 0, F) {
        ll r = c[i] - s - s / F;
        if (r < 0 || r % s != mod) return 0;
        menor = min(menor, r);
    }
    return menor / s + 1;
}

ll solve(ll sum, ll g) {
    if (sum % F != 0) return 0;
    ll ans = 0;
    for (ll d = 1; d * d <= g; d++) {
        if (g % d != 0) continue;
        ans += pack(d * F, sum);
        if (g / d != d) ans += pack(g / d * F, sum);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    while (cin >> F && F) {
        ll gcdall = 0;
        ll sum = 0;
        FOR(i, 0, F) {
            cin >> c[i];
            gcdall = __gcd(gcdall, c[i]);
            sum += c[i];
        }
        cout << solve(sum, gcdall) << ENDL;
    }

    return 0;
}