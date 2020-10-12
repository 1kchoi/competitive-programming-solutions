// CSES Problem Set - Grid Paths
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e3+5)
#define INF 0x3f3f3f
#define MOD (int)(1e9+7)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, dp[NMAX][NMAX];
bool G[NMAX][NMAX];


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        string s; cin >> s;
        for (int j = 1; j <= N; j++) {
            if (s[j-1] == '.') {
                dp[i][j] = (i==1 && j==1);
                dp[i][j] += dp[i-1][j] + dp[i][j-1];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[N][N] << endl;

    return 0;
}
