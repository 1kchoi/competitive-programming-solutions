// Now I am become Death, the destroyer of worlds.
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <cassert>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <utility>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <complex>
#define MAXN 52
#define MAXK 32
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int T, N, K, P, input;
int largest, ans;
int v[MAXN][MAXK];
int dp[MAXN][MAXN*MAXK];
bool discovered[MAXN][MAXN*MAXK];

int getValue(int n, int k) {
    if (k == -1) return 0;
    return v[n][k];
}

int solve(int n, int k) {
    //cout << "case n=" << n << " k=" << k << endl;
    if (!discovered[n][k]) {
        discovered[n][k] = true;
        if (n == N || k == 0) {
            dp[n][k] = 0;
        }
        else {
            //largest = 0;
            for (int i = 0; i <= K && i <= k; i++) { // i = how many plates are being taken from stack n
                int p = solve(n+1,k-i)+getValue(n,i-1);
                if (p > dp[n][k]) {
                    dp[n][k] = p;
                }
            }
            //dp[n][k] = largest;
        }
    }
    return dp[n][k];
}

int main() {

    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        memset(discovered, false, sizeof(discovered));
        memset(dp,0,sizeof(dp));
        cin >> N >> K >> P;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < K; j++) {
                cin >> input;
                if (j == 0) {
                    v[i][j] = input;
                }
                else {
                    v[i][j] = input + v[i][j-1];
                }
            }
        }

        cout << "Case #" << tc << ": " << solve (0,P) << endl;
    }

    return 0;
}
