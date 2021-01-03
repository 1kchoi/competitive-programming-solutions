// CCC '02 S4 - Bridge Crossing
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 110
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M, A[NMAX], dp[NMAX][2]; // {min value, parent subsolution}
string names[NMAX];

void printAns(int X, int parent) {
    if (X == -1) return;
    printAns(dp[X][1], X);
    for (int i = X; i < parent; i++) {
        if (i > X) cout << " ";
        cout << names[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        cin >> names[i] >> A[i];
    }

    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;
    dp[0][1] = -1;
    for (int i = 1; i <= N; i++) {
        int slowest = 0;
        for (int j = 1; j <= M && j <= i; j++) {
            slowest = max(slowest, A[i - j]);
            // dp[i] = min(dp[i], dp[i - j] + slowest);
            if (dp[i][0] > dp[i - j][0] + slowest) {
                dp[i][0] = dp[i - j][0] + slowest;
                dp[i][1] = i - j;
            }
        }
    }

    cout << "Total Time: " << dp[N][0] << endl;

    printAns(dp[N][1], N);

    return 0;
}
