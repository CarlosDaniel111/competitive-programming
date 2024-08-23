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

int arr[MAXN] = {0};
int n, m;

bool checar() {
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m;

    FOR(i, m) {
        int x;
        cin >> x;
        arr[x]++;
    }
    int may = -1, itermay;
    int min = INF, itermin;
    FOR1(i, n) {
        if (arr[i] > may) {
            may = arr[i];
            itermay = i;
        }
        if (arr[i] < min) {
            min = arr[i];
            itermin = i;
        }
    }

    arr[itermay]--;
    if (checar()) {
        cout << "-" << itermay << ENDL;
        return 0;
    } else {
        arr[itermay]++;
    }

    arr[itermin]++;
    if (checar()) {
        cout << "+" << itermin << ENDL;
        return 0;
    } else {
        arr[itermin]--;
    }

    arr[itermay]--;
    arr[itermin]++;
    if (checar()) {
        cout << "-" << itermay << " +" << itermin << ENDL;
        return 0;
    }
    cout << "*" << ENDL;

    return 0;
}
