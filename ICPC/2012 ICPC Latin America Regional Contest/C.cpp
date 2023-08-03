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
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)

#define ENDL '\n'

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int INF = 1 << 28;
const ll LLINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

struct TrieNode {
    map<char, TrieNode *> children;
    bool isEndOfWord;
    int numPrefix;
    char sig;

    TrieNode() {
        isEndOfWord = false;
        numPrefix = 0;
        sig = '-';
    }
};

class Trie {
  private:
    TrieNode *root;

  public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *curr = root;
        int len = word.length();
        for (int i = 0; i < len; i++) {
            if (curr->children.find(word[i]) == curr->children.end()) {
                curr->children[word[i]] = new TrieNode();
            }
            curr = curr->children[word[i]];
            if (curr->sig == '-') {
                if (i + 1 == len) {
                    curr->sig = '+';
                } else {
                    curr->sig = word[i + 1];
                }
            } else {
                if (i + 1 == len) {
                    curr->sig = '*';
                }
                if (word[i + 1] != curr->sig) {
                    curr->sig = '*';
                }
            }
            curr->numPrefix++;
        }
        curr->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode *curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                return false;
            }
            curr = curr->children[c];
        }
        return curr->isEndOfWord;
    }

    int countPrefix(string prefix) {
        TrieNode *curr = root;
        for (char c : prefix) {
            if (curr->children.find(c) == curr->children.end()) {
                return 0;
            }
            curr = curr->children[c];
        }
        return curr->numPrefix;
    }

    int countLetters(string word) {
        int cont = 0;
        TrieNode *curr = root;

        int len = word.length();
        F0R(i, len) {
            if (i == 0) {
                cont++;
            } else {
                if (curr->sig == '*') {
                    cont++;
                }
            }
            curr = curr->children[word[i]];
        }
        return cont;
    }
};

string palabras[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        Trie trie;

        F0R(i, n) {
            cin >> palabras[i];
            trie.insert(palabras[i]);
        }
        int pressKey = 0;
        F0R(i, n) {
            pressKey += trie.countLetters(palabras[i]);
        }
        double ans = (double)pressKey / n;
        cout << setprecision(2) << fixed << ans << ENDL;
    }

    return 0;
}
