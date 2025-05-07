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

ll mpSize[5005];
double mpDist[5005][5005];
bool alive[5005];

struct Node{
    double dist;
    ll u,v;

    bool operator<(const Node &o) const {
        if(dist == o.dist){
            if(u == o.u) return v<o.v;
            return u<o.u;
        }
        return dist<o.dist;
    }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  memset(alive,1,sizeof(alive));

  ll n;
  cin >> n;
  vector<pi> a(n);
  FOR(i,0,n) cin >> a[i].first >> a[i].second;

  set<Node> st;

  for (ll i = 0; i < n; i++) {
    mpSize[i] = 1;
    for (ll j = i + 1; j < n; j++) {
        double dist = (ll)(a[i].first - a[j].first) * (a[i].first - a[j].first);
        dist += (ll)(a[i].second - a[j].second) * (a[i].second - a[j].second);
        mpDist[i][j] = mpDist[j][i] = dist;
        st.insert((Node){dist,i,j});
    }
}

ll cntAlive = n;
ll id = n-1;
while (cntAlive > 1) {
    auto itmn = st.begin();
    ll idA = itmn->u;
    ll idB = itmn->v;
    st.erase(itmn);
    if (!alive[idA] || !alive[idB]) {
        continue;
    }
    ll idC = ++id;
    mpSize[idC] = mpSize[idA] + mpSize[idB];
    alive[idA] = alive[idB] = 0;
    cout << mpSize[idC] << '\n';
    for (ll idX = 0; idX < id; ++idX) {
        if (!alive[idX]) {
            continue;
        }
        double distCX = mpDist[idA][idX] + mpDist[idB][idX];
        mpDist[idC][idX] = mpDist[idX][idC] = distCX;
        st.insert((Node){distCX/(mpSize[idX]*mpSize[idC]),idX,idC});
    };
    
    cntAlive--;
}


  return 0;
}