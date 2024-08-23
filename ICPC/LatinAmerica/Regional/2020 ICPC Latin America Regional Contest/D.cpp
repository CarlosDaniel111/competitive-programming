#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e6 + 7;

int cont[MAXN];

int main() {
    int n;
    cin >> n;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        cont[x]++;
    }
    int aux = 0;
    FOR(i, 0, MAXN - 1) {
        if (cont[i] >= 2) {
            cont[i + 1] += cont[i] / 2;
            if (cont[i] % 2 != 0) {
                aux++;
            }
        } else if (cont[i] == 1) {
            aux++;
        }
    }

    if (aux == 2 || (aux == 1 && n >= 2)) {
        cout << "Y" << ENDL;
    } else {
        cout << "N" << ENDL;
    }

    return 0;
}