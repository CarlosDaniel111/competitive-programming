#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
#define ENDL '\n'
#define FOR(x, n) for (long long x = 0; x < (long long)n; x++)
#define FOR1(x, n) for (long long x = 1; x <= (long long)n; x++)
#define FORR(x, n) for (long long x = n - 1; x >= 0; x--)
#define FORR1(x, n) for (long long x = n; x >= 1; x--)
const long long INF = 1 << 28, MOD = 1e9 + 7, MAXN = 1e5 + 5;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vii;

int tree[4 * MAXN];
int B, mod;

ll bigmod(ll a, ll b) { //(a^b) mod m
    ll aux = a % mod;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = (1LL * res * aux) % mod;
        aux = (1LL * aux * aux) % mod;
        b >>= 1;
    }
    return res;
}

class SegmentTree {
  public:
    int n;

    SegmentTree(int N) {
        n = N;
        FOR(i, N * 4 + 1) {
            tree[i] = 0;
        }
    }

    ll query(int index, int start, int end, int l, int r) {
        if (end < l || start > r)
            return 0;

        if (l <= start && r >= end)
            return tree[index];

        int mid = (start + end) / 2;
        ll q1 = query(2 * index + 1, start, mid, l, r);
        ll q2 = query(2 * index + 2, mid + 1, end, l, r);

        // CHECAR
        int aux = min(end, r);
        ll ans = (bigmod(B, aux - mid) * q1 + q2) % mod;
        return ans;
    }

    void update(int index, int start, int end, int idx, int val) {
        if (idx < start || end < idx)
            return;
        if (start == idx && idx == end) {
            tree[index] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2 * index + 1, start, mid, idx, val);
            else
                update(2 * index + 2, mid + 1, end, idx, val);

            ll q1 = tree[2 * index + 1];
            ll q2 = tree[2 * index + 2];

            // Sacar el B
            ll ans = (bigmod(B, end - mid) * q1 + q2) % mod;
            tree[index] = ans;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int l, n;
    while (cin >> B) {
        cin >> mod >> l >> n;
        if (B == 0 && mod == 0 && l == 0 && n == 0) {
            return 0;
        }
        SegmentTree st(l + 1);
        FOR(i, n) {
            char opc;
            int id, v;
            cin >> opc >> id >> v;

            if (opc == 'E') {
                st.update(0, 1, l, id, v);
            } else {
                if (id == v) {
                    cout << 0 << ENDL;
                } else {
                    ll ans = st.query(0, 1, l, id, v) % mod;
                    cout << ans << ENDL;
                }
            }
        }
        cout << '-' << ENDL;
    }

    return 0;
}
