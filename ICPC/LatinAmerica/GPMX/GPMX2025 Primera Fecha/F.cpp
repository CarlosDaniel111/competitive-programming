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

const int N = 1e5 + 5, B = 131;
const int SZ_BLOCK = 770;

int n, q, a[N];
deque<int> sorted_ids[SZ_BLOCK];
int add[SZ_BLOCK], par[N], rep[SZ_BLOCK][SZ_BLOCK], internal_id[N],
    value_by_id[SZ_BLOCK][SZ_BLOCK];

int get(int x) { return par[x] == x ? x : par[x] = get(par[x]); }

void join(int a, int b) {
  a = get(a);
  b = get(b);
  if (a == b) return;
  par[a] = b;
}

void build_block(int id) {
  add[id] = 0;
  int l = id * B;
  int r = min(n, l + B) - 1;
  sorted_ids[id].clear();

  FOR(i, l, r + 1) par[i] = i;
  vi values(a + l, a + r + 1);
  sort(ALL(values));
  values.erase(unique(ALL(values)), values.end());
  vi last(SZ(values), -1);
  FOR(i, 0, SZ(values)) {
    value_by_id[id][i] = values[i];
    sorted_ids[id].push_back(i);
  }
  FOR(i, l, r + 1) {
    int pos = lower_bound(ALL(values), a[i]) - values.begin();
    internal_id[i] = pos;
    if (last[pos] != -1) join(i, last[pos]);
    last[pos] = i;
    rep[id][pos] = get(i);
  }
}

void build() {
  for (int i = 0; i * B < n; i++) build_block(i);
}

int get_value(int id, int i) {
  return add[id] + value_by_id[id][internal_id[get(i)]];
}

int get_block_max(int id) {
  return value_by_id[id][sorted_ids[id].back()] + add[id];
}

int get_max() {
  int res = 0;
  for (int i = 0; i * B < n; i++) res = max(res, get_block_max(i));
  return res;
}

void rebuild_add(int id, int L, int R) {
  int l = id * B;
  int r = min(n, l + B) - 1;
  FOR(i, l, r + 1) {
    a[i] = get_value(id, i);
    if (L <= i && i <= R) a[i] += 1;
  }
  build_block(id);
}

void rebuild_reset(int id, int L, int R, int mx) {
  int l = id * B;
  int r = min(n, l + B) - 1;
  FOR(i, l, r + 1) {
    a[i] = get_value(id, i);
    if (L <= i && i <= R && a[i] == mx) a[i] = 0;
  }
  build_block(id);
}

void add_one(int l, int r) {
  if (l / B == r / B) {
    rebuild_add(l / B, l, r);
    return;
  }
  int R = l;
  while (R % B) R++;
  rebuild_add(l / B, l, R - 1);
  l = R;
  while (l + B - 1 <= r) {
    add[l / B] += 1;
    l += B;
  }
  if (l <= r) rebuild_add(l / B, l, r);
}

void set_max_to_zero(int id) {
  int mx_value_id = sorted_ids[id].back();
  int mx = add[id] + value_by_id[id][mx_value_id];
  sorted_ids[id].pop_back();
  if (SZ(sorted_ids[id])) {
    int mn_value_id = sorted_ids[id].front();
    int mn = add[id] + value_by_id[id][mn_value_id];
    if (mn == 0) {
      int mn_rep = rep[id][mn_value_id];
      int mx_rep = rep[id][mx_value_id];
      join(mn_rep, mx_rep);
      mn_rep = get(mn_rep);
      internal_id[mn_rep] = mn_value_id;
      rep[id][mn_value_id] = mn_rep;
      return;
    }
  }
  sorted_ids[id].push_front(mx_value_id);
  value_by_id[id][mx_value_id] = -add[id];
}

void reset_range(int l, int r, int mx) {
  if (l / B == r / B) {
    if (get_block_max(l / B) == mx) rebuild_reset(l / B, l, r, mx);
    return;
  }
  int R = l;
  while (R % B) R++;
  if (get_block_max(l / B) == mx) {
    rebuild_reset(l / B, l, R - 1, mx);
  }
  l = R;
  while (l + B - 1 <= r) {
    if (get_block_max(l / B) == mx) set_max_to_zero(l / B);
    l += B;
  }
  if (l <= r && get_block_max(l / B) == mx) rebuild_reset(l / B, l, r, mx);
}

int query(int l, int r) {
  int res = 0;
  while (l % B && l <= r) {
    res = max(res, get_value(l / B, l));
    l++;
  }
  while (l + B - 1 <= r) {
    res = max(res, get_block_max(l / B));
    l += B;
  }
  while (l <= r) {
    res = max(res, get_value(l / B, l));
    l++;
  }
  return res;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> q;
  FOR(i, 0, n) cin >> a[i];

  build();
  while (q--) {
    char op;
    int l, r;
    cin >> op >> l >> r;
    l--, r--;
    if (op == 'Q')
      cout << query(l, r) << ENDL;
    else if (op == 'A')
      add_one(l, r);
    else {
      int mx = get_max();
      if (mx) reset_range(l, r, mx);
    }
  }

  return 0;
}