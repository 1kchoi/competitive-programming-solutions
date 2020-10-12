// CSES Problem Set - Shortest Routes I
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
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, M, ans, dist[NMAX];
vii G[NMAX];
priority_queue<ii, vii, greater<ii>> Q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        ll a, b, c; cin >> a >> b >> c; --a; --b;
        G[a].PB({c, b});
    }

    memset(dist, 0x3f, sizeof(dist));
    dist[0] = 0;
    Q.push({0, 0});

    while (Q.size()) {
        ii u = Q.top(); Q.pop();
        if (u[0] > dist[u[1]]) continue;
        for (ii v : G[u[1]]) {
            if (dist[v[1]] > dist[u[1]] + v[0]) {
                dist[v[1]] = dist[u[1]] + v[0];
                Q.push({dist[v[1]], v[1]});
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
