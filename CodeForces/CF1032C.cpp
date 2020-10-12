// Codeforces 1032C. Playing Piano
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(2e5+5)
#define INF 0x3f3f3f
#define MOD (int)(1e9+7)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, A[NMAX], dp[NMAX][7];

void printAns(int i, int j) {
    if (i == 1) {
        // cout << j;
        return;
    }
    printAns(i-1, dp[i][j]);
    cout << " " << dp[i][j];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= 5; j++) {
            if (i==1) {
                dp[i][j] = 6;
            }
            else {
                if (A[i-1] > A[i]) {
                    for (int k = j+1; k <= 5; k++) {
                        //dp[i][j] = max(dp[i][j], dp[i-1][k]);
                        if (dp[i-1][k]) {
                            dp[i][j] = k;
                        }
                    }
                }
                else if (A[i-1] < A[i]) {
                    for (int k = 1; k < j; k++) {
                        //dp[i][j] = max(dp[i][j], dp[i-1][k]);
                        if (dp[i-1][k]) {
                            dp[i][j] = k;
                        }
                    }
                }
                else { // ==
                    for (int k = 1; k <= 5; k++) {
                        if (j != k) {
                            //dp[i][j] = max(dp[i][j], dp[i-1][k]);
                            if (dp[i-1][k]) {
                                dp[i][j] = k;
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    for (int j = 1; j <= 5; j++) {
        for (int i = 1; i <= N; i++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    bool flag = false;
    for (int i = 1; i <= 5; i++) {
        if (dp[N][i]) {
            flag = true;
            printAns(N, i);
            break;
        }
    }
    if (!flag) {
        cout << -1 << endl;
    }

    return 0;
}
