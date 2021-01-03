// Problem 8 - Largest product in a series
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

string S;
ll ans;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> S;
    for (int i = 0; i + 12 < 1000; i++) {
        ll x = 1;
        for (int j = 0; j < 13; j++) {
            x *= (S[i + j] - '0');
        }
        ans = max(ans, x);
    }
    cout << ans << endl;

    return 0;
}
