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

void solve() {
    int n;
    cin >> n;
    vi arr(n);
    map<int, int> mapa;
    for (auto &x : arr) {
        cin >> x;
        mapa[x]++;
    }
    map<int, ll> ans_r, ans_l;
    ll cnt = 0, last = 0, sum = 0;
    for (auto &[a, b] : mapa) {
        sum += (a - last) * cnt;
        cnt += b;
        last = a;
        ans_l[a] = sum;
    }

    cnt = 0, last = 0, sum = 0;
    for (auto it = mapa.rbegin(); it != mapa.rend(); it++) {
        auto &[a, b] = *it;
        sum += (last - a) * cnt;
        cnt += b;
        last = a;
        ans_r[a] = sum;
    }

    for (auto &x : arr) {
        cout << ans_r[x] + ans_l[x] + n << " ";
    }
    cout << ENDL;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}