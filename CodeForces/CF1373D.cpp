// Codeforces 1373D - Maximum Sum on Even Positions
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(2e5+5)
#define INF (INT_MAX/2)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int T, N;
ll A[NMAX], dp[NMAX][5];

int max3(ll a, ll b, ll c) {
    return max(max(a,b),c);
}

int max4(ll a, ll b, ll c, ll d) {
    return max(max(a,b),max(c,d));
}

void printDP() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j <= N; j++) {
            cout << dp[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> T;
    while (T--) {
        memset(dp,0,sizeof(dp));
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        if (N==1) {
            cout << A[0] << endl;
        }
        else if (N==2) {
            cout << max(A[1],A[2]) << endl;
        }
        else {
            dp[1][0] = A[0];
            for (int i = 3; i <= N; i += 2) {
                dp[i][0] = dp[i-2][0] + A[i-1];
            }

            for (int i = 2; i <= N; i += 2) {
                dp[i][1] = max(dp[i-2][1], dp[i-1][0]) + A[i-1];
            }

            dp[2][2] = A[1];
            for (int i = 4; i <= N; i += 2) {
                dp[i][2] = max(dp[i-2][2], dp[i-3][0]) + A[i-1];
            }

            dp[3][3] = A[1]+A[2];
            for (int i = 5; i <= N; i += 2) {
                dp[i][3] = max3(dp[i-3][1], dp[i-1][2], dp[i-2][3]) + A[i-1];
            }

            //printDP();
            cout << max4(dp[(N-1)/2*2+1][0], dp[(N-1)/2*2][1], dp[N/2*2][2], dp[(N-1)/2*2+1][3]) << endl;
            //cout << dp[(N-1)/2*2+1][0] << " " << dp[(N-1)/2*2][1] << " " << dp[N/2*2][2] << " " << dp[(N-1)/2*2+1][3] << endl;
        }
    }

    return 0;
}
