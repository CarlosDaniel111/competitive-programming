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

int k;

int solve(int i, int izq, int der) {
    if (i == k)
        return solve(i + 1, izq, der);
    if (i > izq && i > der)
        return izq + der;
    int ans = solve(i + 1, izq, der);
    if (izq >= i)
        ans = min(ans, solve(i + 1, izq - i, der));
    if (der >= i)
        ans = min(ans, solve(i + 1, izq, der - i));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, e;
    cin >> n >> k >> e;

    int der = n - k - e;
    if (der >= 5)
        der = 0;
    if (e >= 5)
        e = 0;

    cout << solve(1, e, der) << ENDL;

    return 0;
}
