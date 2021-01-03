// CCC '19 S5 - Triangle: The Data Structure
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(3e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int N, K;
ll ans;
vvi dp[NMAX];

ll twothirds(ll x) {
    if (x % 3 == 1) {
        return x * 2 / 3 + 1;
    }
    return x * 2 / 3;
}

ll solve(ll k, ll i, ll j) {
    if (!( sz(dp[k]) && sz(dp[k][i]) && dp[k][i][j] >= 0 )) {
        if (!sz(dp[k])) {
            dp[k].assign(N + 2 - k, vi());
        }
        if (!sz(dp[k][i])) {
            dp[k][i].assign(i + 2, -1);
        }
        ll nextk = twothirds(k);
        ll c1 = solve(nextk, i, j);
        ll c2 = solve(nextk, i + k - nextk, j);
        ll c3 = solve(nextk, i + k - nextk, j + k - nextk);
        dp[k][i][j] = max({c1, c2, c3});
    }
    return dp[k][i][j];
}

//*
void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}
//*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> K;
    dp[1].assign(N + 1, vi());
    for (int i = 0; i < N; i++) {
        dp[1][i].assign(i + 2, -1);
        for (int j = 0; j <= i; j++) {
            cin >> dp[1][i][j];
        }
    }
    for (int i = 0; i <= N - K; i++) {
        for (int j = 0; j <= i; j++) {
            ans += solve(K, i, j);
        }
    }
    cout << ans << endl;

    return 0;
}
