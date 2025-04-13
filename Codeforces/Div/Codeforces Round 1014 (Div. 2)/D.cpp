#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

// ILT
void solve() {
  vector<string> conv;
  conv.pb("I");
  conv.pb("L");
  conv.pb("T");
  int n;
  cin >> n;
  string s;
  cin >> s;
  vi ans;
  while (SZ(ans) <= n * 2) {
    int cntT = 0, cntL = 0, cntI = 0;
    vi gen(3, -1);
    FOR(i, 0, SZ(s)) {
      cntT += (s[i] == 'T');
      cntL += (s[i] == 'L');
      cntI += (s[i] == 'I');
      if (i < SZ(s) - 1) {
        char c1 = s[i];
        char c2 = s[i + 1];
        if (c1 > c2) swap(c1, c2);
        if (c1 == 'I' && c2 == 'L') gen[2] = i;
        if (c1 == 'I' && c2 == 'T') gen[1] = i;
        if (c1 == 'L' && c2 == 'T') gen[0] = i;
      }
    }
    if (cntT == cntL && cntT == cntI) {
      cout << SZ(ans) << ENDL;
      for (auto x : ans) {
        cout << x << ENDL;
      }
      return;
    }
    vector<pair<int, int>> aux;
    aux.pb({cntT, 2});
    aux.pb({cntI, 0});
    aux.pb({cntL, 1});
    sort(ALL(aux));
    if (aux[2].first == SZ(s)) {
      cout << -1 << ENDL;
      return;
    }
    if (aux[1].first == aux[2].first) {
      if (aux[1].second == 0 && aux[2].second == 1) {
        if (gen[2] != -1) {
          s.insert(gen[2] + 1, "T");
          ans.pb(gen[2] + 1);
        } else {
          if (gen[0] != -1) {
            s.insert(gen[1] + 1, "L");
            ans.pb(gen[1] + 1);
          } else {
            s.insert(gen[0] + 1, "I");
            ans.pb(gen[0] + 1);
          }
        }
      }

      if (aux[1].second == 0 && aux[2].second == 2) {
        if (gen[1] != -1) {
          s.insert(gen[1] + 1, "L");
          ans.pb(gen[1] + 1);
        } else {
          if (gen[0] != -1) {
            s.insert(gen[0] + 1, "I");
            ans.pb(gen[0] + 1);
          } else {
            s.insert(gen[2] + 1, "T");
            ans.pb(gen[2] + 1);
          }
        }
      }

      if (aux[1].second == 1 && aux[2].second == 2) {
        if (gen[0] != -1) {
          s.insert(gen[0] + 1, "I");
          ans.pb(gen[0] + 1);
        } else {
          if (gen[1] != -1) {
            s.insert(gen[1] + 1, "L");
            ans.pb(gen[1] + 1);
          } else {
            s.insert(gen[2] + 1, "T");
            ans.pb(gen[2] + 1);
          }
        }
      }
      // ans++;
      // cout << s << ENDL;
      continue;
    }

    if (gen[aux[1].second] != -1) {
      s.insert(gen[aux[1].second] + 1, conv[aux[1].second]);
      ans.pb(gen[aux[1].second] + 1);
    } else if (gen[aux[0].second] != -1) {
      ans.pb(gen[aux[0].second] + 1);
      s.insert(gen[aux[0].second] + 1, conv[aux[0].second]);
    }
  }
  cout << -1 << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t = 1;
  cin >> t;
  while (t--) solve();

  return 0;
}