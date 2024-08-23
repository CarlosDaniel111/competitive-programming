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

    string mat[10][3];
    mat[1][0] = "*.";
    mat[1][1] = "..";
    mat[1][2] = "..";

    mat[2][0] = "*.";
    mat[2][1] = "*.";
    mat[2][2] = "..";

    mat[3][0] = "**";
    mat[3][1] = "..";
    mat[3][2] = "..";

    mat[4][0] = "**";
    mat[4][1] = ".*";
    mat[4][2] = "..";

    mat[5][0] = "*.";
    mat[5][1] = ".*";
    mat[5][2] = "..";

    mat[6][0] = "**";
    mat[6][1] = "*.";
    mat[6][2] = "..";

    mat[7][0] = "**";
    mat[7][1] = "**";
    mat[7][2] = "..";

    mat[8][0] = "*.";
    mat[8][1] = "**";
    mat[8][2] = "..";

    mat[9][0] = ".*";
    mat[9][1] = "*.";
    mat[9][2] = "..";

    mat[0][0] = ".*";
    mat[0][1] = "**";
    mat[0][2] = "..";

    unordered_map<string, int> m;
    FOR(i, 10) {
        m[mat[i][0] + mat[i][1] + mat[i][2]] = i;
    }

    int d;
    while (cin >> d) {
        if (d == 0)
            break;

        char op;
        cin >> op;
        if (op == 'S') {
            string s;
            cin >> s;
            FOR(i, 3) {
                for (auto c : s) {
                    cout << mat[c - '0'][i] << ' ';
                }
                if (i < 2)
                    cout << ENDL;
            }
            cout << ENDL;
        } else {
            string lines[d];
            FOR(i, d)
            lines[i] = "";
            FOR(i, 3) {
                int k = 0;
                FOR(j, d) {
                    string line;
                    cin >> line;
                    lines[k] += line;
                    k = (k + 1) % d;
                }
            }
            FOR(i, d) {
                cout << m[lines[i]];
            }
            cout << ENDL;
        }
    }

    return 0;
}
