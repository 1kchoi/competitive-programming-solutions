// Mock CCC '19 Contest 1 S4 - Pusheen Plays Neko Atsume
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll A, B, C, D, Q, X;
ll dp[(int)(1e7+2)];

ll solve(int x) {
    if (x <= 0) return 1;
    if (x > (ll)(1e7)) {
        return solve(x / A - B) + solve(x / C - D);
    }
    return dp[x];
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> A >> B >> C >> D >> Q;

    dp[0] = 1;
    for (ll i = 1; i <= 1e7; i++) {
        dp[i] = dp[max(0LL, i / A - B)] + dp[max(0LL, i / C - D)];
        //cout << i << " " << dp[i] << endl;
    }

    while (Q--) {
        cin >> X;
        cout << solve(X) << endl;
    }

    return 0;
}
