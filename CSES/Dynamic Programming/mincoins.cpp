// CSES - Minimizing Coins
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX 105
#define XMAX (int)(1e6+5)
#define INF (INT_MAX/2)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int n, x, a[NMAX], dp[XMAX];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= x; i++) {
        int best = INF;
        for (int j = 0; j < n; j++) {
            if (i-a[j] >= 0) {
                best = min(best, dp[i-a[j]]+1);
            }
        }
        dp[i] = best;
    }
    cout << (dp[x] == INF ? -1 : dp[x]) << endl;

    return 0;
}
