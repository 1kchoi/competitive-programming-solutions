// USACO 2018 February Contest, Gold
// Problem 3. Taming the Herd
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 105
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, A[NMAX], dp[NMAX][NMAX][NMAX], infinity;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO("taming");

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        A[i] -= i;
        A[i] *= -1;
    }

    memset(dp, INF, sizeof(dp));
    infinity = dp[0][0][0];
    dp[0][1][0] = (A[0] != 0);

    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= i + 1; ++j) {
            int x = infinity;
            for (int k = 0; k <= i; ++k) {
                dp[i][j][k] = min(dp[i][j][k],
                                  dp[i - 1][j][k] + (A[i] != k)); // continue streak
                x = min(x, dp[i - 1][j - 1][k]);
                /*
                if (i == k) {
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][k] + (A[i] != k));
                }
                */
                /*
                if (dp[i][j][k] == infinity) {
                    cout << i << " " << j << " " << k << endl;
                }
                */
            }
            dp[i][j][i] = min(dp[i][j][i], x + (A[i] != i));
            /*
            if (dp[i][j][i] == infinity) {
                cout << i << " " << j << " " << i << endl;
            }
            */
        }
    }

    for (int i = 1; i <= N; ++i) {
        int ans = INT_MAX;
        for (int j = 0; j < N; ++j) {
            ans = min(ans, dp[N - 1][i][j]);
        }
        cout << ans << endl;
    }

    return 0;
}
