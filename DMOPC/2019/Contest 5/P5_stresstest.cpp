// DMOPC '19 Contest 5 P5 - Crazy Cyclic Coincidences
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 25
#define MMAX 25
#define VMAX (1e6+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int N, M, V, dist[NMAX];
vector<ar<int, 3>> G[NMAX];

void dfs(int v) {
    for (ii e : G[v]) {
        int u = e[0], d = e[1];
        if (dist[u] >= 0) {

        }
        else {
            
        }
    }
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> M >> V;
    if (V == 0) {
        cout << "yes" << endl;
        return 0;
    }

    if (M == N - 1) {
        cout << "no" << endl;
        return 0;
    }

    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        G[a].PB({b, c});
        G[b].PB({a, c});
    }

    memset(dist, -1, sizeof(dist));
    dist[1] = 0;


    return 0;
}
