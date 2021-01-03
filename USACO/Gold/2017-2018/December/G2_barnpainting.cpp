// USACO 2017 December Contest, Gold
// Problem 2. Barn Painting
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

int N, K, F[NMAX];
ll dp[NMAX][3];
vi G[NMAX];

ll solve(int node, int color, int parent) {
    if (dp[node][color] < 0) {
        if (F[node] >= 0 && color != F[node]) {
            dp[node][color] = 0;
        }
        else {
            dp[node][color] = 1;
            for (int child : G[node]) {
                if (child == parent) continue;
                ll s = 0;
                for (int d = 0; d < 3; d++) {
                    if (d == color) continue;
                    s += solve(child, d, node);
                    s %= MOD;
                }
                dp[node][color] *= s;
                dp[node][color] %= MOD;
            }
        }
    }
    return dp[node][color];
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO("barnpainting");

    memset(F, -1, sizeof(F));
    memset(dp, -1, sizeof(dp));
    cin >> N >> K;
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        G[a].PB(b);
        G[b].PB(a);
    }
    for (int i = 0; i < K; i++) {
        int a, x; cin >> a >> x;
        --x;
        F[a] = x;
    }

    ll ans = 0;
    for (int i = 0; i < 3; i++) {
        ans += solve(1, i, 0);
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
