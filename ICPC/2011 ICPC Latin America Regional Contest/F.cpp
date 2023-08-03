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
constexpr int MAXN = 7e5 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

struct SuffixArray {
    vi SA, LCP;
    string S;
    int n;
    SuffixArray(string &s, int lim = 256) : S(s), n(SZ(s)) {  // O(n log n)
        int k = 0, a, b;
        vi x(ALL(s)), y(n + 1), ws(max(n, lim)), rank(n);
        SA = LCP = y, iota(ALL(SA), 0);

        // Calcular SA
        for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
            p = j, iota(ALL(y), n - j);
            FOR(i, 0, n) {
                if (SA[i] >= j) y[p++] = SA[i] - j;
            }
            fill(ALL(ws), 0);
            FOR(i, 0, n) {
                ws[x[i]]++;
            }
            FOR(i, 1, lim) {
                ws[i] += ws[i - 1];
            }
            for (int i = n; i--;) SA[--ws[x[y[i]]]] = y[i];
            swap(x, y), p = 1, x[SA[0]] = 0;
            FOR(i, 1, n) {
                a = SA[i - 1];
                b = SA[i], x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
            }
        }

        // Calcular LCP (longest common prefix)
        FOR(i, 1, n) {
            rank[SA[i]] = i;
        }
        for (int i = 0, j; i < n - 1; LCP[rank[i++]] = k)
            for (k &&k--, j = SA[rank[i] - 1]; s[i + k] == s[j + k]; k++)
                ;
    }
};

ll pos[MAXN];
int rem[MAXN];
pair<ll, ll> vals[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int F;
    while (cin >> F && F) {
        string text = "";
        int n = 0;
        FOR(i, 0, F) {
            string s;
            cin >> s;
            FOR(j, 0, SZ(s)) {
                pos[j + n] = 1LL << i;
                rem[j + n] = SZ(s) - j;
            }
            text += s + "$";
            n = SZ(text);
        }

        SuffixArray sa(text);

        int p = -1;
        set<ll> ans;
        sa.LCP[n] = 0, sa.SA[n] = n, pos[n] = 0, rem[n] = 0;

        FOR(i, F, n) {
            sa.LCP[i] = min(sa.LCP[i], rem[sa.SA[i]]);
        }

        FOR(i, F, n + 1) {
            int u = sa.SA[i];
            int lcp = sa.LCP[i];
            if (i < n && rem[u] > max(sa.LCP[i], sa.LCP[i + 1])) ans.insert(pos[u]);

            ll acum = 0;
            while (p >= 0 && lcp < vals[p].first) {
                int lcp1 = vals[p].first;
                while (lcp1 == vals[p].first) acum |= vals[p--].second;
                ans.insert(acum | vals[p].second);
            }
            if (p >= 0) vals[++p] = make_pair(lcp, acum);
            vals[++p] = make_pair(lcp, pos[u]);
        }

        cout << SZ(ans) << ENDL;
    }

    return 0;
}