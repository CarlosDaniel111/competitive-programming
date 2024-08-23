#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<double, double>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<double>;
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

// pairs
#define mp make_pair
#define f first
#define s second

// vectors
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define tcT template <class T
tcT > int lwb(vector<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }

// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)

#define ENDL '\n'

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int INF = 1 << 28;
const ll LLINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

int arr[MAXN], tree[MAXN * 4];

void buildTree(int index, int start, int end) {
    if (start == end) {
        tree[index] = arr[start];
    } else {
        int mid = (start + end) / 2;
        buildTree(2 * index + 1, start, mid);
        buildTree(2 * index + 2, mid + 1, end);
        tree[index] = tree[2 * index + 1] * tree[2 * index + 2];
    }
}

void update(int index, int start, int end, int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        tree[index] = val;
    } else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid)
            update(2 * index + 1, start, mid, idx, val);
        else
            update(2 * index + 2, mid + 1, end, idx, val);

        tree[index] = tree[2 * index + 1] * tree[2 * index + 2];
    }
}

int query(int index, int start, int end, int l, int r) {
    if (r < start || end < l)
        return 1;

    if (l <= start && end <= r)
        return tree[index];

    int mid = (start + end) / 2;
    int q1 = query(2 * index + 1, start, mid, l, r);
    int q2 = query(2 * index + 2, mid + 1, end, l, r);

    return q1 * q2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, k;
    while (cin >> n) {
        cin >> k;
        F0R(i, n) {
            cin >> arr[i];
            if (arr[i] > 0) {
                arr[i] = 1;
            } else if (arr[i] < 0) {
                arr[i] = -1;
            }
        }
        buildTree(0, 0, n - 1);

        char opc;
        F0R(i, k) {
            int x, y;
            cin >> opc;
            if (opc == 'C') {
                cin >> x >> y;
                x--;
                if (y > 0) {
                    y = 1;
                } else if (y < 0) {
                    y = -1;
                }
                update(0, 0, n - 1, x, y);
            } else {
                int ans;
                cin >> x >> y;
                x--;
                y--;
                ans = query(0, 0, n - 1, x, y);
                /*F0R(i, n) {
                    cout << arr[i] << " ";
                }
                cout << ENDL;*/
                // cout << ans << " ";
                if (ans == 0) {
                    cout << '0';
                } else if (ans > 0) {
                    cout << '+';
                } else {
                    cout << '-';
                }
            }
        }
        cout << ENDL;
    }

    return 0;
}
