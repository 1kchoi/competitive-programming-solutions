#include <iostream>
#include <cstdio>
using namespace std;
#define MAXM 10
#define MAXN 100

int M, N;
int w[MAXM][MAXN];
int d[MAXM][MAXN];
bool dp[MAXM][MAXN];
int p[MAXM][MAXN];

int solve(int i, int j) {
    if (!dp[i][j]) {
        if (j == 0) {
            d[i][j] = w[i][j];
        }
        else {
            int min = INT_MAX;
            for (int a = i-1; a <= i+1; a++) {
                int possible = solve(a,j-1) + w[i][j];
                if (possible < min) {
                    min = possible;
                }
            }
        }
        dp[i][j] = true;
    }
    return d[i][j];
}

int main() {

    while (scanf("%d %d", &M, &N) != EOF) {
        // reset dp array
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &w[i][j]);
            }
        }


    }

}
