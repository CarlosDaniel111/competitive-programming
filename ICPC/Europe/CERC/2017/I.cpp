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

int n, q;
vi a, id, pos;
vector<pi> queries, ans;

void check(int l, int r, vector<pi> &inter, bool isLeft) {
  int mid = (l + r) / 2;
  int mn = min(a[mid], a[mid + 1]), mx = max(a[mid], a[mid + 1]);
  int posL = mid, posR = mid + 1;
  int currMn = mn, currMx = mn;
  while (true) {
    if (posL < l or posR > r or mx - mn > r - l) break;
    if (mx - mn == posR - posL) {
      inter.pb({posL, posR});
      if (isLeft) {
        posL--;
        if (posL >= l) {
          mn = min(mn, a[posL]);
          mx = max(mx, a[posL]);
        }
      } else {
        posR++;
        if (posR <= r) {
          mn = min(mn, a[posR]);
          mx = max(mx, a[posR]);
        }
      }
    }
    int sigPosL = posL, sigPosR = posR;
    for (; currMn >= mn; currMn--) {
      sigPosL = min(sigPosL, pos[currMn]);
      sigPosR = max(sigPosR, pos[currMn]);
    }
    for (; currMx <= mx; currMx++) {
      sigPosL = min(sigPosL, pos[currMx]);
      sigPosR = max(sigPosR, pos[currMx]);
    }
    currMn++, currMx--;

    if (sigPosL < l or sigPosR > r) break;
    for (; posL >= sigPosL; posL--) {
      mn = min(mn, a[posL]);
      mx = max(mx, a[posL]);
    }
    for (; posR <= sigPosR; posR++) {
      mn = min(mn, a[posR]);
      mx = max(mx, a[posR]);
    }
    posL++, posR--;
  }
}

void improveViaMid(int l, int r, vi &id) {
  vector<pi> interLeft, interRight;

  check(l, r, interLeft, true);
  check(l, r, interRight, false);

  for (auto i : id) {
    pi currAns = {0, n - 1};
    int qL = queries[i].first, qR = queries[i].second;

    int lo = 0, hi = SZ(interLeft) - 1;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (interLeft[mid].first <= qL)
        hi = mid - 1;
      else
        lo = mid + 1;
    }
    if (lo < SZ(interLeft)) currAns = interLeft[lo];

    lo = 0, hi = SZ(interRight) - 1;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (interRight[mid].second >= qR)
        hi = mid - 1;
      else
        lo = mid + 1;
    }
    if (lo < SZ(interRight))
      currAns = {min(currAns.first, interRight[lo].first),
                 max(currAns.second, interRight[lo].second)};

    if (currAns.first <= qL && currAns.second >= qR &&
        currAns.second - currAns.first < ans[i].second - ans[i].first)
      ans[i] = currAns;
  }
}

void improve(int l, int r, vi &id) {
  if (SZ(id) == 0) return;
  if (l == r) {
    for (auto i : id) ans[i] = {l, l};
    return;
  }
  int m = (l + r) / 2;
  vi idL, idR;
  for (auto i : id) {
    if (queries[i].second <= m) idL.pb(i);
    if (queries[i].first > m) idR.pb(i);
  }
  improve(l, m, idL);
  improve(m + 1, r, idR);

  improveViaMid(l, r, id);
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;
  a.resize(n), pos.resize(n + 1);
  FOR(i, 0, n) cin >> a[i];
  FOR(i, 0, n) pos[a[i]] = i;
  cin >> q;
  queries.resize(q);
  FOR(i, 0, q) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    queries[i] = {l, r};
  }
  id.resize(q), ans.assign(q, {0, n - 1});
  iota(ALL(id), 0);

  improve(0, n - 1, id);

  for (auto [x, y] : ans) {
    cout << x + 1 << " " << y + 1 << ENDL;
  }

  return 0;
}