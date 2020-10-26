// Codeforces 837A - Round Subset
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 205
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, K, p2[NMAX], p5[NMAX], dp[NMAX][NMAX][100], ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    memset(dp, -INF, sizeof(dp));
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        ll a; cin >> a;
        while (a % 2 == 0) {
            a /= 2;
            ++p2[i];
        }
        while (a % 5 == 0) {
            a /= 5;
            ++p5[i];
        }
    }

    dp[0][0][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K && j <= i; j++) {
            for (int f = p5[i - 1]; f < 30; f++) {
                //if (!j) {
                //    dp[i][j][f] = 0;
                //}
                //else
                dp[i][j][f] = max(dp[i - 1][j][f], dp[i - 1][j - 1][f - p5[i - 1]] + p2[i - 1]);
            }
        }
    }

    for (ll i = 0; i < 30; i++) {
        ans = max(ans, min(i, dp[N][K][i]));
    }

    cout << ans << endl;



    return 0;
}
