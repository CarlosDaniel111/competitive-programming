#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
#define ENDL '\n'
#define FOR(x, n) for (long long x = 0; x < (long long)n; x++)
#define FOR1(x, n) for (long long x = 1; x <= (long long)n; x++)
#define FORR(x, n) for (long long x = n - 1; x >= 0; x--)
#define FORR1(x, n) for (long long x = n; x >= 1; x--)
const long long INF = 1 << 28, MOD = 1e9 + 7, MAXN = 1e3 + 5;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vii;

int res[MAXN][MAXN];
int dp[MAXN][MAXN];
string cadena;
int len, n;

char solve(int i, int residuo) {
    if (i == len) {
        return !residuo;
    }
    if (dp[i][residuo] != -1)
        return dp[i][residuo];

    bool puede = false;
    if (cadena[i] != '?') {
        int digito = cadena[i] - '0';
        if (solve(i + 1, (10 * residuo + digito) % n)) {
            res[i][residuo] = digito;
            puede = true;
        }
    } else {
        int j = (i == 0);
        for (; j < 10; j++) {
            if (solve(i + 1, (10 * residuo + j) % n)) {
                res[i][residuo] = j;
                puede = true;
                break;
            }
        }
    }
    dp[i][residuo] = puede;
    return (dp[i][residuo]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> cadena >> n;
    memset(dp, -1, sizeof(dp));

    len = cadena.length();
    if (!solve(0, 0)) {
        cout << '*' << ENDL;
        return 0;
    }
    int residuo = 0;
    FOR(i, len) {
        cout << char('0' + res[i][residuo]);
        residuo = (10 * residuo + res[i][residuo]) % n;
    }
    cout << ENDL;

    return 0;
}
