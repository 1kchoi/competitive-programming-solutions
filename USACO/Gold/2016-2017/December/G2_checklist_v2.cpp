// USACO 2016 December Contest, Gold
// Problem 2. Cow Checklist
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
#define NMAX (int)(1e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll NA, NB, dp[NMAX][NMAX][2]; // 0 is on A, 1 is on B
vii A, B;

int dist(ii v, ii u) {
    ll x = v[0] - u[0];
    ll y = v[1] - u[1];
    return x * x + y * y;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);

    memset(dp, INF, sizeof(dp));
    //dp[0][0][0] = 0;

    cin >> NA >> NB;
    for (int i = 0; i < NA; i++) {
        ll x, y; cin >> x >> y;
        A.PB({x, y});
    }
    for (int i = 0; i < NB; i++) {
        ll x, y; cin >> x >> y;
        B.PB({x, y});
    }

/*
    for (int i = 0; i < NA; i++) {
        for (int j = 0; j < NB; j++) {
            if (i) {
                dp[i][j][0] = min(dp[i - 1][j][0] + dist(A[i - 1], A[i]), dp[i - 1][j][1] + dist(B[j], A[i]));
            }
            if (j) {
                dp[i][j][1] = min(dp[i][j - 1][1] + dist(B[j - 1], B[j]), dp[i][j - 1][0] + dist(A[i], B[j]));
            }
        }
    }
//*/
//*
    dp[1][0][0] = 0;
    for (int i = 1; i <= NA; i++) {
        for (int j = 0; j <= NB; j++) {
            /*
            if (i == 1 && j == 0) {
                dp[i][j][0] = 0;
            }
            else {
                // 110: min(010)
                // if j == 0, then k must be 0
                // 2 0: i wouldnt try 2 -1, i would only try 1 0

                if (i) {
                    int choice1 = dp[i - 1][j][0] + dist(A[i - 1], A[i]);
                    int choice2 = (j) ? dp[i - 1][j][1] + dist(B[j], A[i]) : INT_MAX;
                    dp[i][j][0] = min(choice1, choice2);
                }
                if (j) {
                    int choice1 = dp[i][j - 1][1] + dist(B[j - 1], B[j]);
                    int choice2 = dp[i][j - 1][0] + dist(A[i], B[j]);
                    dp[i][j][1] = min(choice1, choice2);
                }
            }
            */

            for (int k = 0; k < 2; k++) {
                if (!k && !i) continue;
                if (k && !j) continue;
                ii source;
                if (!k) source = A[i-1];
                else source = B[j-1];

                if (i < NA) {
                    dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k] + dist(source, A[i]));
                }
                if (j < NB) {
                    dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][k] + dist(source, B[j]));
                }
            }

        }
    }
//*/
    //cout << dp[NA - 1][NB - 1][0] << endl;
    cout << dp[NA][NB][0] << endl;

    return 0;
}
