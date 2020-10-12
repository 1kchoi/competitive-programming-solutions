// USACO 2015 December Contest, Gold
// Problem 2. Fruit Feast
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(5e6+7)
#define INF (INT_MAX/2)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, A, B;
bool dp[NMAX][3];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);

    cin >> N >> A >> B;
    dp[0][0] = dp[0][1] = true;
    for (int i = 0; i <= N; i++) {
        if ((i >= A && dp[i-A][0]) || (i >= B && dp[i-B][0])) {
            dp[i][0] = true;
        }
    }
    for (int i = 0; i <= N; i++) {
        if ((2*i <= N && dp[2*i][0]) || (2*i+1 <= N && dp[2*i+1][0]) || (i >= A && dp[i-A][1]) || (i >= B && dp[i-B][1])) {
            dp[i][1] = true;
        }
    }
    for (int i = N; i >= 0; i--) {
        if (dp[i][0] || dp[i][1]) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
