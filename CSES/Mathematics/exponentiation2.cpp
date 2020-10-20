// CSES Problem Set - Exponentiation II
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
#define NMAX (int)(1e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, A, B, C;

ll binpow(ll x, ll n, ll m) {
    x %= m;
    ll ans = 1;

    while (n > 0) {
        if (n % 2) {
            ans *= x; ans %= m;
        }
        x *= x; x %= m;
        n /= 2;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N;
    while (N--) {
        cin >> A >> B >> C;
        cout << binpow(A, binpow(B, C, MOD - 1), MOD) << endl;
    }

    return 0;
}
