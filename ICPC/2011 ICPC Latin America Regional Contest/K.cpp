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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int a, b, c;
    while (cin >> a >> b >> c && a) {
        if (a == 13 && b == 13 && c == 13) {
            cout << "*" << ENDL;
            continue;
        }
        if (a == b && a == c) {
            cout << a + 1 << ' ' << a + 1 << ' ' << a + 1 << ENDL;
        } else if (a == b || a == c || b == c) {
            if (a == c)
                swap(b, c);
            if (b == c)
                swap(a, c);

            if (a == 13 && b == 13 && c == 12) {
                cout << "1 1 1" << ENDL;
            } else if (c == 13) {
                cout << 1 << ' ' << a + 1 << ' ' << b + 1 << ENDL;
            } else {
                if (c + 1 == a)
                    c++;
                c++;
                if (c < a)
                    swap(c, a);
                cout << a << ' ' << b << ' ' << c << ENDL;
            }

        } else {
            cout << "1 1 2" << ENDL;
        }
    }
    return 0;
}
