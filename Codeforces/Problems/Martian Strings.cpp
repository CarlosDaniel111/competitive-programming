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
    vi SuffixArr, lcp;
    string S;
    int n;
    SuffixArray(string &s, int lim = 256) : S(s), n(SZ(s) + 1) {  // O(n log n)
        int k = 0, a, b;
        vi x(ALL(s) + 1), y(n), ws(max(n, lim)), rank(n);
        SuffixArr = lcp = y, iota(ALL(SuffixArr), 0);

        // Calcular SuffixArr
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(ALL(y), n - j);
            FOR(i, 0, n) {
                if (SuffixArr[i] >= j) y[p++] = SuffixArr[i] - j;
            }
            fill(ALL(ws), 0);
            FOR(i, 0, n) {
                ws[x[i]]++;
            }
            FOR(i, 1, lim) {
                ws[i] += ws[i - 1];
            }
            for (int i = n; i--;) SuffixArr[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[SuffixArr[0]] = 0;
            FOR(i, 1, n) {
                a = SuffixArr[i - 1];
                b = SuffixArr[i], x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
            }
        }

        // Calcular lcp (longest common prefix)
        FOR(i, 1, n) {
            rank[SuffixArr[i]] = i;
        }
        for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
            for (k &&k--, j = SuffixArr[rank[i] - 1]; s[i + k] == s[j + k]; k++)
                ;
    }

    int lower(string &sub) {
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            int res = S.compare(SuffixArr[mid], SZ(sub), sub);
            (res >= 0) ? r = mid : l = mid + 1;
        }
        if (S.compare(SuffixArr[l], SZ(sub), sub) != 0) return -1;
        return l;
    }

    int upper(string &sub) {
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            int res = S.compare(SuffixArr[mid], SZ(sub), sub);
            (res > 0) ? r = mid : l = mid + 1;
        }
        if (S.compare(SuffixArr[r], SZ(sub), sub) != 0) --r;
        return r;
    }

    bool subStringSearch(string &sub) {  // O(|sub| log n)
        int L = lower(sub);
        if (S.compare(SuffixArr[L], SZ(sub), sub) != 0) return 0;
        return 1;
    }

    int countSubString(string &sub) {  // O(|sub| log n)
        return upper(sub) - lower(sub) + 1;
    }

    ll countDistinctSubstring() {  // O(n)
        ll result = 0;
        FOR(i, 1, n) {
            result += ll(n - SuffixArr[i] - 1 - lcp[i]);
        }
        return result;
    }

    string longestCommonSubstring(int lenS, int lenT) {  // O(n)
        int maximo = -1, indice = -1;
        FOR(i, 2, n) {
            if ((SuffixArr[i] > lenS && SuffixArr[i - 1] < lenS) || (SuffixArr[i] < lenS && SuffixArr[i - 1] > lenS)) {
                if (lcp[i] > maximo) {
                    maximo = lcp[i];
                    indice = SuffixArr[i];
                }
            }
        }
        return S.substr(indice, maximo);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string s;
    cin >> s;
    SuffixArray sa(s);
    int n;
    cin >> n;
    int ans = 0;
    FOR(i, 0, n) {
        string pal;
        cin >> pal;
        int len = SZ(pal);
        vi pref(len, -1);
        vi suff(len, -1);
        string pre = "", suf = "";
        FOR(i, 0, len) {
            pre += pal[i];
            suf += pal[len - i - 1];
            pref[i] = sa.SuffixArr[sa.lower(pre)];
            suff[i] = sa.SuffixArr[sa.upper(suf)];
        }
        cout << pref[0] << " " << suff[0] << ENDL;
    }

    return 0;
}