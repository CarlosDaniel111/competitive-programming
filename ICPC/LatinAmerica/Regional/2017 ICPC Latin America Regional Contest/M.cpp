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

constexpr ll MOD = 1e9 + 7;
constexpr int MAXN = 4e5 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

struct SuffixArray {
    vi SuffixArr, lcp;
    vi S;
    int n;
    SuffixArray(vi &s, int lim = 306) : S(s), n(SZ(s) + 1) {  // O(n log n)
        int k = 0, a, b;
        vi x(ALL(s) + 1), y(n), ws(max(n, lim)), rank(n);
        x[SZ(s)] = 0;
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

    vi constructRSA() {
        vi RSA(n);
        FOR(i, 0, n) {
            RSA[SuffixArr[i]] = i;
        }
        return RSA;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vi arr;
    vector<vi> id(N);
    FOR(i, 0, N) {
        int k;
        cin >> k;
        id[i].resize(k);
        FOR(j, 0, k) {
            int x;
            cin >> x;
            id[i][j] = SZ(arr);
            arr.pb(x);
        }
        arr.pb(302);
    }

    SuffixArray sa(arr, 305);
    vi rsa = sa.constructRSA();

    pqg<tuple<int, int, int>> q;
    FOR(i, 0, N) {
        q.emplace(rsa[id[i][0]], i, 0);
    }

    ll ans = 0;
    while (!q.empty()) {
        int _rnk, idx, ps;
        tie(_rnk, idx, ps) = q.top();
        q.pop();
        ans = ((ans * 365) % MOD + arr[id[idx][ps]]) % MOD;

        if (ps + 1 < id[idx].size()) {
            q.emplace(rsa[id[idx][ps + 1]], idx, ps + 1);
        }
    }
    cout << ans * 365 % MOD << ENDL;

    return 0;
}