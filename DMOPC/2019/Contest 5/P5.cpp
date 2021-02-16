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

struct DSU {
    vi e; void init(int N) { e = vi(N, -1); }
    int get(int x) { return (e[x] < 0) ? x : e[x] = get(e[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {
        x = get(x), y = get(y); if (x == y) return 0;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x; return 1;
    }
};

int N, M, V, dist[NMAX];
bool dp[2][1 << 21], edgeprocessed[MMAX];
vector<ar<int, 3>> G[NMAX];
DSU S;
queue<int> Q;
vi basis;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        G[a].PB({b, c, i});
        G[b].PB({a, c, i});
    }

    S.init(N + 1);
    Q.push(1);
    while (sz(Q)) {
        int v = Q.front(); Q.pop();
        //cout << "now at " << v << endl;
        for (ar<int, 3> e : G[v]) {
            int u = e[0], d = e[1], id = e[2];
            if (edgeprocessed[id]) continue;
            if (S.unite(u, v)) {
                dist[u] = dist[v] ^ d;
                Q.push(u);
            }
            else {
                basis.PB(dist[u] ^ dist[v] ^ d);
                //cout << "pushed into basis " << id + 2 << " " << (dist[u] ^ dist[v] ^ d) << endl;
            }
            edgeprocessed[id] = true;
        }
    }
    assert(sz(basis) == M - N + 1 || sz(basis) == 0);

    dp[0][0] = true;
    for (int i = 0; i < sz(basis); i++) {
        //cout << basis[i] << endl;
        int p = i % 2;
        int x = basis[i];
        memset(dp[1 - p], 0, sizeof(dp[1 - p]));
        for (int j = 0; j < (1 << 21); j++) {
            if (dp[p][j]) {
                dp[1 - p][j ^ x] = true;
            }
        }
    }

    if (dp[sz(basis) % 2][V]) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }


    return 0;
}
