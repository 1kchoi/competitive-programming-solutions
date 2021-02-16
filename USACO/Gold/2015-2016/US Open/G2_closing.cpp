// USACO 2016 US Open Contest, Gold
// Problem 2. Closing the Farm
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
    vi e;
    void init(int n) { e.assign(n, -1); }
    int get(int x) { return (e[x] < 0) ? x : e[x] = get(e[x]); }
    bool sameSet(int x, int y) { return get(x) == get(y); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {
        x = get(x), y = get(y); if (x == y) return 0;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x; return 1;
    }
};

int N, M, A[NMAX];
bool added[NMAX], ans[NMAX];
vi G[NMAX];
DSU S;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO("closing");

    cin >> N >> M;
    S.init(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        --a; --b;
        G[a].PB(b); G[b].PB(a);
    }
    for (int i = 0; i < N; i++) {
        cin >> A[i]; --A[i];
    }
    for (int i = N - 1; i >= 0; i--) {
        int v = A[i];
        added[v] = 1;
        for (int j = 0; j < sz(G[v]); j++) {
            int u = G[v][j];
            if (added[u]) S.unite(v, u);
        }
        if (S.size(v) == N - i) ans[i] = 1;
    }

    for (int i = 0; i < N; i++) {
        if (ans[i]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}
