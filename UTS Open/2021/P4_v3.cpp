// UTS Open '21 P4 - Lucky Graph
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(2e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

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


int N, M, ans, EL[NMAX][2], degree[NMAX], subtreesize[NMAX];
vii G[NMAX];
bool discovered[NMAX], removing[NMAX], inST[NMAX];
DSU S;
queue<int> Q;

int dfs(int node, int parent) {
    int s = 1;
    for (ii e : G[node]) {
        int u = e[0], id = e[1];
        if (u == parent) continue;
        if (!inST[id]) continue;
        s += dfs(u, node);
    }
    subtreesize[node] = s;
    return s;
}

void pruneOdd(int node, int parent) {
    if (subtreesize[node] == 1) {
        inST[G[node][0][1]] = false;
        return;
    }
    for (ii e : G[node]) {
        if (e[0] == parent) continue;
        pruneOdd(e[0], node);
        subtreesize[node]--;
        break;
    }
}

void process(int node, int parent) {
    for (ii e : G[node]) {
        int child = e[0], id = e[1];
        if (!inST[id]) continue;
        if (child == parent) continue;
        if (subtreesize[child] % 2 == 0) {
            inST[id] = false;
        }
        process(child, node);
    }
}

void check(int node) {
    Q.push(node);
    while (sz(Q)) {
        int v = Q.front(); Q.pop();
        discovered[v] = true;
        for (ii e : G[v]) {
            int u = e[0], id = e[1];
            if (discovered[u]) continue;
            if (S.unite(v, u)) {
                inST[id] = true;
                Q.push(u);
            }
        }
    }


    dfs(node, -1);
    ans += subtreesize[node];
    if (subtreesize[node] % 2 == 1) {
        ans--;
        if (subtreesize[node] != 1) pruneOdd(node, -1);
    }
    process(node, -1);

}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> M;
    S.init(N + 1);
    for (int i = 0; i < M; i++) {
        int v, u; cin >> v >> u;
        G[v].PB({u, i});
        G[u].PB({v, i});
        EL[i][0] = v;
        EL[i][1] = u;
        degree[v]++; degree[u]++;
    }
    for (int i = 1; i <= N; i++) {
        if (!discovered[i]) {
            check(i);
        }
    }

    cout << ans << endl;
    int removescore = 0;
    for (int i = 0; i < M; i++) {
        if (!inST[i]) removescore++;
    }
    cout << removescore << endl;
    for (int i = 0; i < M; i++) {
        if (!inST[i]) cout << i + 1 << " ";
    }
    cout << endl;

    return 0;
}
