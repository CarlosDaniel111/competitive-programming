#include <bits/stdc++.h>
using namespace std;
// AC2++
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define fi first
#define se second
#define pb push_back
#define SZ(x) int((x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ROF(i, a, b) for (int i = (a)-1; i >= (b); --i)
#define ENDL '\n'

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

bool isPart[30];
string buena;

bool check(string s, string p) {
  FOR(i, 0, SZ(s)) {
    if (p[i] == 'X' && (s[i] == buena[i] || isPart[s[i] - 'a']))
      return false;
    if (p[i] == '*' && s[i] != buena[i])
      return false;
    if (p[i] == '!' && (s[i] == buena[i] || !isPart[s[i] - 'a']))
      return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> palabras(n);
  FOR(i, 0, n) {
    cin >> palabras[i];
  }
  buena = palabras[0];

  for (auto c : palabras[0]) {
    isPart[c - 'a'] = true;
  }

  int q;
  cin >> q;
  while (q--) {
    int ans = 0;
    string s;
    cin >> s;
    FOR(i, 0, n) {
      if (check(palabras[i], s)) {
        ans++;
      }
    }
    cout << ans << ENDL;
  }

  return 0;
}