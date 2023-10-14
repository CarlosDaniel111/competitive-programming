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
typedef tuple<int, int, int> iii;

bool bs[MAXN];
vll primes;

int bit[MAXN + 5];

int query(int index) {
    int sum = 0;
    index++;
    while (index > 0) {
        sum += bit[index];
        index -= index & (-index);
    }
    return sum;
}

int query2(int a, int b) {
    return query(b) - query(a - 1);
}

void update(int index, int val) {
    index++;
    while (index <= MAXN) {
        bit[index] += val;
        index += index & (-index);
    }
}

void criba(ll criba_tamanio) {
    memset(bs, 1, sizeof(bs));
    bs[0] = bs[1] = 0;
    for (ll p = 2; p < criba_tamanio; p++) {
        if (bs[p]) {
            for (ll i = p * p; i < criba_tamanio; i += p) {
                bs[i] = false;
            }
            primes.push_back(p);
        }
    }
}

vector<iii> queries;
int res[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    FOR(i, MAXN) {
        update(i, 1);
    }
    criba(MAXN);

    int q, n, k;
    cin >> q;
    FOR(i, q) {
        cin >> n >> k;
        queries.push_back({k, n, i});
    }

    sort(queries.rbegin(), queries.rend());

    int indicePrimo = primes.size() - 1;

    int K, N, I;

    FOR(caso, q) {
        tie(K, N, I) = queries[caso];
        while (primes[indicePrimo] > K) {
            for (int j = primes[indicePrimo]; j < MAXN; j += primes[indicePrimo]) {
                if (query2(j, j) != 0)
                    update(j, -1);
            }
            indicePrimo--;
        }
        res[I] = query2(2, N);
    }

    FOR(i, q) {
        cout << res[i] << ENDL;
    }

    return 0;
}
