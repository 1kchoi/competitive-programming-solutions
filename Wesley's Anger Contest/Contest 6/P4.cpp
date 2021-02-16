// Wesley's Anger Contest 6 Problem 4 - Runway Lights
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(2e5+5)
#define INF 0x3f
#define MOD 998244353
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, K, pf[3][NMAX], pfwa[NMAX], pfac[NMAX], pfwac[NMAX], nw, na, nc;
vi A;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    string input;
    cin >> N >> K >> input;
    for (int i = 0; i < N; i++) {
        if (input[i] == 'W') {
            A.PB(0);
        }
        if (input[i] == 'A') {
            A.PB(1);
        }
        if (input[i] == 'C') {
            A.PB(2);
        }
    }
    N = sz(A);

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            pf[j][i] = pf[j][i - 1];
        }
        pf[A[i - 1]][i]++;
        pf[A[i - 1]][i] %= MOD;
    }
    for (int i = 1; i <= N; i++) {
        pfwa[i] = pfwa[i - 1];
        if (A[i - 1] == 1) {
            pfwa[i] += pf[0][i];
        }
        pfwa[i] %= MOD;

        pfac[i] = pfac[i - 1];
        if (A[i - 1] == 2) {
            pfac[i] += pf[1][i];
        }
        pfac[i] %= MOD;
    }
    for (int i = 1; i <= N; i++) {
        pfwac[i] = pfwac[i - 1];
        if (A[i - 1] == 2) {
            pfwac[i] += pfwa[i];
        }
        pfwac[i] %= MOD;
    }

    nw = pf[0][N];
    na = pf[1][N];
    nc = pf[2][N];

    ll ans = 0;
    for (ll k = 0; k < K; k++) {
    //    ans += ((nc * (((k * pfwa[N]) % MOD) + (((na * nw) % MOD) * (((k - 1) * k / 2) % MOD)) % MOD)) % MOD) + ((k * nw * pfac[N]) % MOD) + pfwac[N];

        // ans += nc * (k * pfwa[N] + na * nw * ((k - 1) * k / 2)) + k * nw * pfac[N] + pfwac[N];

        ll kpfwan = (k * pfwa[N]) % MOD;
        ll nanw = (na * nw) % MOD;
        ll kk = ((k - 1) * k / 2) % MOD;
        ll pt1 = (nanw * kk) % MOD;
        ll pt2 = (kpfwan + pt1) % MOD;
        ll pt3 = (nc * pt2) % MOD;
        ll knw = (k * nw) % MOD;
        ll pt4 = (knw * pfac[N]) % MOD;
        ll pt5 = (pt3 + pt4) % MOD;
        ll pt6 = (pt5 + pfwac[N]) % MOD;

        ans += pt6;
        ans %= MOD;

        assert(ans >= 0 && ans < MOD);
    }

    cout << ans << endl;


    return 0;
}
