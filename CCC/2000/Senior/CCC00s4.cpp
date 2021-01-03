// CCC '00 S4 - Golf
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 5300
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, K, dp[NMAX], ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int A; cin >> A;
        for (int j = 0; j + A <= N; j++) {
            dp[j + A] = min(dp[j + A], dp[j] + 1);
        }
    }
    if (dp[N] > 5300) {
        cout << "Roberta acknowledges defeat." << endl;
    }
    else {
        cout << "Roberta wins in " << dp[N] << " strokes." << endl;
    }

    return 0;
}
