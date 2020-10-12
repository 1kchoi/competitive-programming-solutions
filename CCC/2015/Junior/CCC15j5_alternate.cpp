// CCC '15 J5 - π-day
// iterative solution
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
#define NMAX 253
#define INF 0x3f3f3f
#define MOD (int)(1e9+7)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, K;
ll dp[NMAX][NMAX][NMAX], ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> K;

    for (int n = 1; n <= N; n++) {
        for (int k = 1; k <= n; k++) {
            if (k == 1) {
                dp[n][k][n] = 1;
            }
            else {
                for (int min = 1; min <= n; min++) {
                    for (int i = 1; i <= min; i++) {
                        dp[n][k][min] += dp[n-min][k-1][i];
                    }
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        ans += dp[N][K][i];
    }

    cout << ans << endl;

    return 0;
}
