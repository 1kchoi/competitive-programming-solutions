// CSES Problem Set - Two Sets II
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

ll N, dp[NMAX][2 * NMAX * NMAX];

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N;
    if ((N * (N + 1) / 2) & 1) {
        cout << 0 << endl;
    }
    else {
        dp[0][0] = 1;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= i * (i + 1) / 2; j++) {
                dp[i][j] = dp[i - 1][j];
                if (i <= j) dp[i][j] += dp[i - 1][j - i];
                dp[i][j] %= MOD;
            }
        }
        cout << dp[N][N * (N + 1) / 4] << endl;
    }

    return 0;
}
