// DMOPC '17 Contest 5 P4 - Intersecting Arcs
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 505
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, K, dp[2][NMAX][NMAX], pf[2][NMAX][NMAX];

ll prefix(int i, int j, int l, int r) {
    if (l <= 0) {
        return pf[i][j][r];
    }
    return (pf[i][j][r] - pf[i][j][l - 1] + MOD) % MOD;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> K;

    dp[0][0][0] = pf[0][0][0] = 1;
    for (int i = 1; i <= N; i++) {
        int p = i % 2;
        memset(dp[p], 0, sizeof(dp[p]));
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= K; k++) {
                ll part1 = dp[1 - p][j][k];
                ll part2 = (j ? dp[1 - p][j - 1][k] : 0LL);
                ll part3 = prefix(1 - p, j + 1, k - j, k);
                dp[p][j][k] = part1 + part2 + part3;
                dp[p][j][k] += MOD;
                dp[p][j][k] %= MOD;
                //cout << i << " " << j << " " << k << ": " << dp[i][j][k] << endl;

                pf[p][j][k] = dp[p][j][k];
                if (k) pf[p][j][k] += pf[p][j][k - 1];
                pf[p][j][k] += MOD;
                pf[p][j][k] %= MOD;
            }
        }
    }
    cout << dp[N % 2][0][K] << endl;

    return 0;
}
