// CSES Problem Set - Book Shop
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
#define XMAX (int)(1e5+5)
#define INF 0x3f3f3f
#define MOD (int)(1e9+7)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, X, price[NMAX], pages[NMAX], dp[XMAX], ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> price[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> pages[i];
    }


    memset(dp, -INF, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = X - price[i]; j >= 0; j--) {
            dp[j + price[i]] = max(dp[j + price[i]], dp[j] + pages[i]);
            ans = max(ans, dp[j + price[i]]);
        }
    }

    cout << ans << endl;

    return 0;
}
