#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

const int maxn = 2e5 + 10;
const int maxc = 27;
ll ans = 0, Ans[maxn];
int w, que[maxn], ql = 1, qr = 0;
struct ST {
  const static int inf = 1e8;
  int t[maxn][maxc], father[maxn], sons[maxn], start[maxn], len[maxn], link[maxn], now, rem, s[maxn], n, leaf, tot, pool[maxn];
  ST() : now(1), rem(0), n(0), leaf(0), tot(1) {
    for (int i = 1; i < maxn; ++i) pool[i] = i;
    father[1] = 0;
    len[0] = inf;
  }
  void erase(int &x) {
    memset(t[x], 0, sizeof t[x]), start[x] = len[x] = link[x] = father[x] = sons[x] = 0;
    pool[tot--] = x;
    x = 0;
  }
  int node(int star, int le) {
    int nw = pool[++tot];
    start[nw] = star, len[nw] = le, link[nw] = 1;
    return nw;
  }

  void add(int c) {
    s[++n] = c, ++rem;
    for (int last = 1; rem;) {
      while (rem > len[t[now][s[n - rem + 1]]]) rem -= len[now = t[now][s[n - rem + 1]]];
      int ed = s[n - rem + 1];
      int &v = t[now][ed];
      int x = s[start[v] + rem - 1];
      if (!v) {
        father[que[++qr] = v = node(n - rem + 1, inf)] = now;
        ++sons[now];
        link[last] = now;
        last = now;
      } else if (x == c) {
        link[last] = now;
        last = now;
        break;
      } else {
        int u = node(start[v], rem - 1);
        father[u] = father[v];
        father[que[++qr] = t[u][c] = node(n, inf)] = u;
        father[t[u][x] = v] = u, start[v] += rem - 1;
        if (len[v] < inf) len[v] -= rem - 1;
        sons[link[last] = v = u] = 2;
        last = v;
      }
      ++leaf;
      if (now == 1)
        --rem;
      else
        now = link[now];
    }
  }

  void compress(int x) {
    if (!father[x]) return;
    if (sons[x] && (--sons[x]) != 1) return;
    int i;
    for (i = 1; i < maxc; ++i)
      if (t[x][i]) break;
    int u = t[x][i];
    start[u] -= len[x];
    if (len[u] < inf) len[u] += len[x];
    father[u] = father[x];
    erase(t[father[x]][s[start[x]]]);
    t[father[u]][s[start[u]]] = u;
  }

  void del(int x) {
    int f = father[x];
    if (now == f) {
      if (!rem || t[now][s[n - rem + 1]] != x) {
        ans -= n - start[x] + 1;
        --leaf;
        erase(t[f][s[start[x]]]);
        if (now != 1) now = father[now], rem += len[f];
        compress(f);
        return;
      }
      ans -= n - rem - start[x] + 1;
      start[x] = n - rem + 1;
      que[++qr] = x;
      if (now == 1)
        --rem;
      else
        now = link[now];
    } else {
      ans -= n - start[x] + 1;
      erase(t[f][s[start[x]]]);
      compress(f);
      --leaf;
    }
  }

  void run() {
    for (int i = 1; i <= tot; ++i)
      if (pool[i] != 1)
        ans += min(len[pool[i]], n - start[pool[i]] + 1);
  }
} sut;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n, m;
  string s;
  cin >> s;
  n = SZ(s);
  cin >> m >> w;
  FOR(i, 0, w) {
    sut.add(s[i] - 'a' + 1);
  }
  sut.run();
  Ans[0] = ans;
  FOR(i, w, n) {
    if (ql <= qr) sut.del(que[ql++]);
    sut.add(s[i] - 'a' + 1);
    ans += sut.leaf;
    Ans[i - w + 1] = ans;
  }
  while (m--) {
    int a;
    cin >> a;
    cout << Ans[a - 1] << ENDL;
  }

  return 0;
}