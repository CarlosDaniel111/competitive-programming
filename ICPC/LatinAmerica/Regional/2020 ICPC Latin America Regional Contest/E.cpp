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
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vi arr(n, 0);
    for (auto &a : arr) cin >> a;

    stack<int> st;
    vi leftMax(n);
    FOR(i, 0, n) {
        while (!st.empty() && arr[st.top()] < arr[i])
            st.pop();
        if (st.empty())
            leftMax[i] = -1;
        else
            leftMax[i] = st.top();
        st.push(i);
    }

    stack<int> st2;
    vi rightMax(n);
    ROF(i, n, 0) {
        while (!st2.empty() && arr[st2.top()] < arr[i])
            st2.pop();
        if (st2.empty())
            rightMax[i] = -1;
        else
            rightMax[i] = st2.top();
        st2.push(i);
    }

    vi ans(n + 5, 0);

    FOR(i, 0, n) {
        if (leftMax[i] == -1) {
            if (i != 0) {
                ans[0]++;
                ans[i]--;
            }
        } else {
            int pos = (i + leftMax[i] + 2) / 2;
            if (pos != i) {
                ans[pos]++;
                ans[i]--;
            }
        }

        if (rightMax[i] == -1) {
            if (i != n - 1) {
                ans[i + 1]++;
                ans[n]--;
            }
        } else {
            int pos = (rightMax[i] + i + 1) / 2 - 1;
            if (pos != i) {
                ans[pos + 1]--;
                ans[i + 1]++;
            }
        }
    }

    cout << ans[0] << " ";
    FOR(i, 1, n) {
        ans[i] += ans[i - 1];
        cout << ans[i] << " ";
    }

    return 0;
}