#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'
constexpr ll N = 3e5 + 10, MOD = 1e9 + 7, H = 431887867;
ll pw[N];

void calc() {
  pw[0] = 1;
  FOR(i, 1, N) pw[i] = (pw[i - 1] * H) % MOD;
}

struct Node {
  Node *l = 0, *r = 0;
  ll val, y, c = 1;
  ll hLR, hRL;
  ll s;
  bool rev;
  Node(ll val) : val(val), y(rand()), s(val), rev(false), hLR(val), hRL(val) {}
  void recalc();
};

ll sum(Node* n) { return n ? n->s : 0ll; }
ll cnt(Node* n) { return n ? n->c : 0ll; }
ll getHashLR(Node* n) { return n ? n->hLR : 0ll; }
ll getHashRL(Node* n) { return n ? n->hRL : 0ll; }
void Node::recalc() {
  c = cnt(l) + cnt(r) + 1;
  s = val + sum(l) + sum(r);
  hLR = (getHashLR(l) + pw[cnt(l)] * val) % MOD;
  (hLR += pw[cnt(l) + 1] * getHashLR(r)) %= MOD;

  hRL = (getHashRL(r) + pw[cnt(r)] * val) % MOD;
  (hRL += pw[cnt(r) + 1] * getHashRL(l)) %= MOD;
}

void apply(Node* n) {
  if (n) {
    n->rev ^= 1;
    swap(n->l, n->r);
  }
}

void push(Node* n) {
  if (n && n->rev) {
    apply(n->l);
    apply(n->r);
    n->rev = false;
  }
}

pair<Node*, Node*> split(Node* n, ll k) {
  if (!n) return {};
  push(n);
  if (cnt(n->l) >= k) {  // "n->val >= k" para usar lower_bound(k)
    auto [L, R] = split(n->l, k);
    n->l = R;
    n->recalc();
    return {L, n};
  } else {
    auto [L, R] = split(n->r, k - cnt(n->l) - 1);  // y solo "k"
    n->r = L;
    n->recalc();
    return {n, R};
  }
}

Node* merge(Node* l, Node* r) {
  push(l);
  push(r);
  if (!l) return r;
  if (!r) return l;
  if (l->y > r->y) {
    l->r = merge(l->r, r);
    return l->recalc(), l;
  } else {
    r->l = merge(l, r->l);
    return r->recalc(), r;
  }
}

Node* ins(Node* t, Node* n, ll pos) {
  auto [l, r] = split(t, pos);
  return merge(merge(l, n), r);
}

void print(Node* t) {
  if (!t) return;
  print(t->l);
  cout << t->val << " ";
  print(t->r);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  calc();
  ll n, m;
  cin >> n >> m;

  string s;
  cin >> s;
  Node* treap = new Node(s[0] - 'a' + 1);
  FOR(i, 1, n) {
    char c = s[i];
    Node* sig = new Node(c - 'a' + 1);
    treap = merge(treap, sig);
  }
  Node *A, *B, *C, *D, *E;
  FOR(i, 0, m) {
    ll opc;
    cin >> opc;
    if (opc == 1) {
      ll l, r;
      cin >> l >> r;
      l--, r--;
      tie(A, B) = split(treap, l);
      tie(B, C) = split(B, r - l + 1);
      treap = merge(A, C);
    } else if (opc == 2) {
      char c;
      ll pos;
      cin >> c >> pos;
      Node* n = new Node(c - 'a' + 1);
      treap = ins(treap, n, pos - 1);
    } else {
      ll l, r;
      cin >> l >> r;
      l--, r--;
      ll len = (r - l + 1);
      tie(A, B) = split(treap, l);
      tie(B, C) = split(B, len);
      if (getHashLR(B) == getHashRL(B)) {
        cout << "yes" << ENDL;
      } else {
        cout << "no" << ENDL;
      }
      treap = merge(merge(A, B), C);
    }
  }

  return 0;
}