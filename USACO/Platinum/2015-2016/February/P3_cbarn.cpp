// USACO 2016 February Contest, Platinum
// Problem 3. Circular Barn
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, K, A[NMAX], ans, dp[8][NMAX], sum[NMAX][NMAX], infinity;

void solve(int rot, int i, int l, int r, int optl, int optr) {
    if (l > r) return;
    int m = l + (r - l) / 2; // solving dp[i][m]
    int argk = -1;
    for (int k = max(m + 1, optl); k <= optr; k++) {
        ll cand = dp[i - 1][k] + sum[(rot + m) % N][(rot + k - 1 + N) % N];
        if (argk == -1 || dp[i][m] > cand) {
            dp[i][m] = cand;
            argk = k;
        }
    }
    //cout << i << " " << m << " " << best[1] << " " << best[0] << endl;
    solve(rot, i, l, m - 1, optl, argk);
    solve(rot, i, m + 1, r, argk, optr);
}

ll run(int rot) {
    dp[0][N] = 0;

    for (int i = 1; i <= K; i++) {
        solve(rot, i, 0, N - i, 0, N + 1 - i);
    }

    return dp[K][0];
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    memset(dp, INF, sizeof(dp));
    infinity = dp[0][0];

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N + i; j++) {
            sum[i][j % N] = sum[i][(j + N - 1) % N] + A[j % N] * (j - i);
        }
    }

    ans = infinity;
    for (int i = 0; i < N; i++) {
        ll cand = run(i);
        ans = min(ans, cand);
        rotate(A, A + 1, A + N);
    }
    cout << ans << endl;

    return 0;
}
