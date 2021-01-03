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

ll N, K, M, ans;

bool check(int X) {
    ll days = 0;
    ll gallons = N;
    while (gallons >= 0) {
        ll perday = gallons / X;
        if (perday <= M) { // special case, final stretch
            days += (gallons - 1) / M + 1;
            break;
        }
        else {
            ll l = 1, r = gallons, spot = 0;
            while (l <= r) {
                ll m = l + (r - l) / 2;
                if (m / X == perday) {
                    spot = m;
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
            assert(spot);
            ll addeddays = (gallons - spot) / perday + 1;
            days += addeddays;
            gallons -= addeddays * perday;
        }
    }
    return days <= K;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO("loan");

    cin >> N >> K >> M;
    ll l = 1, r = N;
    while (l <= r) {
        ll X = l + (r - l) / 2;
        if (check(X)) {
            ans = X;
            l = X + 1;
        }
        else {
            r = X - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
