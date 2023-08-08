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
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define ENDL '\n'

constexpr int MAXN = 5e5 + 5, MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string s;
    cin >> s;
    ll n, S;
    cin >> S;
    n = SZ(s);
    s = s + s;

    ll last = -1;
    ll ans = 0;
    ROF(i, 2 * n, 0) {
        if (s[i] == 'E') {
            if (i < n) {
                ans += S;
            }
            last = i;
        } else if (i < n) {
            if (last != -1) {
                ll dist = last - i + 1;
                if (dist <= S) {
                    ans += S - dist + 1;
                }
            }
        }
    }

    cout << ans << ENDL;

    return 0;
}