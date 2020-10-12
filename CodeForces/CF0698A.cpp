// Codeforces 698A - Vacations
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX 103
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N;
bool S[NMAX][2]; // gym, coding
int dp[NMAX][3];

int min3(int a, int b, int c) {
    return min(a,min(b,c));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    for (int i = 0; i < NMAX; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = (i == 0) ? 0 : (INT_MAX/2);
        }
    }

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        S[i][1] = a%2;
        S[i][0] = a/2;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                dp[i][j] = min3(dp[i-1][0], dp[i-1][1], dp[i-1][2]) + 1;
            }
            else if ((j == 1) && S[i-1][0]) {
                dp[i][j] = min(dp[i-1][0], dp[i-1][2]);
            }
            else if ((j == 2) & S[i-1][1]){
                dp[i][j] = min(dp[i-1][0], dp[i-1][1]);
            }
        }
    }

    cout << min3(dp[N][0], dp[N][1], dp[N][2]) << endl;

    return 0;
}
