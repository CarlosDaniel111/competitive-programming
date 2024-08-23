#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define eb emplace_back
#define ENDL '\n'
#define FOR(x, n) for (long long x = 0; x < (long long)n; x++)
#define FOR1(x, n) for (long long x = 1; x <= (long long)n; x++)
#define FORR(x, n) for (long long x = n - 1; x >= 0; x--)
#define FORR1(x, n) for (long long x = n; x >= 1; x--)
const long long INF = 1 << 28, MOD = 1e9 + 7, MAXN = 1e4 + 5;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pair<int, int>> vii;

double dp[MAXN];
double costo[MAXN];
int tiempo[MAXN];
int n;

double solve(int i) {
    if (i >= n)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    double costoActual = costo[i];
    int tiempoActual = tiempo[i];
    double res = costoActual + solve(i + 1);
    if (tiempoActual < 120) {
        costoActual += (costo[i + 1] / 2);
        tiempoActual += tiempo[i + 1];
        res = min(res, costoActual + solve(i + 2));
        for (int j = 2; j < 6; j++) {
            if (tiempoActual < 120) {
                costoActual += (costo[i + j] / 4);
                tiempoActual += tiempo[i + j];
                res = min(res, costoActual + solve(i + j + 1));
            } else {
                break;
            }
        }
    }
    dp[i] = res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;
    FOR(i, n) {
        cin >> tiempo[i] >> costo[i];
    }

    FOR(i, MAXN) {
        dp[i] = -1;
    }

    double res = solve(0);

    printf("%.2f", res);

    return 0;
}
