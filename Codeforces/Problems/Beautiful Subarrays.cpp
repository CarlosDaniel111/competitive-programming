#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

struct TrieNode {
  TrieNode* children[2];
  int cnt;
};

struct Trie {
  TrieNode* root;
  int k;
  Trie(int k) : k(k) { root = new TrieNode(); }

  void insert(int x) {
    TrieNode* curr = root;
    for (int i = 30; i >= 0; i--) {
      int b = (x >> i) & 1;
      if (curr->children[b] == nullptr) {
        curr->children[b] = new TrieNode();
      }
      curr = curr->children[b];
      curr->cnt++;
    }
  }

  ll get(int x) {
    TrieNode* curr = root;
    ll res = 0;
    bool add = 1;
    for (int i = 30; i >= 0; i--) {
      int bx = (x >> i) & 1, bk = (k >> i) & 1;
      if (!bk && curr->children[!bx] != nullptr)
        res += curr->children[!bx]->cnt;
      if (curr->children[bx xor bk] == nullptr) {
        add = 0;
        break;
      }
      curr = curr->children[bx xor bk];
    }
    if (add) res += curr->cnt;
    return res;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k;
  cin >> n >> k;
  int pref = 0;
  Trie trie(k);
  trie.insert(0);
  ll ans = 0;
  FOR(i, 0, n) {
    int x;
    cin >> x;
    pref = pref xor x;
    ans += trie.get(pref);
    trie.insert(pref);
  }
  cout << ans << ENDL;

  return 0;
}