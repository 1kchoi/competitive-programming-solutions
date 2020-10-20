// USACO 2016 February Contest, Gold
// Problem 2. Circular Barn Revisited
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 105
#define KMAX 10
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, K;
ll A[NMAX], dp[KMAX][NMAX], ans = LLONG_MAX;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        memset(dp, INF, sizeof(dp));
        dp[0][N] = 0;
        for (int k = 1; k <= K; k++) {
            for (int j = 0; j < N; j++) {
                ll val = 0;
                for (int a = j + 1; a <= N; a++) {
                    val += A[a - 1] * (a - j - 1);
                    dp[k][j] = min(dp[k][j], dp[k - 1][a] + val);
                }
            }
        }
        ans = min(ans, dp[K][0]);
        rotate(A, A + 1, A + N);
    }
    cout << ans << endl;

    return 0;
}
