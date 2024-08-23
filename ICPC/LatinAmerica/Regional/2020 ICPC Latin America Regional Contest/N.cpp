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

pair<int, int> getMoney() {
    char c;
    cin >> c;

    string s;
    cin >> s;

    int entero = 0, decimal = 0;
    if (s[1] == '.') {
        entero = s[0] - '0';
        decimal = (s[2] - '0') * 10 + (s[3] - '0');
    } else {
        entero = (s[0] - '0') * 10 + s[1] - '0';
        decimal = (s[3] - '0') * 10 + s[4] - '0';
    }
    return {entero, decimal};
}

int main() {
    int n;
    cin >> n;

    auto [enteroInicial, decimalInicial] = getMoney();

    int ans = 0;
    while (n--) {
        auto [entero, decimal] = getMoney();
        enteroInicial += entero;
        decimalInicial += decimal;

        ans += decimalInicial % 100 != 0;
    }
    cout << ans << ENDL;

    return 0;
}