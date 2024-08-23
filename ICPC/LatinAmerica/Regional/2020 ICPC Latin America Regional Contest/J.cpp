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

int k;
ll cnts[43046725];
int pot9[10];

void solve(vi &arr, int cnt, int mask, int val) {
    if (cnt == k) {
        cnts[mask] += val;
        return;
    }
    FOR(i, 0, arr[cnt] + 1) {
        int new_mask = mask + (pot9[cnt] * i);
        solve(arr, cnt + 1, new_mask, val);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    pot9[0] = 1;
    FOR(i, 1, 10) {
        pot9[i] = pot9[i - 1] * 9;
    }

    int n;
    cin >> n >> k;
    vector<vi> machine(n, vi(8, 0));
    int id = 0;
    FOR(i, 0, n) {
        char opc;
        cin >> opc;
        if (opc == 'C') {
            int r;
            cin >> r;
            FOR(j, 0, r) {
                int x;
                cin >> x;
                x--;
                machine[id][x]++;
            }
            solve(machine[id], 0, 0, 1);
            id++;
        } else if (opc == 'D') {
            int x;
            cin >> x;
            x--;
            solve(machine[x], 0, 0, -1);
        } else {
            int r, mask = 0;
            cin >> r;
            FOR(j, 0, r) {
                int x;
                cin >> x;
                x--;
                mask += (pot9[x]);
            }
            cout << cnts[mask] << ENDL;
        }
    }

    return 0;
}