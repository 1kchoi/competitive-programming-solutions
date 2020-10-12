// USACO 2020 January Contest, Gold
// Problem 1. Time is Mooney
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(1e3+3)
#define MMAX (int)(2e3+3)
#define INF 0x7f7f7f7f
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M, C, value[NMAX], A[MMAX], B[MMAX];
ll ans, dp[NMAX][1002];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

    cin >> N >> M >> C;
    for (int i = 1; i <= N; i++) {
        cin >> value[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
    }
    memset(dp, -1, sizeof(dp));
    dp[1][0] = 0;
    for (int t = 1; t < 1002; t++) {
        for (int i = 0; i < M; i++) {
            if (dp[A[i]][t-1] >= 0) {
                dp[B[i]][t] = max(dp[B[i]][t], dp[A[i]][t-1] + value[B[i]]);
            }
        }
        ans = max(ans, dp[1][t] - C*t*t);
    }

    cout << ans << endl;

    return 0;
}
