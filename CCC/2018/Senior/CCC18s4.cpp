// CCC '18 S4 - Balanced Trees
// 9/15 points
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

ll A;
map<ll, ll> dp;

ll BST(ll N) {
    if (!dp.count(N)) {
        if (N == 1) {
            dp[N] = 1;
        }
        else {
            ll ans = 0;
            for (int k = 2; k <= N; k++) {
                ll s = BST(N / k);
                ll l = k, i = k, r = N;
                while (l <= r) {
                    ll m = l + (r - l) / 2;
                    if (N / m == N / k) {
                        i = m;
                        l = m + 1;
                    }
                    else {
                        r = m - 1;
                    }
                }
                ans += s * (i - k + 1);
                k = i;
            }
            dp[N] = ans;
        }
    }
    return dp[N];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> A;
    cout << BST(A) << endl;

    return 0;
}
