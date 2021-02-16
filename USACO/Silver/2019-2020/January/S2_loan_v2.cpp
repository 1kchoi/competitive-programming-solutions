// USACO 2020 January Contest, Silver
// Problem 2. Loan Repayment
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

ll N, M, K, ans;

bool solve(ll X) {
    ll gallons = N;
    ll days = 0;
    while (gallons > 0) {
        ll givingperday = gallons / X;
        //cout << days << " " << gallons << " " << givingperday << endl;
        if (givingperday <= M) {
            ll daystojump = (gallons - 1) / M + 1;
            days += daystojump;
            //cout << "bruh " << days << endl;
            break;
        }
        else {
            ll lbound = givingperday * X;
            ll distancetocover = gallons - lbound;
            ll daystojump = distancetocover / givingperday + 1;
            days += daystojump;
            gallons -= daystojump * givingperday;
            if (days > K) return 0;
        }
    }
    return days <= K;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO("loan");

    cin >> N >> K >> M;

    //cout << solve(499999900000) << endl;


    ll l = 1, r = 1e12;
    while (l <= r) {
        ll m = l + (r - l) / 2;
        ll msolve = solve(m);
        if (msolve) {
            ans = m;
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }


    cout << ans << endl;

    return 0;
}
