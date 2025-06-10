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
  int idx;
  int s;
  bool rev;
  Node(int i, int val) : val(val), y(rand()), s(val), idx(i) {}
  void recalc();
};

int sum(Node* n) { return n ? n->s : 0ll; }
int cnt(Node* n) { return n ? n->c : 0; }
int getVal(Node* n) { return n ? n->val : 0; }
int getIdx(Node* n) { return n ? n->idx : 0; }
void Node::recalc() {
  c = cnt(l) + cnt(r) + 1;
  s = val + sum(l) + sum(r);
}

pair<Node*, Node*> split(Node* n, int k) {
  if (!n) return {};
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

int lower_bound(Node* t, ll x, int add = 0) {
  if (!t) return add;
  ll left_sum = sum(t->l);

  if (left_sum >= x) {
    return lower_bound(t->l, x, add);
  } else if (left_sum + t->val >= x) {
    return add + cnt(t->l);
  } else {
    return lower_bound(t->r, x - left_sum - t->val, add + cnt(t->l) + 1);
  }
}

void print(Node* t) {
  if (!t) return;
  print(t->l);
  FOR(i, 0, t->val) { cout << t->idx << " "; }
  print(t->r);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q, k;
  cin >> n >> k >> q;
  int ant;
  Node* t = nullptr;
  cin >> ant;
  int cnt1 = 1;
  FOR(i, 1, n) {
    int x;
    cin >> x;
    if (x == ant)
      cnt1++;
    else {
      t = (t ? merge(t, new Node(ant, cnt1)) : new Node(ant, cnt1));
      ant = x;
      cnt1 = 1;
    }
  }
  t = (t ? merge(t, new Node(ant, cnt1)) : new Node(ant, cnt1));
  while (q--) {
    int p, m;
    cin >> p >> m;
    int pos = lower_bound(t, p);
    Node *A, *B, *C, *sig;
    tie(A, B) = split(t, pos);
    tie(B, C) = split(B, 1);

    // Le sirve al siguiente
    if (sum(A) + sum(B) == p) {
      tie(sig, C) = split(C, 1);
      if (getIdx(sig) == m) {
        A = merge(A, B);
        C = merge(sig, C);
        tie(B, C) = split(C, 1);
      } else {
        C = merge(sig, C);
      }
    }

    if (getIdx(B) == m) {
      B = new Node(getIdx(B), getVal(B) + 1);
      if (getVal(B) >= k) {
        Node *ant, *sig;
        tie(A, ant) = split(A, cnt(A) - 1);
        tie(sig, C) = split(C, 1);
        while (ant && sig) {
          if (getIdx(ant) != getIdx(sig)) break;
          int s = getVal(ant) + getVal(sig);
          if (s < k) {
            ant = new Node(ant->idx, s);
            sig = nullptr;
            break;
          }
          tie(A, ant) = split(A, cnt(A) - 1);
          tie(sig, C) = split(C, 1);
        }
        t = merge(merge(merge(A, ant), sig), C);
      } else {
        t = merge(merge(A, B), C);
      }
      cout << sum(t) << ENDL;

      continue;
    }

    int usado = p - sum(A);
    if (sum(A) + sum(B) == p) {
      t = merge(merge(merge(A, B), new Node(m, 1)), C);
    } else {
      t = merge(
          merge(merge(merge(A, new Node(getIdx(B), usado)), new Node(m, 1)),
                new Node(getIdx(B), getVal(B) - usado)),
          C);
    }
    // print(t);
    // cout << ENDL;
    cout << sum(t) << ENDL;
  }

  return 0;
}