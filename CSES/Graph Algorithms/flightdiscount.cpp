// CSES Problem Set - Flight Discount
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF 0x3f3f3f
#define MOD (int)(1e9+7)
typedef pair<int,int> ii;
typedef pair<ii,ll> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<iii> viii;

int N, M;
ll parent[NMAX], dist[NMAX], ans, longestedge;
vii AL[NMAX]; // (neighbor, cost)
map<ii, ll> EL;
priority_queue< ii, vii, greater<ii> > Q; // (cost, (destination, parent))

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        ll a,b,c; cin >> a >> b >> c;
        AL[a].PB(ii(b,c));
        if (EL.find(ii(a,b)) != EL.end()) {
            EL[ii(a,b)] = min(EL[ii(a,b)], c);
        }
        else {
            EL[ii(a,b)] = c;
        }
    }

    memset(dist, INF, sizeof(dist));
    dist[1] = 0;
    Q.push(ii(0,1));

    while (!Q.empty()) {
        ii front = Q.top(); Q.pop();
        ll w = front.first, v = front.second;
        //cout << w << " " << v << endl;
        if (dist[v] < w) continue;
        for (int i = 0; i < sz(AL[v]); i++) {
            ll u = AL[v][i].first, cost = AL[v][i].second;
            if (dist[v] + cost < dist[u]) {
                dist[u] = dist[v] + cost;
                parent[u] = v;
                Q.push(ii(dist[u], u));
                //cout << "pushed: " << dist[u] << " " << u << endl;
            }
        }
    }

    int i = N;
    while (parent[i]) {
        //cout << i << " " << parent[i] << " " << EL[ii(parent[i], (ll)i)] << endl;
        longestedge = max(longestedge, EL[ii(parent[i], (ll)i)]);
        i = parent[i];
    }

    cout << dist[N]-longestedge+longestedge/2 << endl;

    return 0;
}
