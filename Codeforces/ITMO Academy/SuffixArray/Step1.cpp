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

void radix_sort(vector<pair<pair<int, int>, int>> &a) {
    int n = a.size();
    {
        vi cnt(n);
        for (auto x : a) {
            cnt[x.first.second]++;
        }
        vector<pair<pair<int, int>, int>> a_new(n);
        vi pos(n);
        pos[0] = 0;
        FOR(i, 1, n) {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for (auto x : a) {
            int i = x.first.second;
            a_new[pos[i]] = x;
            pos[i]++;
        }
        a = a_new;
    }

    {
        vi cnt(n);
        for (auto x : a) {
            cnt[x.first.first]++;
        }
        vector<pair<pair<int, int>, int>> a_new(n);
        vi pos(n);
        pos[0] = 0;
        FOR(i, 1, n) {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for (auto x : a) {
            int i = x.first.first;
            a_new[pos[i]] = x;
            pos[i]++;
        }
        a = a_new;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string s;
    cin >> s;
    s += "$";
    int n = SZ(s);
    vi p(n), c(n);
    {
        vector<pair<char, int>> a(n);
        FOR(i, 0, n) {
            a[i] = {s[i], i};
        }
        sort(ALL(a));

        FOR(i, 0, n) {
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        FOR(i, 1, n) {
            if (a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            } else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
    }
    // k = 0

    int k = 0;
    while ((1 << k) < n) {
        vector<pair<pair<int, int>, int>> a(n);
        FOR(i, 0, n) {
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }
        radix_sort(ALL(a));
        FOR(i, 0, n) {
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        FOR(i, 1, n) {
            if (a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            } else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
        k++;
    }

    FOR(i, 0, n) {
        cout << p[i] << " ";
    }

    return 0;
}