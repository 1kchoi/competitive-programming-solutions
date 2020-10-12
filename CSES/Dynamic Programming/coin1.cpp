// CSES - Coin Combinations I
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(1e2+2)
#define XMAX (int)(1e6+2)
#define MOD (int)(1e9+7)
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
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= x; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] == i) {
                sum += 1;
            }
            if (a[j] < i) {
                sum += dp[i-a[j]];
                sum %= MOD;
            }
        }
        dp[i] = sum;
    }

    cout << dp[x] << endl;

    return 0;
}
