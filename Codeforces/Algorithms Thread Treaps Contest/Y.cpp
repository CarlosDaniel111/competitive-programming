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
  bool rev;
  int mx0, mx1, pref0, pref1, suff0, suff1;
  Node(int val) : val(val), y(rand()), rev(false) {
    mx0 = pref0 = suff0 = (val == 0);
    mx1 = pref1 = suff1 = (val == 1);
  }
  void recalc();
};

int cnt(Node* n) { return n ? n->c : 0; }
int getPref0(Node* n) { return n ? n->pref0 : 0; }
int getPref1(Node* n) { return n ? n->pref1 : 0; }
int getSuff0(Node* n) { return n ? n->suff0 : 0; }
int getSuff1(Node* n) { return n ? n->suff1 : 0; }
void Node::recalc() {
  c = cnt(l) + cnt(r) + 1;

  mx0 = max(l ? l->mx0 : 0, r ? r->mx0 : 0);
  mx1 = max(l ? l->mx1 : 0, r ? r->mx1 : 0);

  if (val == 0)
    mx0 = max(mx0, (l ? l->suff0 : 0) + 1 + (r ? r->pref0 : 0));
  else
    mx1 = max(mx1, (l ? l->suff1 : 0) + 1 + (r ? r->pref1 : 0));

  pref0 = ((getPref0(l) == cnt(l) && val == 0) ? getPref0(l) + 1 + getPref0(r)
                                               : getPref0(l));
  pref1 = ((getPref1(l) == cnt(l) && val == 1) ? getPref1(l) + 1 + getPref1(r)
                                               : getPref1(l));

  suff0 = ((getSuff0(r) == cnt(r) && val == 0) ? getSuff0(r) + 1 + getSuff0(l)
                                               : getSuff0(r));

  suff1 = ((getSuff1(r) == cnt(r) && val == 1) ? getSuff1(r) + 1 + getSuff1(l)
                                               : getSuff1(r));
}

void apply(Node* n) {
  if (n) {
    swap(n->mx0, n->mx1);
    swap(n->pref0, n->pref1);
    swap(n->suff0, n->suff1);
    n->rev ^= 1;
    n->val ^= 1;
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
  if (cnt(n->l) >= k) {
    auto [L, R] = split(n->l, k);
    n->l = R;
    n->recalc();
    return {L, n};
  } else {
    auto [L, R] = split(n->r, k - cnt(n->l) - 1);
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

void flip(Node*& t, int l, int r) {
  Node *a, *b, *c;
  tie(a, b) = split(t, l);
  tie(b, c) = split(b, r - l);
  apply(b);
  t = merge(merge(a, b), c);
}

void print(Node* t) {
  if (!t) return;
  print(t->l);
  cout << t->val << " ";
  print(t->r);
}

int get(Node* t) { return max(t->mx0, t->mx1); }

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  Node* t = nullptr;
  FOR(i, 0, n) {
    char c;
    cin >> c;
    t = (t ? merge(t, new Node(c - '0')) : new Node(c - '0'));
  }
  while (q--) {
    int opc, l, r;
    cin >> opc >> l >> r;
    l--;
    flip(t, l, r);
    cout << get(t) << ENDL;
  }

  return 0;
}