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

vi taken;

struct City {
    int v;
    ull distancia, costo;
};

struct CompareCity {
    bool operator()(City const &c1, City const &c2) {
        if (c1.distancia != c2.distancia) {
            return c1.distancia > c2.distancia;
        } else {
            return c1.costo > c2.costo;
        }
    }
};

priority_queue<City, vector<City>, CompareCity> pq;

void process(vector<vector<City>> &adjlist, int vtx, City a) {
    taken[vtx] = 1;
    for (int j = 0; j < (int)adjlist[vtx].size(); j++) {
        City v = adjlist[vtx][j];
        pq.push(City{v.v, v.distancia + a.distancia, v.costo});
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    taken.assign(n + 1, 0);
    vector<vector<City>> graph(n + 1);
    for (int i = 0; i <= n; i++) {
        vector<City> vec;
        graph[i] = vec;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        ull l, c;
        cin >> a >> b >> l >> c;
        graph[a].push_back(City{b, l, c});
        graph[b].push_back(City{a, l, c});
    }
    ull resp = 0;
    pq.push(City{1, 0, 0});
    while (!pq.empty()) {
        City front = pq.top();
        pq.pop();
        int u = front.v;
        if (!taken[u]) {
            resp += front.costo;
            process(graph, u, front);
        }
    }

    cout << resp << '\n';
    return 0;
}