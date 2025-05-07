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
    int n, k;
    cin >> n >> k;
    vector<pi> arr(n);
    FOR(i, 0, n) {
        int x;
        cin >> x;
        arr[i] = {x, i + 1};
    }

    sort(ALL(arr));
    int menorAND = INT_MAX, indice;
    FOR(i, 1, n) {
        int xAND = arr[i].first ^ arr[i - 1].first;
        if (xAND < menorAND) {
            menorAND = xAND;
            indice = i;
        }
    }
    cout << arr[indice].second << " " << arr[indice - 1].second << " " << ((1 << k) - 1 - arr[indice - 1].first) << ENDL;
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