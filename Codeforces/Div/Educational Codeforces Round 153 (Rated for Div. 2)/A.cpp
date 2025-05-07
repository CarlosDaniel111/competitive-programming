#include <bits/stdc++.h>
using namespace std;
// AC2++
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
    string s;
    cin >> s;

    if (s == "()") {
        cout << "NO" << ENDL;
        return;
    }
    int n = SZ(s);
    int put = 0;
    bool pegados = false;
    FOR(i, 1, n) {
        if (s[i] == s[i - 1]) {
            pegados = true;
            break;
        }
    }
    cout << "YES" << ENDL;
    if (pegados) {
        FOR(i, 0, n) {
            cout << "()";
        }
    } else {
        FOR(i, 0, n) {
            cout << "(";
        }
        FOR(i, 0, n) {
            cout << ")";
        }
    }
    cout << ENDL;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}