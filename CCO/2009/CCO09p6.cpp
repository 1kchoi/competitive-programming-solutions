// CCO '09 P6 - A Weighty Problem
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define DMAX 105
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef pair<ll, double> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll C, D, K, V[DMAX];
double W[DMAX], dp[2 * NMAX], ans, startweight;
vii demsort;

double getWeight(ll X) {
    double ret = 0;
    for (int i = 0; i < D; i++) {
        ret += X / demsort[i].first * demsort[i].second;
        X %= demsort[i].first;
    }
    return ret;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> C >> D >> K;
    for (int i = 1; i <= D; i++) {
        ll x; double y; cin >> x >> y;
        V[i] = x;
        W[i] = y;
        demsort.PB(ii(V[i], W[i]));
    }

    sort(all(demsort));
    reverse(all(demsort));

    memset(dp, -INF, sizeof(dp));
    ans = -dp[0]; // ans = INF
    dp[0] = 0;
    for (int i = 0; i < K; i++) {
        ll x; cin >> x;
        double weight = W[x]; ll value = V[x];
        startweight += weight;
        for (int j = 2 * NMAX - 1; j >= value; j--) {
            if (dp[j - value] < 0) continue;
            dp[j] = max(dp[j], dp[j - value] + weight);
        }
    }


    bool found = 0;
    for (int i = C; i < 2 * NMAX; i++) {
        if (ans > startweight - dp[i] + getWeight(i - C)) {
            ans = startweight - dp[i] + getWeight(i - C);
            found = 1;
        }
    }

    if (found) {
        cout << fixed << setprecision(2) << ans << endl;
    }
    else {
        cout << "too poor" << endl;
    }


    return 0;
}
