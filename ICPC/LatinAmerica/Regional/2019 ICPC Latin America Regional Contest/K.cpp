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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string s;
    cin >> s;
    ll n = SZ(s);
    vi raices;
    FOR(i, 0, n - 1) {
        if (s[i] != s[i + 1]) {
            raices.pb((i + 1) * 2 + 1);
        }
    }

    if (raices.empty()) {
        cout << 0 << ENDL;
        cout << (s[0] == 'H' ? 1 : -1) << ENDL;
        return 0;
    }

    int m = SZ(raices);
    vi ans;
    ans.pb(raices[m - 1]);
    ans.pb(1);
    FOR(i, 0, m - 1) {
        vi tmp = ans;
        ans.pb(0);
        for (auto &a : ans) a *= raices[i];
        FOR(i, 0, SZ(tmp)) {
            ans[i + 1] += tmp[i];
        }
    }

    if (s[0] == 'A' && m % 2 == 0 || s[0] == 'H' && m % 2 == 1) {
        for (int i = SZ(ans) - 1; i >= 0; i -= 2) {
            ans[i] *= -1;
        }
    } else {
        for (int i = SZ(ans) - 2; i >= 0; i -= 2) {
            ans[i] *= -1;
        }
    }

    cout << m << ENDL;

    for (int i = SZ(ans) - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }

    return 0;
}