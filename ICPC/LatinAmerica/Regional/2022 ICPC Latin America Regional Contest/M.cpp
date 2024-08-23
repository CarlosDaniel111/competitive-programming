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

bool tablero[MAXN][105];
int n, m;
unordered_set<string> pasadas[MAXN];

string convertir(vector<bool> tuerca) {
    string s = "";
    FOR(i, m) {
        s += char('0' + tuerca[i]);
    }
    return s;
}

bool puedeEncajar(int fila, vector<bool> tuerca) {
    FOR(i, m) {
        if (tuerca[i] == 1 && tablero[fila][i] == 1) {
            return false;
        }
    }
    return true;
}

bool solve(int fila, vector<bool> tuerca) {
    if (fila == n - 1)
        return true;

    if (fila != -1) {
        if (pasadas[fila].count(convertir(tuerca)))
            return false;
        pasadas[fila].insert(convertir(tuerca));
    }

    // Bajar sin dar vueltas
    if (puedeEncajar(fila + 1, tuerca) && solve(fila + 1, tuerca))
        return true;

    vector<bool> aux(m);

    // Vueltas a la derecha
    FOR(i, m) {
        FOR(j, m) {
            aux[j] = tuerca[(j + i) % m];
        }

        // No se puede dar mas vueltas
        if (fila != -1 && !puedeEncajar(fila, aux))
            break;

        // Subir la tuerca
        if (fila > 0 && puedeEncajar(fila - 1, aux) && solve(fila - 1, aux))
            return true;

        // Bajar la tuerca
        if (puedeEncajar(fila + 1, aux) && solve(fila + 1, aux))
            return true;
    }

    // Vueltas a la izquierda
    FOR(i, m) {
        FOR(j, m) {
            aux[j] = tuerca[(j - i + m) % m];
        }

        // No se puede dar mas vueltas
        if (fila != -1 && !puedeEncajar(fila, aux))
            break;

        // Subir la tuerca
        if (fila > 0 && puedeEncajar(fila - 1, aux) && solve(fila - 1, aux))
            return true;

        // Bajar la tuerca
        if (puedeEncajar(fila + 1, aux) && solve(fila + 1, aux))
            return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m;
    string cadena;
    vector<bool> tuerca(m);

    cin >> cadena;
    FOR(i, m) {
        tuerca[i] = cadena[i] == '1';
    }
    FOR(i, n) {
        cin >> cadena;
        FOR(j, m) {
            tablero[i][j] = cadena[j] == '1';
        }
    }

    if (solve(-1, tuerca)) {
        cout << 'Y' << ENDL;
        return 0;
    }
    reverse(all(tuerca));
    if (solve(-1, tuerca)) {
        cout << 'Y' << ENDL;
        return 0;
    }
    cout << 'N' << ENDL;

    return 0;
}
