// CSES Problem Set - Distinct Colors
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

int N, ans[NMAX];
vi G[NMAX];
set<int> S[NMAX];

void dfs(int node, int parent) {
    for (int v : G[node]) {
        if (v == parent) continue;
        dfs(v, node);
        if (sz(S[v]) > sz(S[node])) swap(S[v], S[node]);
        for (int c : S[v]) {
            S[node].insert(c);
        }
        S[v].clear();
    }
    ans[node] = sz(S[node]);
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //ßsetIO();

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int c; cin >> c;
        S[i].insert(c);
    }
    for (int i = 1; i < N; i++) {
        int a, b; cin >> a >> b;
        G[a].PB(b);
        G[b].PB(a);
    }
    dfs(1, 0);
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
