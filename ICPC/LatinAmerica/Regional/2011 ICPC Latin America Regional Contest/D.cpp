#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

struct TrieNode {
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord;
    int numPrefix;

    TrieNode() : isEndOfWord(false), numPrefix(0) {}
};

class Trie {
   public:
    TrieNode *root;
    int stateCount;
    Trie() {
        root = new TrieNode();
        stateCount = 1;
    }

    void insert(string word) {
        TrieNode *curr = root;
        for (char c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new TrieNode();
                stateCount++;
            }
            curr = curr->children[c];
            curr->numPrefix++;
        }
        curr->isEndOfWord = true;
    }
};

int start[26];
int sc;

void suffixDfs(TrieNode *curr, int depth) {
    for (auto e : curr->children) {
        if (depth >= 1) {
            start[e.first - 'a']++;
        }
        suffixDfs(e.second, depth + 1);
    }
}

ll prefixDfs(TrieNode *curr, int depth) {
    ll ans = 0;
    if (depth >= 1) ans += sc - 1;
    for (auto e : curr->children) {
        if (depth >= 1) {
            ans -= start[e.first - 'a'];
        }
        ans += prefixDfs(e.second, depth + 1);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int P, S;
    while (cin >> P >> S && (P || S)) {
        Trie prefixTrie;
        Trie suffixTrie;
        memset(start, 0, sizeof(start));
        FOR(i, 0, P) {
            string s;
            cin >> s;
            prefixTrie.insert(s);
        }
        FOR(i, 0, S) {
            string s;
            cin >> s;
            reverse(ALL(s));
            suffixTrie.insert(s);
        }
        sc = suffixTrie.stateCount;

        suffixDfs(suffixTrie.root, 0);
        cout << prefixDfs(prefixTrie.root, 0) << ENDL;
    }

    return 0;
}