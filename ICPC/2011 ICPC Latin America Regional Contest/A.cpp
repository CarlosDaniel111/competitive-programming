#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
#define ENDL '\n'
#define FOR(x, n) for (long long x = 0; x < (long long)n; x++)
#define FOR1(x, n) for (long long x = 1; x <= (long long)n; x++)
#define FORR(x, n) for (long long x = n - 1; x >= 0; x--)
#define FORR1(x, n) for (long long x = n; x >= 1; x--)
const long long INF = 1 << 28, MOD = 1e9 + 7, MAXN = 1e5 + 5;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vii;

ii soldados[MAXN];

void init(int n) {
    FOR(i, n) {
        soldados[i].first = i - 1;
        soldados[i].second = i + 1;
    }

    soldados[n - 1].second = -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int s, b;
    bool imprime = false;
    while (cin >> s) {
        cin >> b;
        if (s == 0 && b == 0)
            return 0;
        init(s);
        FOR(i, b) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            if (l == r) {
                int res1 = soldados[l].first;
                int res2 = soldados[l].second;
                if (res1 != -1) {
                    soldados[res1].second = res2;
                }
                if (res2 != -1) {
                    soldados[res2].first = res1;
                }

                // IMPRESION
                if (res1 == -1) {
                    cout << "* ";
                } else {
                    cout << res1 + 1 << " ";
                }

                if (res2 == -1) {
                    cout << "*" << ENDL;
                } else {
                    cout << res2 + 1 << ENDL;
                }
            } else {
                int res1 = soldados[l].first;
                int res2 = soldados[r].second;

                if (res1 != -1) {
                    soldados[res1].second = res2;
                }
                soldados[res2].first = res1;
                if (res2 != -1) {
                    soldados[res2].first = res1;
                }
                soldados[res1].second = res2;

                // IMPRESION
                if (res1 == -1) {
                    cout << "* ";
                } else {
                    cout << res1 + 1 << " ";
                }

                if (res2 == -1) {
                    cout << "*" << ENDL;
                } else {
                    cout << res2 + 1 << ENDL;
                }
            }
        }
        cout << '-' << ENDL;
    }

    return 0;
}
