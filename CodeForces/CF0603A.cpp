// Codeforces 603A - Alternative Thinking
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(1e5+5)
#define INF (INT_MAX/2)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, dp[4][NMAX];
bitset<NMAX> A;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N;
    string s; cin >> s;
    for (int i = 0; i < N; i++) {
        A[i] = (s.at(i) == '1');
    }

    for (int i = 0; i < 3; i++) {
        dp[i][1] = 1;
    }
    for (int i = 0; i+1 < N; i++) {
        bool b = A[i]==A[i+1];
        dp[0][i+2] = dp[0][i+1] + !b;
        dp[1][i+2] = max(dp[0][i+1] + b, dp[1][i+1] + !b);
        dp[2][i+2] = max(dp[1][i+1] + b, dp[2][i+1] + !b);
    }

    cout << max(dp[1][N],dp[2][N]) << endl;

    return 0;
}
