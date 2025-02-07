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

ll cntPar[2], cntImpar[2];

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string s;
  cin >> s;
  ll ansImpar = SZ(s), ansPar = 0;
  FOR(i, 0, SZ(s)) {
    int c = s[i] - 'a';
    if (i & 1) {
      ansImpar += cntImpar[c];
      ansPar += cntPar[c];
      cntImpar[c]++;
    } else {
      ansImpar += cntPar[c];
      ansPar += cntImpar[c];
      cntPar[c]++;
    }
  }
  cout << ansPar << " " << ansImpar << ENDL;

  return 0;
}