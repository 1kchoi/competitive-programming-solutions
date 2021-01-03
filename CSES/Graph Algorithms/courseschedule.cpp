// CSES Problem Set - Course Schedule
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

int N, M, degree[NMAX];
vi G[NMAX], ans;
queue<int> Q;

/*
void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        G[a].PB(b);
        degree[b]++;
    }
    for (int i = 1; i <= N; i++) {
        if (!degree[i]) Q.push(i);
    }
    while (Q.size()) {
        int v = Q.front(); Q.pop();
        ans.PB(v);
        for (int u : G[v]) {
            if (!(--degree[u])) {
                Q.push(u);
            }
        }
    }

    if (sz(ans) < N) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        for (int x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
