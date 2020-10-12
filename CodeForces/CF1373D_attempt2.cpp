// Codeforces 1373D - Maximum Sum on Even Positions (attempt 2)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(2e5+5)
#define INF (INT_MAX/2)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vll;

int T, N, A[NMAX];
//ll dp[4][NMAX];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> T;
    while (T--) {
        //memset(dp,0,sizeof(dp));
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        vll dp(3, vl(N+2));
        for (int i = 0; i < N; ++i) {
            dp[0][i+1] = dp[0][i] + (i&1?0:A[i]);
            if (i+1 < N) {
                dp[1][i+2] = max(dp[0][i],dp[1][i]) + (i&1?A[i]:A[i+1]);
            }
            dp[2][i+1] = max({dp[0][i],dp[1][i],dp[2][i]}) + (i&1?0:A[i]);
        }
        cout << max({dp[0][N],dp[1][N],dp[2][N]}) << endl;
    }

    return 0;
}
