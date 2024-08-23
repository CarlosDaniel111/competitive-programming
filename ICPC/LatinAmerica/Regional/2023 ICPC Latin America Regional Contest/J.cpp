#include <bits/stdc++.h>
using namespace std;
// AC2#
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

vector<vector<int>> g;
vector<bool> is_removed;
vector<int> subtree_size;
vector<pi> min_dist;

vector<vector<pair<int, int>>> ancestro;

int get_subtree_size(int node, int parent = -1) {
  subtree_size[node] = 1;
  for (int child : g[node]) {
    if (child == parent || is_removed[child])
      continue;
    subtree_size[node] += get_subtree_size(child, node);
  }
  return subtree_size[node];
}

int get_centroid(int node, int tree_size, int parent = -1) {
  for (int child : g[node]) {
    if (child == parent || is_removed[child])
      continue;
    if (subtree_size[child] * 2 > tree_size)
      return get_centroid(child, tree_size, node);
  }
  return node;
}

void calc_dist(int node, int centroid, int parent = -1, int dist = 1) {
  ancestro[node].pb({centroid, dist});
  for (int child : g[node]) {
    if (child == parent || is_removed[child]) continue;
    calc_dist(child, centroid, node, dist + 1);
  }
}

void build_centroid_decomp(int node = 0) {
  int centroid = get_centroid(node, get_subtree_size(node));

  // do something

  is_removed[centroid] = true;

  for (int child : g[centroid]) {
    if (is_removed[child])
      continue;
    calc_dist(child, centroid, centroid);
    build_centroid_decomp(child);
  }
}

void update(int node) {
  for (auto &[ance, dist] : ancestro[node]) {
    if (ance >= node) continue;
    if (min_dist[ance].first >= dist) {
      min_dist[ance] = {dist, node};
    }
  }
  min_dist[node] = {0, node};
}

int query(int node) {
  int ans = min_dist[node].first;
  int ans2 = min_dist[node].second;
  for (auto &[ance, dist] : ancestro[node]) {
    if (dist == 0) continue;
    if (dist + min_dist[ance].first <= ans) {
      if (dist + min_dist[ance].first == ans) {
        ans2 = min(ans2, min_dist[ance].second);
      } else {
        ans2 = min_dist[ance].second;
      }
      ans = dist + min_dist[ance].first;
    }
  }
  return ans2;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);

  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << ENDL;
    return 0;
  }
  g.assign(n, vi());
  min_dist.assign(n, {0, 0});
  FOR(i, 0, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].pb(b);
    g[b].pb(a);
    min_dist[i] = {INF, i};
  }

  subtree_size.assign(n, 0);
  ancestro.assign(n, vector<pi>());
  is_removed.assign(n, false);

  build_centroid_decomp();

  vi ans;
  ans.pb(n - 1);

  ROF(i, n, 1) {
    update(i);
    ans.pb(query(i - 1));
  }

  reverse(ALL(ans));
  for (auto x : ans) {
    cout << x + 1 << " ";
  }

  return 0;
}