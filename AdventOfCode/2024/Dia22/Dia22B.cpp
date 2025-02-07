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

vector<string> split(string str, char pattern) {
  ll posInit = 0;
  ll posFound = 0;
  string splitted;
  vector<string> results;

  while (posFound >= 0) {
    posFound = str.find(pattern, posInit);
    splitted = str.substr(posInit, posFound - posInit);
    posInit = posFound + 1;
    results.push_back(splitted);
  }

  return results;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ifstream file(
      "/Users/CarlosBeltran/Documents/ICPC/competitive-programming/"
      "AdventofCode/2024/Dia22/input.txt");

  string line;
  ll ans = 0;
  vector<vector<pi>> a;
  while (getline(file, line)) {
    ll n = stoll(line);
    ll ant = n % 10;
    a.pb(vector<pi>());
    FOR(i, 0, 2000) {
      ll sig = 64 * n;
      sig = sig xor n;
      sig %= 16777216;
      n = sig;
      sig = n / 32;
      sig = sig xor n;
      sig %= 16777216;
      n = sig;
      sig = n * 2048;
      sig = sig xor n;
      sig %= 16777216;
      n = sig;
      // cout << n << " ";
      ll ultn = n % 10;
      a[SZ(a) - 1].pb({ultn, ultn - ant});
      ant = ultn;
    }
  }

  FOR(i, -9, 10) {
    FOR(j, -9, 10) {
      FOR(k, -9, 10) {
        FOR(l, -9, 10) {
          ll curr = 0;

          FOR(ii, 0, SZ(a)) {
            FOR(jj, 0, SZ(a[ii]) - 3) {
              if (a[ii][jj].second == i && a[ii][jj + 1].second == j &&
                  a[ii][jj + 2].second == k && a[ii][jj + 3].second == l) {
                curr += a[ii][jj + 3].first;
                break;
              }
            }
          }

          ans = max(ans, curr);
        }
      }
    }
  }
  cout << ans << ENDL;

  return 0;
}