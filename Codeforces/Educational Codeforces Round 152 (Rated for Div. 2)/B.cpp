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
    priority_queue<pi> q;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        int aux;

        if (x % k == 0) {
            aux = INF;
        } else if (k > x) {
            aux = x;
        } else {
            aux = x % k;
        }

        q.push({aux, -(i + 1)});
    }

    while (!q.empty()) {
        pi par = q.top();
        q.pop();

        cout << -par.second << " ";
        /*if (aux > 0) {
            q.push({aux, top.second});
        } else {
            cout << -top.second << " ";
        }*/
    }
    cout << ENDL;
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