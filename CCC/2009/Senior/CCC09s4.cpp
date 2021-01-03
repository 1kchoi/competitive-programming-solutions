// CCC '09 S4 - Shop and Ship
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 5010
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, T, K, P[NMAX], D, dist[NMAX], ans = INT_MAX;
vii G[NMAX];
set<ii> Q;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    setIO();

    cin >> N >> T;
    for (int i = 0; i < T; i++) {
        int a, b, c; cin >> a >> b >> c;
        G[a].PB({c, b});
        G[b].PB({c, a});
    }

    cin >> K;
    memset(P, INF, sizeof(P));
    for (int i = 0; i < K; i++) {
        int a, b; cin >> a >> b;
        P[a] = min(P[a], b);
    }

    cin >> D;
    memset(dist, INF, sizeof(dist));
    dist[D] = 0;
    Q.insert({0, D});
    while (Q.size()) {
        ii v = *Q.begin(); Q.erase(Q.begin());
        if (v[0] < dist[v[1]]) continue;
        for (int i = 0; i < sz(G[v[1]]); ++i) {
            ii u = G[v[1]][i];
            if (dist[u[1]] > dist[v[1]] + u[0]) {
                dist[u[1]] = dist[v[1]] + u[0];
                Q.insert({dist[u[1]], u[1]});
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        ans = min(ans, dist[i] + P[i]);
    }
    cout << ans << endl;

    return 0;
}
