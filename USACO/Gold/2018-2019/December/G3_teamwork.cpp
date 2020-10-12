// USACO 2018 December Contest, Gold
// Problem 3. Teamwork
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(1e4+5)
#define INF (INT_MAX/2)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, K, A[NMAX], dp[NMAX];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= N; i++) {
        int best = 0;
        int mx = 0;

        for (int j = 1; j <= K; j++) {
            mx = max(mx, A[i-j]);
            if (i >= j) {
                best = max(best, dp[i-j] + j*mx);
            }
        }

        dp[i] = best;
    }

    cout << dp[N] << endl;

    return 0;
}
