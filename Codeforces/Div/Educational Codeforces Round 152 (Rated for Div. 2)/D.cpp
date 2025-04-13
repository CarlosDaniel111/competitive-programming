#include <bits/stdc++.h>
using namespace std;

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
    // AC2++
    int n;
    cin >> n;

    vector<int> arr(n);
    FOR(i, 0, n) {
        cin >> arr[i];
    }

    int i = 0;
    int ans = 0;
    while (i < n) {
        if (arr[i] == 0) {
            ans++;
            i++;
            int flag = 0;
            while (i < n && arr[i] != 0) {
                if (arr[i] == 2) flag = true;
                i++;
            }
            if (flag) i++;
        } else {
            ans++;
            if (arr[i + 1] == 0)
                i += 2;
            else {
                i++;
                while (i < n && arr[i] != 0) {
                    i++;
                }
                i++;
            }
        }
    }
    cout << ans << ENDL;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}