// CCC '13 S5 - Factor Solitaire
// 9/15 points
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#define NMAX 5000005
using namespace std;

int N;
int dp[NMAX];

int solve(int n) {
    int min = NMAX;
    int val;
    //cout << "n: " << n << endl;
    if (dp[n] == -1){
        if (n==1) {
            dp[n] = 0;
        }
        else {
            for (int i = 2; i <= sqrt(n)+1; i++) {
                //cout << "i:" << i << endl;
                if (n%i==0) {
                    val = solve(n-n/i)+i-1;
                    //cout << "val, min: " << val << " " << min << endl;
                    if (val < min) {
                        //cout << "chungus" << endl;
                        min = val;
                    }
                    val = solve(n-i)+n/i-1;
                    //cout << "val, min: " << val << " " << min << endl;
                    if (val < min) {
                        //cout << "chungus" << endl;
                        min = val;
                    }
                }
            }
            dp[n] = min;
        }
    }
    return dp[n];
}

int main() {
    cin >> N;
    fill(dp, dp+NMAX, -1);
    cout << solve(N) << endl;
}
