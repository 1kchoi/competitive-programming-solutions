// CCC '15 S5 - Greedy For Pies
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF 0x3f3f3f
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M, ans, dp[2][2][103][103];
vi A, B;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        A.PB(x);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int x; cin >> x;
        B.PB(x);
    }
    sort(B.rbegin(), B.rend());

    for (int i = 0; i <= N; i++) {
        int p = i % 2;
        memset(dp[p], 0, sizeof(dp[p]));
        for (int j = 0; j <= M; j++) {
            for (int k = M; k >= j; k--) {
                if (i > 0) {
                    dp[p][0][j][k] = max(dp[p][0][j][k], dp[1-p][1][j][k]); // ignore
                }
                if (k < M) {
                    dp[p][0][j][k] = max(dp[p][0][j][k], dp[p][1][j][k+1]); // use filler pie
                }
                if (i > 0) {
                    dp[p][1][j][k] = max({dp[p][0][j][k], dp[1-p][0][j][k] + A[i-1]}); // take
                }
                if (j > 0) {
                    dp[p][1][j][k] = max(dp[p][1][j][k], dp[p][0][j-1][k] + B[j-1]); // use sugar pie
                }
            }
            if (i == N) {
                ans = max(ans, dp[p][1][j][j]);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
