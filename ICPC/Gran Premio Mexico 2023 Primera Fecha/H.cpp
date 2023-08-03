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

vi patternPos[MAXN];

struct Vertex {
    unordered_map<char, int> children;
    bool leaf;
    int parent, suffixLink, wordID, endWordLink;
    char parentChar;

    Vertex() {
        children.clear();
        leaf = false;
        parent = suffixLink = wordID = endWordLink = -1;
    }
};

class Aho {
   private:
    vector<Vertex *> Trie;
    vector<int> wordsLength;
    int size, root;

    void calcSuffixLink(int vertex) {
        // Procesar root
        if (vertex == root) {
            Trie[vertex]->suffixLink = root;
            Trie[vertex]->endWordLink = root;
            return;
        }
        // Procesamiento de hijos de la raiz
        if (Trie[vertex]->parent == root) {
            Trie[vertex]->suffixLink = root;
            if (Trie[vertex]->leaf) {
                Trie[vertex]->endWordLink = vertex;
            } else {
                Trie[vertex]->endWordLink =
                    Trie[Trie[vertex]->suffixLink]->endWordLink;
            }
            return;
        }

        // Para calcular el sufijo link para el vértice actual, necesitamos el
        // sufijo
        // enlace para el padre del vértice y el personaje que nos movió a la
        // vértice actual.
        int curBetterVertex = Trie[Trie[vertex]->parent]->suffixLink;
        char chVertex = Trie[vertex]->parentChar;
        while (true) {
            if (Trie[curBetterVertex]->children.count(chVertex)) {
                Trie[vertex]->suffixLink =
                    Trie[curBetterVertex]->children[chVertex];
                break;
            }
            if (curBetterVertex == root) {
                Trie[vertex]->suffixLink = root;
                break;
            }
            curBetterVertex = Trie[curBetterVertex]->suffixLink;
        }

        if (Trie[vertex]->leaf) {
            Trie[vertex]->endWordLink = vertex;
        } else {
            Trie[vertex]->endWordLink =
                Trie[Trie[vertex]->suffixLink]->endWordLink;
        }
    }

   public:
    Aho() {
        size = root = 0;
        Trie.pb(new Vertex());
        size++;
    }

    void addString(string s, int wordID) {
        int curVertex = root;
        F0R(i, s.length()) {  // Iteracion sobre los caracteres de la cadena
            char c = s[i];
            if (!Trie[curVertex]->children.count(c)) {
                Trie.pb(new Vertex());
                Trie[size]->suffixLink = -1;
                Trie[size]->parent = curVertex;
                Trie[size]->parentChar = c;
                Trie[curVertex]->children[c] = size;
                size++;
            }
            curVertex = Trie[curVertex]
                            ->children[c];  // Mover al nuevo vertice en el trie
        }
        // Marcar el final de la palabra y almacene su ID
        Trie[curVertex]->leaf = true;
        Trie[curVertex]->wordID = wordID;
        wordsLength.pb(s.length());
    }

    void prepareAho() {
        queue<int> vertexQueue;
        vertexQueue.push(root);
        while (!vertexQueue.empty()) {
            int curVertex = vertexQueue.front();
            vertexQueue.pop();
            calcSuffixLink(curVertex);
            for (auto key : Trie[curVertex]->children) {
                vertexQueue.push(key.second);
            }
        }
    }

    void processString(string text) {
        int currentState = root;
        int result = 0;
        F0R(j, text.length()) {
            while (true) {
                if (Trie[currentState]->children.count(text[j])) {
                    currentState = Trie[currentState]->children[text[j]];
                    break;
                }
                if (currentState == root) break;
                currentState = Trie[currentState]->suffixLink;
            }
            int checkState = currentState;
            // Tratar de encontrar todas las palabras posibles de este prefijo
            while (true) {
                checkState = Trie[checkState]->endWordLink;

                // Si estamos en el vertice raiz, no hay mas coincidencias
                if (checkState == root) break;

                int indexOfMatch =
                    j + 1 - wordsLength[Trie[checkState]->wordID];
                patternPos[indexOfMatch].pb(Trie[checkState]->wordID);

                // Tratando de encontrar todos los patrones combinados de menor
                // longitud
                checkState = Trie[checkState]->suffixLink;
            }
        }
    }
};

int tam;
ll dp[MAXN];
string patterns[MAXN];
ll solve(int i) {
    if (i == tam) return 1;
    ll &ans = dp[i];
    if (ans != -1) return ans;
    ans = 0;
    for (auto x : patternPos[i]) {
        ans += solve(i + patterns[x].size());
        ans %= MOD;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    Aho ahoAlg;
    F0R(i, n) {
        cin >> patterns[i];
        ahoAlg.addString(patterns[i], i);
    }
    ahoAlg.prepareAho();
    string text;
    cin >> text;
    tam = text.size();
    ahoAlg.processString(text);

    cout << solve(0) % MOD << ENDL;

    return 0;
}