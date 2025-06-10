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

struct Node {
  Node *l = 0, *r = 0;
  int val, y, c = 1;
  int s;
  bool rev;
  Node(int val) : val(val), y(rand()), s(val), rev(false) {}
  void recalc();
};

int sum(Node* n) { return n ? n->s : 0ll; }
int cnt(Node* n) { return n ? n->c : 0; }
void Node::recalc() {
  c = cnt(l) + cnt(r) + 1;
  s = val + sum(l) + sum(r);
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

pair<Node*, Node*> split(Node* n, int k) {
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

int kth(Node* n, int k) {
  push(n);
  if (cnt(n->l) > k)
    return kth(n->l, k);
  else if (cnt(n->l) < k)
    return kth(n->r, k - cnt(n->l) - 1);
  return n->val;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  Node* treap = new Node(1);
  FOR(i, 2, n + 1) {
    Node* sig = new Node(i);
    treap = merge(treap, sig);
  }

  Node *A, *B, *C, *D, *E;
  FOR(i, 0, n) {
    int a, b;
    cin >> a >> b;
    if (b <= a) continue;
    int len = min(b - a, n - b + 1);
    tie(A, B) = split(treap, a - 1);
    tie(B, C) = split(B, len);
    tie(C, D) = split(C, b - a - len);
    tie(D, E) = split(D, len);
    treap = merge(merge(merge(merge(A, D), C), B), E);
  }

  FOR(i, 0, n) { cout << kth(treap, i) << " "; }

  return 0;
}