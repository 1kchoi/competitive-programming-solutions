// USACO 2018 US Open Contest, Gold
// Problem 3. Talent Show
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX 255
#define WMAX 1005
#define INF (1e18)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, W, weight[NMAX], talent[NMAX], ans;
ll dp[WMAX];

bool check(int y) {
    for (int i = 0; i < WMAX; i++) {
        dp[i] = -INF;
    }
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        ll score = 1000 * ((ll)talent[i]) - y * ((ll)weight[i]);
        for (int j = W; j >= 0; j--) {
            int j1 = min(j + weight[i], W);
            if (dp[j] != -INF && dp[j1] < dp[j] + score) {
                dp[j1] = dp[j] + score;
            }
        }
    }

    return dp[W] >= 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("talent.in", "r", stdin);
    freopen("talent.out", "w", stdout);

    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> talent[i];
    }

    int lo = 0, hi = 250000001;
    while (lo <= hi) {
        int mid = lo + (hi-lo)/2;
        if (check(mid)) {
            ans = mid;
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }

    cout << ans << endl;

    return 0;
}
