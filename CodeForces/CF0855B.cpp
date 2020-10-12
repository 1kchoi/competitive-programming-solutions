// Codeforces 855B - Marvolo Gaunt's Ring
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(1e5+5)
#define INF LLONG_MIN
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N;
int A[NMAX];
int B[3];
ll dp[NMAX][3];

void printDP() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N;
    for (int i = 0 ; i < 3; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            if (!j) {
                dp[i][j] = A[i] * B[j];
            }
            else {
                ll best = INF;
                for (int k = 0; k <= i; k++) {
                    best = max(best, dp[k][j-1]);
                }
                dp[i][j] = best + A[i] * B[j];
            }
        }
    }
    printDP();
    cout << dp[N-1][2] << endl;

    return 0;
}
