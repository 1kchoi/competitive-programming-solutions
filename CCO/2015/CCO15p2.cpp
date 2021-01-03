// CCO '15 P2 - Artskjid
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 19
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, M;
vii G[NMAX];
ll dp[NMAX][(1 << NMAX)];

ll solve(ll pos, ll mask) {
    if (dp[pos][mask] < 0) {
        if (pos == N - 1 && (mask & (1 << (N - 1)))) {
            dp[pos][mask] = 0;
        }
        else {
            for (ii nextpos : G[pos]) {
                if (mask & (1 << nextpos[0])) continue;
                dp[pos][mask] = max(dp[pos][mask], solve(nextpos[0], (mask | (1 << nextpos[0]))) + nextpos[1]);
            }
        }
    }
    return dp[pos][mask];
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    memset(dp, -INF, sizeof(dp));
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        G[a].PB({b, c});
    }
    cout << solve(0, 1) << endl;


    return 0;
}
