// USACO 2017 February Contest, Gold
// Problem 2. Why Did the Cow Cross the Road II
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
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, A[NMAX], B[NMAX], dp[NMAX][NMAX];

bool isFriendly(int i, int j) {
    return (abs(A[i] - B[j]) <= 4);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + isFriendly(i - 1, j - 1)});
        }
    }

    cout << dp[N][N] << endl;

    return 0;
}
