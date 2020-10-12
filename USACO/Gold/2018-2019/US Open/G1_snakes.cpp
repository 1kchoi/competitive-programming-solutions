// USACO 2019 US Open Contest, Gold
// Problem 1. Snakes
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX 405
#define INF (INT_MAX/2)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, K, T, A[NMAX], Q[NMAX][NMAX], dp[NMAX][NMAX];

void printQ() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(4) << Q[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        T += A[i];
    }

    for (int i = 0; i < N; i++) {
        Q[i][i] = A[i];
        for (int j = i+1; j < N; j++) {
            Q[i][j] = max(Q[i][j-1], A[j]);
        }
    }

    //printQ();
    //cout << T << endl;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            if (j == 0) {
                dp[i][j] = i*Q[0][i-1];
            }
            else {
                int best = INF;
                for (int x = 0; x < i; x++) {
                    //cout << i << " " << j << " " << x << " " << dp[x][j - 1] + (i - x) * Q[x][i - 1] << endl;
                    best = min(best, dp[x][j - 1] + (i - x) * Q[x][i - 1]);
                }
                dp[i][j] = best;
            }
        }
    }

    cout << dp[N][K] - T << endl;


    return 0;
}
