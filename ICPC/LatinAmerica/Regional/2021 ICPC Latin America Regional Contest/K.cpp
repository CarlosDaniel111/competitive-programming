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

vector<bool> letras(26, false);

bool checar(string &s) {
    for (char c : s) {
        if (!letras[c - 'A']) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> palabras(n);
    FOR(i, 0, n) {
        string s;
        cin >> palabras[i];
        letras[palabras[i][0] - 'A'] = true;
    }
    FOR(i, 0, n) {
        string s = palabras[i];
        if (checar(s)) {
            cout << 'Y' << ENDL;
            return 0;
        }
    }
    cout << "N" << ENDL;

    return 0;
}