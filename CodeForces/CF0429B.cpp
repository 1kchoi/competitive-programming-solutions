// Codeforces 429B - Working Out
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(1e3+5)
#define INF (INT_MAX/2)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M, ans, A[NMAX][NMAX], dp[5][NMAX][NMAX];

void printDP() {
    for (int b = 0; b < 4; b++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << setw(5) << dp[b][i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++){
            dp[0][i][j] = max((i>0)?dp[0][i-1][j]:0, (j>0)?dp[0][i][j-1]:0) + A[i][j];
        }
    }
    for (int i = N-1; i >= 0; i--) {
        for (int j = 0; j < M; j++){
            dp[1][i][j] = max((i<N-1)?dp[1][i+1][j]:0, (j>0)?dp[1][i][j-1]:0) + A[i][j];
        }
    }
    for (int i = N-1; i >= 0; i--) {
        for (int j = M-1; j >= 0; j--){
            dp[2][i][j] = max((i<N-1)?dp[2][i+1][j]:0, (j<M-1)?dp[2][i][j+1]:0) + A[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = M-1; j >= 0; j--){
            dp[3][i][j] = max((i>0)?dp[3][i-1][j]:0, (j<M-1)?dp[3][i][j+1]:0) + A[i][j];
        }
    }

    for (int i = 1; i < N-1; i++) {
        for (int j = 1; j < M-1; j++) {
            int x1 = dp[0][i][j-1] + dp[2][i][j+1] + dp[1][i+1][j] + dp[3][i-1][j];
            int x2 = dp[1][i][j-1] + dp[3][i][j+1] + dp[2][i+1][j] + dp[0][i-1][j];
            //if (x1 > ans || x2 > ans) cout << i << " " << j << endl;
            ans = max({ans,x1,x2});
        }
    }

    cout << ans << endl;


    return 0;
}
