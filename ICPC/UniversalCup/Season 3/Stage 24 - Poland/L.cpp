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

constexpr ll MAX = 3e6 + 5;

struct Node {
  ll go[3], cnt[3];
  ll depth, nx;

  Node() {
    depth = nx = 0;
    FOR(i, 0, 3) go[i] = cnt[i] = 0;
  }
};

Node trie[MAX];

ll idx = 1;
ll newNode(ll depth) {
  trie[idx].depth = depth;
  trie[idx].nx = idx;
  return idx++;
}
ll go(ll u, ll x) {
  if (!trie[u].go[x]) trie[u].go[x] = newNode(trie[u].depth + 1);
  return trie[u].go[x];
}

vi Z(const vi& S) {
  vi z(SZ(S));
  ll l = -1, r = -1;
  FOR(i, 1, SZ(S)) {
    z[i] = i >= r ? 0 : min(r - i, z[i - l]);
    while (i + z[i] < SZ(S) && S[i + z[i]] == S[z[i]]) z[i]++;
    if (i + z[i] > r) l = i, r = i + z[i];
  }
  return z;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll n;
  cin >> n;
  vector<vi> a(n);
  ll root = newNode(0);
  FOR(i, 0, n) {
    string s;
    cin >> s;
    a[i].resize(SZ(s) * 2);
    ll m = SZ(s);
    FOR(j, 0, m * 2) {
      char c = s[j % m];
      if (c == 'P')
        a[i][j] = 0;
      else if (c == 'K')
        a[i][j] = 1;
      else
        a[i][j] = 2;
    }
    vi pos(m * 2 + 1);
    ll curr = root;
    FOR(j, 0, m * 2) {
      pos[j] = curr;
      curr = go(curr, a[i][j]);
    }
    pos[m * 2] = curr;
    vi z = Z(a[i]);
    FOR(j, 1, m * 2) {
      ll u = pos[j];
      ll val = z[j];
      ll v = pos[j + val];
      if (trie[trie[u].nx].depth < trie[v].depth) {
        trie[u].nx = v;
      }
    }
  }
  FOR(i, 0, n) {
    ll m = SZ(a[i]);
    ll curr = root;
    FOR(j, 0, m) { curr = go(curr, a[i][j]); }
    ll sig = trie[curr].nx;
    trie[sig].cnt[a[i][trie[sig].depth % m]]++;
  }

  ll ans = 0;

  auto dfs = [&](auto self, ll u) -> ll {
    ll res = 0;
    FOR(x, 0, 3) {
      if (!trie[u].go[x]) continue;
      trie[u].cnt[x] += self(self, trie[u].go[x]);
    }
    FOR(x, 0, 3) res += trie[u].cnt[x];
    ans += trie[u].cnt[0] * trie[u].cnt[1] * trie[u].cnt[2];
    return res;
  };

  dfs(dfs, root);

  cout << ans << ENDL;

  return 0;
}