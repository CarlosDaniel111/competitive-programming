#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vi arr(n);
    vi arr2(n);
    int total = 0;
    FOR(i, 0, n) {
        cin >> arr[i];
        arr2[i] = arr[i];
        total += arr[i];
    }

    int igual = total / n;

    ll opc1 = 0;
    FOR(i, 0, 3 * n) {
        if (arr[i % n] > igual) {
            arr[(i + 1) % n] += arr[i % n] - igual;
            opc1 += arr[i % n] - igual;
            arr[i % n] = igual;
        }
    }

    ll opc2 = 0;
    ROF(i, 3 * n, 0) {
        if (arr2[i % n] > igual) {
            arr2[(i - 1 + n) % n] += arr2[i % n] - igual;
            opc2 += arr2[i % n] - igual;
            arr2[i % n] = igual;
        }
    }

    cout << min(opc1, opc2) << ENDL;

    return 0;
}