// USACO 2020 December Contest, Silver
// Problem 1. Cowntagion
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
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, ans;
vi G[NMAX];

void dfs(int v, int parent) {
    int cows = 1;
    int children = sz(G[v]) - 1 + (v == 1);
    while (cows <= children) {
        cows *= 2;
        ans++;
    }
    ans += children;
    for (int c : G[v]) {
        if (c != parent) {
            dfs(c, v);
        }
    }
}
/*
void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}
//*/
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        G[a].PB(b); G[b].PB(a);
    }

    dfs(1, 0);
    cout << ans << endl;


    return 0;
}
