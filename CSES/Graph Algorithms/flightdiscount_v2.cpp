// CSES Problem Set - Flight Discount
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
#define INF 0x3f3f3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M;
ll d1[NMAX], d2[NMAX], ans = LONG_LONG_MAX;
//vii G1[NMAX], G2[NMAX];
vii G1[NMAX], G2[NMAX];

void djikstra(vii *G, ll *d, int start) {
    priority_queue<ii, vii, greater<ii>> Q;
    d[start] = 0;
    Q.push({0, start});
    while (Q.size()) {
        ii u = Q.top(); Q.pop();
        if (u[0] > d[u[1]]) continue;
        for (ii v : G[u[1]]) {
            if (d[v[0]] > d[u[1]] + v[1]) {
                d[v[0]] = d[u[1]] + v[1];
                Q.push({d[v[0]], v[0]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        ll a, b, c; cin >> a >> b >> c;
        G1[a].PB({b,c});
        G2[b].PB({a,c});
    }

    memset(d1, 0x3f, sizeof(d1));
    memset(d2, 0x3f, sizeof(d2));

    djikstra(G1, d1, 1);
    djikstra(G2, d2, N);

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < sz(G1[i]); j++) {
            ans = min(ans, d1[i] + d2[G1[i][j][0]] + G1[i][j][1]/2);
        }
    }
    cout << ans << endl;

    return 0;
}
