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
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define ENDL '\n'

constexpr int MAXN = 1e5 + 5, MOD = 1e9 + 7;

struct SuffixAutomaton {
    int N = 1;
    vi lnk{-1}, len{0}, pos{-1};
    vector<map<char, int>> nex{1};
    vector<bool> isClone{0};
    vector<vi> iLnk;
    int add(int p, char c) {
        auto getNex = [&]() {
            if (p == -1) return 0;
            int q = nex[p][c];
            if (len[p] + 1 == len[q]) return q;
            int clone = N++;
            lnk.pb(lnk[q]);
            lnk[q] = clone;
            len.pb(len[p] + 1), nex.pb(nex[q]),
                pos.pb(pos[q]), isClone.pb(1);
            for (; ~p && nex[p][c] == q; p = lnk[p]) nex[p][c] = clone;
            return clone;
        };
        int cur = N++;
        lnk.emplace_back(), len.pb(len[p] + 1), nex.emplace_back(),
            pos.pb(pos[p] + 1), isClone.pb(0);
        for (; ~p && !nex[p].count(c); p = lnk[p]) nex[p][c] = cur;
        int x = getNex();
        lnk[cur] = x;
        return cur;
    }
    void init(string &s) {
        int p = 0;
        for (char x : s) p = add(p, x);
    }

    void genIlnk() {
        iLnk.resize(N);
        FOR(v, 1, N)
        iLnk[lnk[v]].pb(v);
    }
    int solve(string &s) {
        int cur = 0;
        ll ans = 0;
        for (char x : s) {
            if (!nex[cur].count(x)) {
                ans++;
                cur = 0;
                if (!nex[cur].count(x)) {
                    return -2;
                }
            }
            cur = nex[cur][x];
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string s;
    cin >> s;
    SuffixAutomaton sa;
    sa.init(s);

    int n;
    cin >> n;
    FOR(i, 0, n) {
        string pal;
        cin >> pal;
        cout << sa.solve(pal) + 1 << ENDL;
    }

    return 0;
}