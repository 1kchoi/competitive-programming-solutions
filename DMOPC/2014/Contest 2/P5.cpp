// DMOPC '14 Contest 2 P5 - Sawmill Scheme
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e6+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M, indegree[NMAX];
vi G[NMAX];
ll ans[NMAX], sum;
queue<int> Q;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        G[a].PB(b);
        indegree[b]++;
    }
    ans[1] = 1e15;
    for (int v = 1; v <= N; v++) {
        for (int u : G[v]) {
            ans[u] += ans[v] / sz(G[v]);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (sz(G[i]) == 0) {
            double x = ans[i] / (1e15);
            cout << fixed << setprecision(12) << x << endl;
            sum += ans[i];
        }
    }

    cout << sum << endl;

    //assert(sum == 1e12);

    return 0;
}
