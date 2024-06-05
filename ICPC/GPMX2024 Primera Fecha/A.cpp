#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

int n;
vi a;
set<int> nums;
multiset<int> res;
int cnt[1000005];
int iguales = 0;

void add(int idx, int end) {
  cnt[a[idx]]++;
  if (cnt[a[idx]] == 2) iguales++;
  if (cnt[a[idx]] >= 2) {
    return;
  }
  auto it = nums.lower_bound(a[idx]);
  if (it != nums.end()) {
    int sig = *it;
    res.insert(abs(sig - a[idx]));
  }
  if (it != nums.begin()) {
    int ant = *(--it);
    res.insert(abs(ant - a[idx]));
  }
}
void del(int idx, int end) {
  cnt[a[idx]]--;
  if (cnt[a[idx]] == 1) iguales--;
  if (cnt[a[idx]] == 0) {
    int sig = -1, ant = -1;
    auto it = nums.lower_bound(a[idx]);
    if (it != nums.end()) {
      sig = *it;
      res.erase(res.find(abs(sig - a[idx])));
    }
    if (it != nums.begin()) {
      ant = *(--it);
      res.erase(res.find(abs(ant - a[idx])));
    }

    if (ant != -1 && sig != -1) {
      res.insert(abs(ant - sig));
    }
  }
}
int calc() {
  if (iguales)
    return 0;
  else
    return *res.begin();
}

vi mosAlgo(vector<pi> Q) {
  int L = 0, R = 0, blk = 350;  // IMPORTANT!! blk ~= N/sqrt(Q)
  vi s(SZ(Q)), res = s;
#define K(x) pi(x.first / blk, x.second ^ -(x.first / blk & 1))
  iota(ALL(s), 0);
  sort(ALL(s), [&](int s, int t) { return K(Q[s]) < K(Q[t]); });
  for (int qi : s) {
    pi q = Q[qi];
    while (L > q.first) add(--L, 0);
    while (R < q.second) add(R++, 1);
    while (L < q.first) del(L++, 0);
    while (R > q.second) del(--R, 1);
    res[qi] = calc();
  }
  return res;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  cin >> n;
  a.resize(n);
  FOR(i, 0, n) { cin >> a[i]; }
  int q;
  cin >> q;
  vector<pi> Q(q);
  FOR(i, 0, q) {
    cin >> Q[i].first >> Q[i].second;
    Q[i].first--;
  }
  vi ans = mosAlgo(Q);
  for (int i = 0; i < q; i++) {
    cout << ans[i] << ENDL;
  }

  return 0;
}