// AtCoder Educational DP Contest E - Knapsack 2
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX 105
#define VMAX (int)(1e5+5)
#define INF 0x7f7f7f7f
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, W, weight[NMAX], value[NMAX], dp[NMAX][VMAX];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> value[i];
    }

    memset(dp, 0x3f3f3f, sizeof(dp));
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= (int)(1e5); j++) {
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if (j-value[i-1] >= 0) dp[i][j] = min(dp[i][j], dp[i-1][j-value[i-1]] + weight[i-1]);
        }
    }

    for (int i = (int)(1e5); i >= 0; i--) {
        if (dp[N][i] <= W) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
