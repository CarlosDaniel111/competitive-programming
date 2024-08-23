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
constexpr int MAXN = 1e6 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

int n, m;

vi PI(vi& s) {
    vi p(SZ(s) + 1);
    p[0] = -1;
    int g = -1, i = 0;
    FOR(i, 0, SZ(s)) {
        while (g >= 0 && s[i] != s[g] && (s[g] || s[i] <= g)) g = p[g];
        g++;
        p[i + 1] = g;
    }
    return p;
}

int KMP(vi& s) {
    vi phi = PI(s);
    int ans = 0;
    FOR(i, SZ(phi) - n, SZ(phi))
    if (phi[i] == m) ans++;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string w;
    while (cin >> w) {
        n = SZ(w);
        cin >> m;
        vi last(26, -1);
        vi s(n + m + 1, 0);
        FOR(i, 0, m) {
            int x;
            cin >> x;
            x--;
            s[i] = last[x] == -1 ? 0 : i - last[x];
            last[x] = i;
        }
        s[m] = -1e9 + 7;
        last.assign(26, -1);
        for (int i = m + 1, j = 0; i <= n + m; i++, j++) {
            char c = w[j] - 'a';
            s[i] = last[c] == -1 ? 0 : j - last[c];
            last[c] = j;
        }

        cout << KMP(s) << ENDL;
    }

    return 0;
}