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

int puntos[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, x, total = 0, cont = 0;
    cin >> n;
    FOR(i, n) {
        cin >> x;
        total += x;
        puntos[i] = total;
    }

    int i = 0;
    while ((2 * puntos[i]) <= total) {
        int j = i + 1;
        while ((2 * (puntos[j] - puntos[i])) < total)
            j++;
        if (2 * (puntos[j] - puntos[i]) == total) {
            cont++;
            if (cont == 2)
                break;
        }
        i++;
    }

    cout << (cont >= 2 ? 'Y' : 'N');

    return 0;
}
