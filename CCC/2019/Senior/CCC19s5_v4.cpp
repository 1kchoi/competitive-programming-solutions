// CCC '19 S5 - Triangle: The Data Structure
// but im actually going to try to solve it this time :)
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(3e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

ll N, K, ans;
vi order;
vvi dp[2];

void fillOrder(int X) {
    order.PB(X);
    if (X == 2) {
        fillOrder(1);
    }
    else if (X > 2) {
        fillOrder(2 * (X + 1) / 3);
    }
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        dp[0].PB(vi(i + 1, 0));
        for (int j = 0; j <= i; j++) {
            cin >> dp[0][i][j];
            if (K == 1) {
                ans += dp[0][i][j];
            }
        }
    }
    fillOrder(K);
    reverse(all(order));

    for (int i = 1; i < sz(order); i++) {
        int p = i % 2;
        dp[p].clear();
        ll d = order[i] - order[i - 1];
        for (int j = 0; j + order[i] <= N; j++) {
            dp[p].PB(vi(j + 1, -1));
            for (int k = 0; k <= j; k++) {
                dp[p][j][k] = max({dp[1 - p][j][k], dp[1 - p][j + d][k], dp[1 - p][j + d][k + d]});
                if (order[i] == K) {
                    ans += dp[p][j][k];
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
