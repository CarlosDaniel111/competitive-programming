#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
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

bool check(string num, int ant) {
  int t = SZ(num);
  FOR(i, 0, t) {
    if (num[i] - '0' < ant) {
      return false;
    }
    ant = num[i] - '0';
  }
  return true;
}

void solve() {
  int n;
  cin >> n;
  vector<string> a(n);
  FOR(i, 0, n) {
    cin >> a[i];
  }

  int ant = -1;
  FOR(i, 0, n) {
    if (ant >= 10) {
      int curr = stoi(a[i]);
      if (curr < ant) {
        cout << "NO" << ENDL;
        return;
      }
      ant = curr;
    }
    if (stoi(a[i]) <= 9) {
      if (a[i][0] - '0' < ant) {
        cout << "NO" << ENDL;
        return;
      } else {
        ant = a[i][0] - '0';
      }
      continue;
    }

    if (check(a[i], ant)) {
      ant = a[i][SZ(a[i]) - 1] - '0';
    } else {
      ant = stoi(a[i]);
    }
  }
  cout << "YES" << ENDL;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}