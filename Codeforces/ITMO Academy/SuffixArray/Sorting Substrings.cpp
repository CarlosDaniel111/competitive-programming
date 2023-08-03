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

template <typename T>
struct SparseTable {
    vector<vector<T>> ST;

    void build(vector<T> &A) {
        ST.assign(30, vector<T>(SZ(A), 0));

        for (int i = 0; i < SZ(A); i++)
            ST[0][i] = A[i];

        for (int k = 1; k < 30; k++)
            for (int i = 0; i + (1 << k) <= SZ(A); i++)
                ST[k][i] = min(ST[k - 1][i], ST[k - 1][i + (1 << (k - 1))]);
    }

    T query(int l, int r) {
        int p = 31 - __builtin_clz(r - l);
        return min(ST[p][l], ST[p][r - (1 << p) + 1]);
    }
};

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
};

SparseTable<int> sparse;
vi antiSA;
string s;

bool comp(pi &p1, pi &p2) {
    int l = p1.first - 1;
    int r = p2.first - 1;
    int lsz = p1.second - p1.first + 1;
    int rsz = p2.second - p2.first + 1;

    if (l == r) {
        return lsz < rsz;
    }

    int lind = antiSA[l];
    int rind = antiSA[r];

    if (lind > rind) swap(lind, rind);
    lind++;
    int min_lcp = sparse.query(lind, rind);

    if (lsz <= min_lcp && rsz <= min_lcp) {
        if (lsz == rsz)
            return (p1.first < p2.first);
        else if (lsz < rsz)
            return true;
        else
            return false;
    } else if (lsz <= min_lcp) {
        return true;
    } else if (rsz <= min_lcp) {
        return false;
    } else {
        return (s[l + min_lcp] < s[r + min_lcp]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> s;
    SuffixArray SA(s);
    sparse.build(SA.lcp);
    antiSA = vi(SZ(s) + 1);
    FOR(i, 0, SZ(s) + 1) {
        antiSA[SA.SuffixArr[i]] = i;
    }

    int n;
    cin >> n;
    vector<pi> pares(n);
    FOR(i, 0, n) {
        int x, y;
        cin >> x >> y;
        pares[i] = {x, y};
    }
    sort(ALL(pares), comp);
    FOR(i, 0, n) {
        cout << pares[i].first << " " << pares[i].second << ENDL;
    }

    return 0;
}