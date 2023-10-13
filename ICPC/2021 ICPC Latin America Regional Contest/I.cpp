#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;
// AC2++
int ans = INF;

void lunes(int x) {
    if (x == 0) {
        ans = min(ans, 30);
        return;
    }
    if (x % 91 == 0) {
        ans = 0;
        return;
    }
    x %= 91;
    if (x > 60) {
        int falta = 91 - x;
        ans = min(ans, falta);
    } else if (x > 30) {
        int falta = 60 - x;
        ans = min(ans, falta);
    } else {
        int falta = 30 - x;
        ans = min(ans, falta);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    unordered_map<string, int> semana;
    semana["Mon"] = 0;
    semana["Tue"] = 1;
    semana["Wed"] = 2;
    semana["Thu"] = 3;
    semana["Fri"] = 4;
    semana["Sat"] = 5;
    semana["Sun"] = 6;

    string s;
    int n;
    cin >> s >> n;
    int hoy = semana[s];

    FOR(i, 0, n) {
        int d;
        cin >> d;
        int aux = d % 7;
        int inicio = ((hoy - aux) + 7) % 7;
        if (inicio == 0) {
            lunes(d);
        } else if (inicio == 1) {
            if (d == 62) {
                cout << 0 << ENDL;
                return 0;
            } else if (d > 62) {
                lunes(d - 62);
            } else {
                if (d > 30) {
                    ans = min(ans, 62 - d);
                } else {
                    ans = min(ans, 30 - d);
                }
            }
        } else if (inicio == 2) {
            if (d == 61) {
                cout << 0 << ENDL;
                return 0;
            } else if (d > 61) {
                lunes(d - 61);
            } else {
                if (d > 30) {
                    ans = min(ans, 61 - d);
                } else {
                    ans = min(ans, 30 - d);
                }
            }
        } else if (inicio == 3) {
            if (d == 32) {
                cout << 0 << ENDL;
                return 0;
            } else if (d > 32) {
                lunes(d - 32);
            } else {
                ans = min(ans, 32 - d);
            }
        } else if (inicio == 4) {
            if (d == 31) {
                cout << 0 << ENDL;
                return 0;
            } else if (d > 31) {
                lunes(d - 31);
            } else {
                ans = min(ans, 31 - d);
            }
        }
        // cout << ans << ENDL;
    }
    cout << ans << ENDL;

    return 0;
}