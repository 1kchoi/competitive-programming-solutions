// CSES Problem Set - Removing Digits
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e6+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, dp[NMAX], infinity;

int solve(int X) {
    if (dp[X] == infinity) {
        if (X == 0) {
            dp[X] = 0;
        }
        else {
            int a = X;
            while (a) {
                int candidate = X - (a % 10);
                //cout << candidate << endl;
                if (candidate >= 0 && candidate != X) {
                    dp[X] = min(dp[X], solve(candidate) + 1);
                }
                a /= 10;
            }
        }
    }
    return dp[X];
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N;
    memset(dp, INF, sizeof(dp));
    infinity = dp[0];
    cout << solve(N) << endl;

    return 0;
}
