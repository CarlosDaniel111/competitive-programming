#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<double, double>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<double>;
using vs = vector<string>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

// pairs
#define mp make_pair
#define f first
#define s second

// vectors
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define tcT template <class T
tcT > int lwb(vector<T> &a, const T &b) { return int(lb(all(a), b) - bg(a)); }

// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define R0F(i, a) ROF(i, a, 0)

#define ENDL '\n'
#define LSOne(S) ((S) & -(S))

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int INF = 1 << 28;
const ll LLINF = 1e18;
const int dx[4] = {1, 0, -1, 0},
          dy[4] = {0, 1, 0, -1};  // abajo, derecha, arriba, izquierda

template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

int arr[27];
vector<pair<char, int>> pares;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, k;
    string word;
    cin >> n >> k;
    cin >> word;
    word += word;

    int i = 1;
    while (i != n) {
        if (word[n * 2 - 1] != word[0]) break;
        string word2 = word.substr(0, n * 2 - 1);
        word = word[n * 2 - 1] + word2;
        i++;
    }

    n *= 2;
    F0R(i, n) {
        int cont = 1;
        char letter = word[i];
        while (i != n - 1 && letter == word[i + 1]) {
            cont++;
            i++;
        }
        pares.pb({letter, cont});
    }
    if (pares.size() == 1) {
        cout << -1 << ENDL;
        return 0;
    }

    i = 0;
    int j = 0, sum = 0, res = 0;
    pi ans;

    while (i < pares.size()) {
        pi l = pares[i];
        arr[l.f - 'a'] += l.s;
        sum += l.s;

        while (arr[l.f - 'a'] > k) {
            auto c = pares[j];
            arr[c.f - 'a'] -= c.s;
            sum -= c.s;
            j++;
        }

        if (sum > res && sum <= n / 2) {
            res = sum;
            ans = {j, i};
        }
        i++;
    }

    string cadena = "";
    cout << res << ENDL;
    FOR(i, ans.f, ans.s + 1) {
        F0R(j, pares[i].s) { cadena += pares[i].f; }
    }
    cout << cadena << ENDL;

    return 0;
}
