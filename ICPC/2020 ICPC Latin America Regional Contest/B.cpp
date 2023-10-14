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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi arr(n);
    vi dif(n, 0);
    for (auto &x : arr) cin >> x;
    vi left(n);
    left[0] = 0;
    FOR(i, 1, n) {
        if (arr[i] <= arr[i - 1] || arr[i - 1] == -1) {
            left[i] = left[i - 1] + 1;
        } else {
            left[i] = 0;
        }
    }

    vi right(n);
    right[n - 1] = 0;
    ROF(i, n - 1, 0) {
        if (arr[i] <= arr[i + 1] || arr[i + 1] == -1) {
            right[i] = right[i + 1] + 1;
        } else {
            right[i] = 0;
        }
    }

    FOR(len, 3, n + 1) {
        bool flag = true;
        for (int i = 0; i < n; i += len) {
            int l = i, r = min(i + len - 1, n - 1);
            int nlen = r - l + 1;
            if (nlen <= 2 || left[r] == 0 || right[l] == 0 || right[l] + left[r] < nlen - 1) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Y" << ENDL;
            return 0;
        }
    }
    cout << "N" << ENDL;

    return 0;
}