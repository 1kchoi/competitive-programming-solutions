// CSES Problem Set - Flight Routes
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
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M, K;
vii G[NMAX];
priority_queue<ll> dist[NMAX];
priority_queue<ii, vii, greater<ii>> Q;
vi ans;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        ll a, b, c; cin >> a >> b >> c;
        G[a].PB({c, b});
    }
    dist[1].push(0);
    Q.push({0, 1});
    while(Q.size()) {
        ii v = Q.top(); Q.pop();
        if (v[0] > dist[v[1]].top()) continue;
        //cout << "now at object " << v[0] << " " << v[1] << endl;
        for (int i = 0; i < sz(G[v[1]]); i++) {
            ii u = G[v[1]][i];
            ll d = v[0] + u[0];
            if (sz(dist[u[1]]) < K) {
                dist[u[1]].push(d);
                Q.push({d, u[1]});
            }
            else if (d < dist[u[1]].top()) {
                dist[u[1]].pop();
                dist[u[1]].push(d);
                Q.push({d, u[1]});
            }
        }
    }

    for (int i = 0; i < K; i++) {
        ans.PB(dist[N].top());
        dist[N].pop();
    }
    reverse(all(ans));
    for (ll x : ans) {
        cout << x << " ";
    }
    cout << endl;


    return 0;
}
