// DMOPC '19 Contest 2 P4 - A Greedy Problem
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(2e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, T, Q, A[NMAX], dp[NMAX];

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

void add(ll x) {
    for (int i = T; i >= x; i--) {
        dp[i] += dp[i - x];
        dp[i] %= MOD;
    }
}

void remove(ll x) {
    for (int i = x; i <= T; i++) {
        dp[i] -= dp[i - x];
        dp[i] += MOD;
        dp[i] %= MOD;
    }
}

void debugDP() {
    cout << "PRINTING DP" << endl;
    for (int i = 0; i <= T; i++) {
        if (dp[i]) cout << i << " " << dp[i] << endl;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> T >> Q;
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        add(A[i]);
    }
    while (Q--) {
        int a, b, q; cin >> a >> b >> q;
        remove(A[a]);
        remove(A[b]);
        ll solvetime = q - A[a] - A[b];
        ll ans = 0;
        for (int i = 0; i <= solvetime; i++) {
            ans += dp[i];
            ans %= MOD;
        }
        cout << ans << endl;
        add(A[a]);
        add(A[b]);
    }

    return 0;
}
