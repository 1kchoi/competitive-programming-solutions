// CSES Problem Set - Edit Distance
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(5e3+5)
#define INF 0x3f3f3f
#define MOD (int)(1e9+7)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

string A, B;
int dp[NMAX][NMAX];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> A >> B;

    for (int i = 0; i <= sz(A); i++) {
        for (int j = 0; j <= sz(B); j++) {
            if (i == 0) {
                dp[i][j] = j;
            }
            else if (j == 0) {
                dp[i][j] = i;
            }
            else {
                //cout << i << " " << j << " " << A[i-1] << " " << B[]
                dp[i][j] = min({dp[i-1][j-1] + (A[i-1] != B[j-1]), dp[i][j-1] + 1, dp[i-1][j] + 1});
            }
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    //cout << endl;
    cout << dp[sz(A)][sz(B)] << endl;

    return 0;
}
