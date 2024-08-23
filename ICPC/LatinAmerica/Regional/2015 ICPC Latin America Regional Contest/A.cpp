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
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // abajo, derecha, arriba, izquierda

template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

int cont[15];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    string numero;
    cin >> numero;
    int tam = numero.size();
    int error = -1;
    F0R(i, tam) {
        cont[numero[i] - '0']++;
        if (cont[numero[i] - '0'] == 3) {
            error = i;
            break;
        }
    }
    if (error == -1) {
        cout << numero << ENDL;
        return 0;
    }

    /*F0R(i, 9) {
        cout << cont[i] << " ";
    }
    cout << ENDL;*/

    bool cambiado = false;
    while (!cambiado) {
        int digit = numero[error] - '0';
        cont[digit]--;
        digit--;
        while (digit != -1) {
            if (cont[digit] < 2) {
                numero[error] = '0' + digit;
                cont[digit]++;
                cambiado = true;
                break;
            }
            digit--;
        }
        error--;
    }
    error += 2;
    FOR(i, error, tam) {
        int aux = 9;
        while (cont[aux] == 2) {
            aux--;
        }
        numero[i] = '0' + aux;
        cont[aux]++;
    }

    int i = 0;
    while (i < sz(numero) && numero[i] == '0') {
        i++;
    }

    numero = numero.substr(i);

    /*F0R(i, 9) {
        cout << cont[i] << " ";
    }
    cout << error << ENDL;*/
    cout << numero << ENDL;

    return 0;
}
