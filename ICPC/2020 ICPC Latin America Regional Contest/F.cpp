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
constexpr ll LLINF = 2e18;

ll dp[8005], last[8005];
pair<ll, ll> st[8005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vi arr(n);
    vi ans(n);
    for (auto &x : arr) cin >> x;

    fill(dp, dp + n, LLINF);
    fill(last, last + n, LLINF);

    st[0] = {0, LLINF};
    FOR(i, 0, n) {
        ll top = 0;
        FOR(j, i, n) {
            while (top && arr[st[top].first] <= arr[j]) {
                last[j - 1] = min(last[j - 1], last[st[top].first - 1]);
                top--;
            }
            st[++top] = {j, last[j - 1] + arr[j]};

            st[top].second = min(st[top].second, st[top - 1].second);
            dp[j] = st[top].second;
        }
        ans[i] = dp[n - 1];
        swap(dp, last);
    }

    sort(ALL(arr), greater<int>());
    ll ans2 = 0;
    FOR(i, 0, n) {
        ans2 += arr[i];
        cout << ans[i] << " " << ans2 << ENDL;
    }

    return 0;
}