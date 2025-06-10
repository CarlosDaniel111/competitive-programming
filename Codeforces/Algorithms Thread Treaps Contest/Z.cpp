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

constexpr ll N = 5e5 + 5;

struct Node {
  Node *l = 0, *r = 0;
  ll val, y, c = 1;
  ll s, fa, idx;
  Node(ll i, ll val) : val(val), y(rand()), s(val), idx(i), fa(i) {}
  void recalc();
};

ll sum(Node* n) { return n ? n->s : 0ll; }
ll cnt(Node* n) { return n ? n->c : 0; }
void Node::recalc() {
  c = cnt(l) + cnt(r) + 1;
  s = val + sum(l) + sum(r);
}

pair<Node*, Node*> split(Node* n, ll k) {
  if (!n) return {};
  if (cnt(n->l) >= k) {  // "n->val >= k" para usar lower_bound(k)
    auto [L, R] = split(n->l, k);
    n->l = R;
    n->recalc();
    if (n->l) n->l->fa = n->idx;
    return {L, n};
  } else {
    auto [L, R] = split(n->r, k - cnt(n->l) - 1);  // y solo "k"
    n->r = L;
    n->recalc();
    if (n->r) n->r->fa = n->idx;
    return {n, R};
  }
}

Node* merge(Node* l, Node* r) {
  if (!l) return r;
  if (!r) return l;
  if (l->y > r->y) {
    l->r = merge(l->r, r);
    if (l->l) l->l->fa = l->idx;
    if (l->r) l->r->fa = l->idx;
    return l->recalc(), l;
  } else {
    r->l = merge(l, r->l);
    if (r->l) r->l->fa = r->idx;
    if (r->r) r->r->fa = r->idx;
    return r->recalc(), r;
  }
}

ll kth(Node* n, ll k) {
  if (cnt(n->l) > k)
    return kth(n->l, k);
  else if (cnt(n->l) < k)
    return kth(n->r, k - cnt(n->l) - 1);
  return n->val;
}

Node* nodos[N];

ll find(ll x) {
  if (nodos[x]->fa == x) return x;
  return find(nodos[x]->fa);
}

void Merge(ll x, ll y) {
  x = find(x), y = find(y);
  if (x == y) return;
  merge(nodos[x], nodos[y]);
}

void Split(ll x, ll k) {
  x = find(x);
  if (cnt(nodos[x]) <= k) return;
  auto [A, B] = split(nodos[x], k);
  if (A) A->fa = A->idx;
  if (B) B->fa = B->idx;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll q;
  cin >> q;
  FOR(i, 1, q + 1) {
    ll opc, x, y;
    cin >> opc >> x;
    if (opc == 1)
      nodos[i] = new Node(i, x);
    else if (opc == 2) {
      cin >> y;
      Merge(x, y);
    } else if (opc == 3) {
      cin >> y;
      Split(x, y);
    } else {
      cout << nodos[find(x)]->s << ENDL;
    }
  }

  return 0;
}