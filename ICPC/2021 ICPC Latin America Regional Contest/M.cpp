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

struct Work {
  int d, t, id;
};

bool cmp(Work &a, Work &b) { return tie(a.d, a.id) < tie(b.d, b.id); }

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<Work> trabajos(n);
  FOR(i, 0, n) {
    cin >> trabajos[i].t >> trabajos[i].d;
    trabajos[i].id = i;
  }
  sort(ALL(trabajos), cmp);

  ll curr = 0;
  FOR(i, 0, n) {
    curr += trabajos[i].t;
    if (curr > trabajos[i].d) {
      cout << "*" << ENDL;
      return 0;
    }
  }

  curr = 0;
  while (SZ(trabajos)) {
    int mnid = -1;
    ll mnsobra = 1e9 + 5;
    ll tmp = curr;
    FOR(i, 0, SZ(trabajos)) {
      if (mnsobra >= trabajos[i].t &&
          (mnid == -1 || trabajos[i].id < trabajos[mnid].id))
        mnid = i;
      tmp += trabajos[i].t;
      mnsobra = min(mnsobra, trabajos[i].d - tmp);
    }
    curr += trabajos[mnid].t;
    cout << trabajos[mnid].id + 1 << " ";
    trabajos.erase(trabajos.begin() + mnid);
  }

  return 0;
}