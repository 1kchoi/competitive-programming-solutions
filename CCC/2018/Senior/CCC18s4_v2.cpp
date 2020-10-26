// CCC '18 S4 - Balanced Trees
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

ll A, dp1[NMAX], dp2[NMAX], notfound;
map<ll, ll> dp;

ll BST(ll N) {
    if ((N * N <= A && dp1[N] == notfound) || (N * N > A && dp2[A/N] == notfound)) {
        if (N == 1) {
            dp1[N] = 1;
        }
        else {
            ll ans = 0;
            for (int k = 2; (N / k) * (N / k) > N; k++) {
                ans += BST(N / k);
            }
            for (int i = 1; i * i <= N; i++) {
                ans += BST(i) * (N / i - N / (i + 1));
            }

            if (N * N <= A) {
                dp1[N] = ans;
            }
            else {
                dp2[A/N] = ans;
            }
        }
    }
    if (N * N <= A) return dp1[N];
    return dp2[A/N];

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    memset(dp1, -INF, sizeof(dp1));
    memset(dp2, -INF, sizeof(dp2));
    notfound = dp1[0];
    cin >> A;
    cout << BST(A) << endl;

    return 0;
}
