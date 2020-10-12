// Codeforces 1288C. Two Arrays
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(1e3+5)
#define MOD (int)(1e9+7)
#define INF (INT_MAX/2)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M;
ll dp[15][NMAX];
ll ans;

void printDP() {
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cout << setw(15) << dp[i][j];
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        for (int j = 0; j <= N; j++) {
            if (i == 1 || j == 1) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i-1][j]%MOD + dp[i][j-1]%MOD;
            }
        }
    }

    //printDP();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N+1-i; j++) {
            ans += dp[M][i]*dp[M][j];
            ans %= MOD;
        }
    }
    cout << ans << endl;

    return 0;
}
