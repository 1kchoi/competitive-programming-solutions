// CSES Problem Set - Investigation
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, M, dist[NMAX], ways[NMAX], minpath[NMAX], maxpath[NMAX];
vii G[NMAX];
priority_queue<ii, vii, greater<ii>> Q;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        G[a].PB({c, b});
    }

    memset(dist, INF, sizeof(dist));
    dist[1] = 0;
    ways[1] = 1;
    Q.push({0, 1});
    while (Q.size()) { // u --> v
        ii u = Q.top(); Q.pop();
        if (u[0] > dist[u[1]]) continue;
        for (int i = 0; i < sz(G[u[1]]); i++) {
            ii v = G[u[1]][i];
            if (dist[v[1]] > dist[u[1]] + v[0]) {
                dist[v[1]] = dist[u[1]] + v[0];
                ways[v[1]] = 0;
                minpath[v[1]] = LLONG_MAX;
                maxpath[v[1]] = 0;
                Q.push({dist[v[1]], v[1]});
            }
            if (dist[v[1]] == dist[u[1]] + v[0]) {
                ways[v[1]] += ways[u[1]];
                ways[v[1]] %= MOD;
                minpath[v[1]] = min(minpath[v[1]], minpath[u[1]] + 1);
                maxpath[v[1]] = max(maxpath[v[1]], maxpath[u[1]] + 1);
            }
        }
    }

    cout << dist[N] << " " <<
            ways[N] << " " <<
            minpath[N] << " " <<
            maxpath[N] << endl;

    return 0;
}
