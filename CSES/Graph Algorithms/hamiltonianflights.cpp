// CSES Problem Set - Hamiltonian Flights
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 21
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M;
vi G[NMAX];
ll dp[1 << NMAX][NMAX];

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        --a; --b;
        G[a].PB(b);
    }
    dp[1][0] = 1;
    for (int mask = 1; mask < (1 << N); mask++) {
        if ((mask & (1 << (N - 1))) && mask != (1 << N) - 1) continue;
        for (int v = 0; v < N; v++) {
            if (!(mask & (1 << v))) continue;
            for (int u : G[v]) {
                if ((mask & (1 << u))) continue;
                int newmask = (mask | (1 << u));
                dp[newmask][u] += dp[mask][v];
                dp[newmask][u] %= MOD;
            }
        }
    }
    cout << dp[(1 << N) - 1][N - 1] % MOD << endl;

    return 0;
}
