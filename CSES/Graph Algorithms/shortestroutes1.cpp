// CSES Problem Set - Shortest Routes I
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
typedef ar<ll, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int N, M;
ll dist[NMAX];
vvii AL;
priority_queue<ii, vii, greater<ii> > Q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("test_input.txt", "r", stdin);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> M;
    AL.assign(N+2, vii());
    for (int i = 0; i < M; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        AL[a].PB(ii(b,c));
    }

    for (int i = 1; i <= N; i++) {
        cout << i << ": ";
        for (int j = 0; j < sz(AL[i]); j++) {
            cout << AL[i][j].first << "," << AL[i][j].second << " ";
        }
        cout << endl;
    }

    memset(dist,INF,sizeof(dist));
    dist[1] = 0;
    Q.push(ii(0,1));

    while (!Q.empty()) {
        ii p = Q.top(); Q.pop();
        int d = p.first, u = p.second;
        if (d > dist[u]) continue;
        for (int i = 0; i < sz(AL[u]); i++) {
            int v = AL[u][i].first, w = AL[u][i].second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                Q.push(ii(dist[v], v));
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (i > 1) cout << " ";
        cout << dist[i];
    }
    cout << endl;

    return 0;
}
