#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i, a, b) \
  for (int i = (int)a; i < (int)b; i++) +

inline bool isOn(int x, int b) { return (x >> b) & 1; }

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  vector<int> msks;
  msks.push_back(1 + 2 + 4 + 16 + 32 + 64);
  msks.push_back(32 + 64);
  msks.push_back(2 + 4 + 8 + 16 + 32);
  msks.push_back(4 + 8 + 16 + 32 + 64);
  msks.push_back(1 + 8 + 32 + 64);
  msks.push_back(1 + 4 + 8 + 16 + 64);
  msks.push_back(1 + 2 + 4 + 8 + 16 + 64);
  msks.push_back(4 + 32 + 64);
  msks.push_back(1 + 2 + 4 + 8 + 16 + 32 + 64);
  msks.push_back(1 + 4 + 8 + 16 + 32 + 64);

  int n;
  cin >> n;

  while (n--) {
    string s;
    cin >> s;

    int fixed = 0, base = 0;
    for (int i = 0; i < 7; ++i) {
      if (s[i] == 'G') {
        base |= 1 << i;
      }
      if (s[i] == '+' || s[i] == '-') {
        fixed |= 1 << i;
      }
    }

    set<int> cand;
    for (int x = 0; x < 10; ++x) {
      int msk = msks[x];
      bool ok = true;
      for (int i = 0; i < 7; ++i) {
        if (!isOn(fixed, i) && isOn(msk, i) ^ isOn(base, i)) {
          ok = false;
          break;
        }
      }
      if (ok) {
        cand.insert(x);
      }
    }
    if (int(cand.size()) == 1) {
      cout << *cand.begin();
    } else {
      cout << "*";
    }
  }
  cout << '\n';

  return 0;
}