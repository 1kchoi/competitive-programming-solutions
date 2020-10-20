// USACO 2019 January Contest, Gold - Problem 1. Cow Poetry
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
#define MMAX (int)(1e5+5)
#define NMAX (int)(5e3+5)
#define KMAX (int)(5e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, M, K, freq[28], dp[KMAX], ways[NMAX], ans = 1;
vector<ar<ll, 2>> A;

ll binpow(ll x, ll n, ll m) {
    x %= m;
    ll res = 1;

    while (n > 0) {
        if (n % 2) {
            res *= x; res %= m;
        }
        x *= x; x %= m;
        n /= 2;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("poetry.in", "r", stdin);
    //freopen("input.in", "r", stdin);
    freopen("poetry.out", "w", stdout);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        ll s, c; cin >> s >> c;
        A.PB({s, c});
    }
    for (int i = 0; i < M; i++) {
        char x; cin >> x;
        freq[x - 'A']++;
    }

    dp[0] = 1;
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j < sz(A); j++) {
            if (i >= A[j][0]) {
                dp[i] += dp[i - A[j][0]];
                dp[i] %= MOD;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        ways[A[i][1]] += dp[K - A[i][0]];
        ways[A[i][1]] %= MOD;
    }

    for (int i = 0; i < 28; i++) {
        if (freq[i]) {
            ll sub = 0;
            for (int j = 0; j <= N; j++) {
                if (ways[j]) {
                    sub += binpow(ways[j], freq[i], MOD);
                    sub %= MOD;
                }
            }
            ans *= sub;
            ans %= MOD;
        }
    }

    cout << ans << endl;

    return 0;
}
