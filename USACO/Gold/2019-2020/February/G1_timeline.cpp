// USACO 2020 February Contest, Gold
// Problem 1. Timeline
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, M, C, S[NMAX], dist[NMAX];
vii G[NMAX];
bool beginning[NMAX];
priority_queue<ii> Q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("timeline.out", "w", stdout);

    memset(beginning, 1, sizeof(beginning));
    memset(dist, -INF, sizeof(dist));

    cin >> N >> M >> C;
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < C; i++) {
        ll a, b, c; cin >> a >> b >> c;
        G[a].PB({c, b});
        beginning[b] = 0;
    }
    for (int i = 1; i <= N; i++) {
        if (beginning[i]) {
            G[0].PB({S[i], i});
        }
    }

    dist[0] = 0;
    Q.push({0,0}); // distance, node
    while (Q.size()) {
        ii u = Q.top(); Q.pop();
        if (dist[u[1]] < u[0]) continue;
        for (int i = 0; i < sz(G[u[1]]); i++) {
            ii v = G[u[1]][i];
            if (dist[v[1]] < dist[u[1]] + v[0]) {
                dist[v[1]] = dist[u[1]] + v[0];
                Q.push({dist[v[1]], v[1]});
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << max(dist[i], S[i]) << endl;
        //dist[i] = max(dist[i], S[i]);
    }

    return 0;
}
