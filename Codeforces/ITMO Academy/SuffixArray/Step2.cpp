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

class SuffixArray {
   private:
    void countingSort() {
        vi cnt(n);
        for (auto x : c) {
            cnt[x]++;
        }
        vi SA_new(n);
        vi pos(n);
        pos[0] = 0;
        FOR(i, 1, n) {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for (auto x : SA) {
            int i = c[x];
            SA_new[pos[i]] = x;
            pos[i]++;
        }
        SA = SA_new;
    }

    void prepareSA() {
        vector<pair<char, int>> a(n);
        FOR(i, 0, n) {
            a[i] = {S[i], i};
        }
        sort(ALL(a));

        FOR(i, 0, n) {
            SA[i] = a[i].second;
        }
        c[SA[0]] = 0;
        FOR(i, 1, n) {
            if (a[i].first == a[i - 1].first) {
                c[SA[i]] = c[SA[i - 1]];
            } else {
                c[SA[i]] = c[SA[i - 1]] + 1;
            }
        }
    }

    void calculateSA() {
        int k = 0;
        while ((1 << k) < n) {
            // k -> k+1
            FOR(i, 0, n) {
                SA[i] = (SA[i] - (1 << k) + n) % n;
            }
            countingSort();
            vi c_new(n);
            c_new[SA[0]] = 0;
            FOR(i, 1, n) {
                pi prev = {c[SA[i - 1]], c[(SA[i - 1] + (1 << k)) % n]};
                pi now = {c[SA[i]], c[(SA[i] + (1 << k)) % n]};
                if (now == prev) {
                    c_new[SA[i]] = c_new[SA[i - 1]];
                } else {
                    c_new[SA[i]] = c_new[SA[i - 1]] + 1;
                }
            }
            c = c_new;
            k++;
        }
    }

   public:
    string S;
    int n;
    vi SA, c;

    SuffixArray(const string initialS) : S(initialS) {
        S += "$";
        n = SZ(S);
        SA = vi(n);
        c = vi(n);
        prepareSA();
        calculateSA();
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string s;
    cin >> s;
    SuffixArray SA(s);

    FOR(i, 0, SZ(s) + 1) {
        cout << SA.SA[i] << " ";
    }

    return 0;
}