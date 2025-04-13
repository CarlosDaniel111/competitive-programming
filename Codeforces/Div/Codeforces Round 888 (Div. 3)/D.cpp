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
    ll n;
    cin >> n;
    vector<ll> arr(n - 1);
    FOR(i, 0, n - 1) {
        cin >> arr[i];
    }
    vector<bool> num(n + 1, 0);
    ll ant = 0;
    ll errores = 0;
    ll indiceError;
    FOR(i, 0, n - 1) {
        ll diff = abs(arr[i] - ant);
        if (diff > n) {
            errores++;
            indiceError = i - 1;
        } else if (num[diff]) {
            errores++;
            indiceError = i - 1;
        } else {
            num[diff] = true;
        }
        ant = arr[i];
    }
    if (errores >= 2) {
        cout << "NO" << ENDL;
        return;
    }
    if (errores == 0) {
        cout << "YES" << ENDL;
        return;
    }
    ll p1 = 0, p2 = 0;
    FOR(i, 1, n + 1) {
        if (!num[i]) {
            if (p1 != 0) {
                p2 = i;
            } else {
                p1 = i;
            }
        }
    }
    ll diff;
    if (indiceError == -1) {
        diff = arr[0];
    } else {
        diff = arr[indiceError + 1] - arr[indiceError];
    }

    if (p1 + p2 == diff) {
        cout << "YES" << ENDL;
    } else {
        cout << "NO" << ENDL;
    }
    // cout << p1 << " " << p2 << " " << indiceError << ENDL;
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