// Google Kick Start 2020 Round H Question 1 - Boring Numbers
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

ll T, L, R, ans;
map<ll, ll> dp;

ll countDigits(ll X) {
    ll a = 0;
    while (X) {
        a++;
        X /= 10;
    }
    return a;
}

bool isBoring(ll X) {
    if (X < 10) return X % 2;
    if (countDigits(X) % 2 == X % 2) {
        return isBoring(X / 10);
    }
    return false;
}

ll f(bool p, ll X) {
    return (X - p) / 2 + 1;
}

ll solve(ll X) {
    cout << "dp: " << X << endl;
    if (!dp.count(X)) {
        if (X < 10) {
            dp[X] = (X + 1) / 2;
            cout << "hi!" << X << endl;
        }
        else {
            dp[X] = solve(X / 10 - 1) * 5 + isBoring(X / 10) * f(countDigits(X) % 2, X);
            cout << solve(X / 10 - 1) << " *  5 + " << isBoring(X / 10) << " * " << f(countDigits(X) % 2, X % 10) << endl;
            cout << "digit count of " << X << ": " << countDigits(X) % 2 << endl;
            //cout <<
        }
    }
    cout << "returning dp of " << X << " = " << dp[X] << endl;
    return dp[X];
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        /*
        cin >> L >> R;
        dp.clear();
        ll A = solve(R);
        dp.clear();
        ll B = solve(L - 1);
        ans = A - B;

        cout << "Case #" << tc << ": " << ans << endl;
        */
        //dp.clear();
        cin >> L;
        ans = solve(L);
        cout << "answer: " << ans << endl;
    }

    return 0;
}
