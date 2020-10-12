// CCC '15 J5 - π-day
// recursive solution
#include <iostream>
#define MAXSIZE 251
using namespace std;

int N, K, dp[MAXSIZE][MAXSIZE][MAXSIZE]; // 251 * 251 * 251

/*
 * n = pies left to give (decreases)
 * k = people left to serve (decreases)
 * min = min pies to give each subsequent person (increases)
 */
int solve(int n, int k, int min) {
    if(dp[n][k][min] == 0) { // if this problem hasn't been solved yet
        if (n==k || k == 1) { // base case
            dp[n][k][min] = 1;
        }
        else { // recursive case
            for (int i = min; i <= n/k; i++) {
                dp[n][k][min] += solve(n-i,k-1,i);
            }
        }
    }
    return dp[n][k][min];
}

int main() {
    cin >> N >> K;
    cout << solve(N,K,1) << endl;
}
