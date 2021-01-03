// CCC '19 S5 - Triangle: The Data Structure
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(3e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int N, K, dp[20][NMAX][NMAX];
vector<int> kvalues;
ll ans;

int twothirds(int x) {
    if (x % 3 == 1) {
        return x * 2 / 3 + 1;
    }
    return x * 2 / 3;
}

int solve(int k, int i, int j) {
    if (dp[k][i][j] < 0) {
        int jump = kvalues[k] - kvalues[k - 1];
        int c1 = solve(k - 1, i, j);
        int c2 = solve(k - 1, i + jump, j);
        int c3 = solve(k - 1, i + jump, j + jump);
        dp[k][i][j] = max({c1, c2, c3});
    }
    return dp[k][i][j];
}

//*
void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}
//*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();
    memset(dp, -1, sizeof(dp));
    cin >> N >> K;

    int x = K;
    while (x > 1) {
        kvalues.PB(x);
        x = twothirds(x);
    }
    kvalues.PB(1);
    reverse(all(kvalues));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> dp[0][i][j];
        }
    }

    for (int i = 0; i <= N - K; i++) {
        for (int j = 0; j <= i; j++) {
            ans += solve(sz(kvalues) - 1, i, j);
        }
    }
    cout << ans << endl;

    return 0;
}
