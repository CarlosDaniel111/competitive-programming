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

struct SuffixArray {
    vi sa, lcp;
    string S;
    int n;
    SuffixArray(string &s, int lim = 256) {  // O(n log n)
        n = SZ(s) + 1;
        S = s;
        int k = 0, a, b;
        vi x(ALL(s) + 1), y(n), ws(max(n, lim)), rank(n);
        sa = lcp = y, iota(ALL(sa), 0);

        // Calcular SA (Suffix Array)
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(ALL(y), n - j);
            FOR(i, 0, n) {
                if (sa[i] >= j) y[p++] = sa[i] - j;
            }
            fill(ALL(ws), 0);
            FOR(i, 0, n) {
                ws[x[i]]++;
            }
            FOR(i, 1, lim) {
                ws[i] += ws[i - 1];
            }
            for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[sa[0]] = 0;
            FOR(i, 1, n) {
                a = sa[i - 1];
                b = sa[i], x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
            }
        }

        // Calcular lcp (longest common prefix)
        FOR(i, 1, n) {
            rank[sa[i]] = i;
        }
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
            for (k &&k--, j = sa[rank[i] - 1]; s[i + k] == s[j + k]; k++)
                ;
    }

    bool subStringSearch(string &sub) {  // O(|sub| log n)
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            int res = S.compare(sa[mid], SZ(sub), sub);
            (res >= 0) ? r = mid : l = mid + 1;
        }
        if (S.compare(sa[l], SZ(sub), sub) != 0) return 0;
        return 1;
    }

    int countSubString(string &sub) {  // O(|sub| log n)
        int l = 0, r = n - 1;
        // Buscar L
        while (l < r) {
            int mid = (l + r) / 2;
            int res = S.compare(sa[mid], SZ(sub), sub);
            (res >= 0) ? r = mid : l = mid + 1;
        }
        if (S.compare(sa[l], SZ(sub), sub) != 0) return 0;
        int L = l;

        // Buscar R
        l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            int res = S.compare(sa[mid], SZ(sub), sub);
            (res > 0) ? r = mid : l = mid + 1;
        }
        if (S.compare(sa[r], SZ(sub), sub) != 0) --r;
        return r - L + 1;
    }

    ll countDistinctSubstring() {  // O(n)
        ll result = 0;
        FOR(i, 1, n) {
            result += ll(n - sa[i] - 1 - lcp[i]);
        }
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string s;
    cin >> s;
    SuffixArray suffix(s);

    cout << suffix.countDistinctSubstring() << ENDL;

    return 0;
}