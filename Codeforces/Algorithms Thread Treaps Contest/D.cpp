#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define ENDL '\n'

constexpr ll INF = 1e17;

struct Node {
  Node *l = nullptr, *r = nullptr;
  ll val, sum, mx1, mx2;
  ll mxcnt, c = 1, y;
  ll add_lazy = 0;

  Node(ll v) : val(v), sum(v), mx1(v), mx2(-INF), mxcnt(1), y(rand()) {}
  void recalc();
};

ll cnt(Node* n) { return n ? n->c : 0; }
ll getsum(Node* n) { return n ? n->sum : 0; }

void Node::recalc() {
  c = 1 + cnt(l) + cnt(r);
  sum = val + getsum(l) + getsum(r);
  mx1 = val;
  mx2 = -INF;
  mxcnt = 1;

  auto check = [&](Node* ch) {
    if (!ch) return;
    if (ch->mx1 == mx1) {
      mxcnt += ch->mxcnt;
      mx2 = max(mx2, ch->mx2);
    } else if (ch->mx1 > mx1) {
      mx2 = max(mx2, max(mx1, ch->mx2));
      mx1 = ch->mx1;
      mxcnt = ch->mxcnt;
    } else {
      mx2 = max(mx2, ch->mx1);
    }
  };

  check(l);
  check(r);
}

void applyAdd(Node* n, ll v) {
  if (!n) return;
  n->val += v;
  n->sum += v * cnt(n);
  n->mx1 += v;
  if (n->mx2 != -INF) n->mx2 += v;
  n->add_lazy += v;
}

void applyChMin(Node* n, ll v) {
  if (!n) return;
  if (v >= n->mx1) return;
  n->sum -= (n->mx1 - v) * n->mxcnt;
  if (n->val == n->mx1) n->val = v;
  n->mx1 = v;
}

void push(Node* n) {
  if (!n) return;
  if (n->add_lazy) {
    applyAdd(n->l, n->add_lazy);
    applyAdd(n->r, n->add_lazy);
    n->add_lazy = 0;
  }
  applyChMin(n->l, n->mx1);
  applyChMin(n->r, n->mx1);
}

void updChMin(Node* n, ll v) {
  if (!n || v >= n->mx1) return;
  if (v > n->mx2) {
    applyChMin(n, v);
    return;
  }
  push(n);
  updChMin(n->l, v);
  updChMin(n->r, v);
  if (n->val > v) n->val = v;
  n->recalc();
}

pair<Node*, Node*> split(Node* n, ll k) {
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
  if (!l || !r) return l ? l : r;
  if (l->y > r->y) {
    l->r = merge(l->r, r);
    l->recalc();
    return l;
  } else {
    r->l = merge(l, r->l);
    r->recalc();
    return r;
  }
}

void rangeAdd(Node*& t, ll l, ll r, ll v) {
  Node *a, *b, *c;
  tie(a, b) = split(t, l);
  tie(b, c) = split(b, r - l);
  applyAdd(b, v);
  t = merge(a, merge(b, c));
}

void rangeChMin(Node*& t, ll l, ll r, ll v) {
  Node *a, *b, *c;
  tie(a, b) = split(t, l);
  tie(b, c) = split(b, r - l);
  updChMin(b, v);
  t = merge(a, merge(b, c));
}

signed main() {
  ll n, q;
  cin >> n >> q;
  Node* t = nullptr;
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    t = (t ? merge(t, new Node(x)) : new Node(x));
  }

  while (q--) {
    ll opc, l, r, x;
    cin >> opc;
    if (opc == 1) {
      cin >> l >> r >> x;
      l--;
      rangeChMin(t, l, r, x);
    } else if (opc == 2) {
      cin >> l >> r;
      l--;
      Node *a, *b, *c;
      tie(a, b) = split(t, l);
      tie(b, c) = split(b, r - l);
      t = merge(a, merge(c, b));
    } else {
      cin >> l >> r >> x;
      l--;
      rangeAdd(t, l, r, x);
    }

    cout << t->sum << '\n';
  }
  return 0;
}