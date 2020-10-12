// Codeforces 1420C1. Pokémon Army (easy version)
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
#define NMAX (int)(3e5+5)
#define INF 0x3f3f3f
#define MOD (int)(1e9+7)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll T, N, Q, A[NMAX], dp[2][NMAX];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    dp[1][0] = -INF;

    cin >> T;
    while (T--) {
        cin >> N >> Q;
        for (int i = 0; i < N; i++) {
            cin >> A[i];
            dp[0][i+1] = max(dp[0][i], dp[1][i] - A[i]);
            dp[1][i+1] = max(dp[1][i], dp[0][i] + A[i]);
        }
        cout << max(dp[0][N], dp[1][N]) << endl;
    }

    return 0;
}
