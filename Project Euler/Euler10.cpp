// Problem 10 - Summation of primes
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(2e6)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

bool p[NMAX + 1];
ll ans = 0;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    memset(p,1,sizeof(p));
    for (int i = 2; i <= NMAX; i++) {
        if (p[i]) {
            ans += i;
            for (int j = 2; i * j <= NMAX; j++) {
                p[i * j] = false;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
