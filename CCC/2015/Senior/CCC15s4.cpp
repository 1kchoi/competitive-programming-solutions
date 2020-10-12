// CCC '15 S4 - Convex Hull
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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef pair<int, ii> iii; // F , F.F , F.S
typedef vector<iii> viii;
typedef vector<viii> vviii;

int K, N, M, A, B, dist[2003][203], ans; // node, damage
vviii AL; // destination, time, damage
priority_queue<iii, viii, greater<iii> > Q; // time, (destination,damage)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> K >> N >> M;
    AL.assign(N+2, viii());
    for (int i = 0; i < M; i++) {
        int a, b, t, h;
        cin >> a >> b >> t >> h;
        AL[a].PB(iii(b,ii(t,h)));
        AL[b].PB(iii(a,ii(t,h)));
    }
    cin >> A >> B;
    Q.push(iii(0,ii(A,0)));

    memset(dist, INF, sizeof(dist));
    dist[A][0] = 0;
    cout << dist[A+1][0] << endl;

    while (!Q.empty()) {
        iii popped = Q.top(); Q.pop();
        int t = popped.first, u = popped.second.first, d = popped.second.second;
        if (t > dist[u][d]) continue;
        for (int i = 0; i < sz(AL[u]); i++) {
            int v = AL[u][i].first;
            int t2 = AL[u][i].second.first;
            int d2 = AL[u][i].second.second;
            if (d+d2 < K && dist[u][d] + t2 < dist[v][d+d2]) {
                dist[v][d+d2] = dist[u][d] + t2;
                Q.push(iii(dist[v][d+d2], ii(v,d+d2)));
            }
        }
    }

    ans = INF;
    for (int i = 0; i < 203; i++) {
        ans = min(ans, dist[B][i]);
    }
    if (ans == INF) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }

    return 0;
}
