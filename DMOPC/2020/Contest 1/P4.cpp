// DMOPC '20 Contest 1 P4 - Victor Makes Bank
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

ll N, K, T, C, A[105][105], ans;

void multiply(ll P[105][105], ll Q[105][105]) { // P *= Q
    ll res[105][105];

    for (int i = 0; i <= T; i++) {
        for (int j = 0; j <= T; j++) {
            res[i][j] = 0;
            for (int k = 0; k <= T; k++) {
                res[i][j] += P[i][k] * Q[k][j];
                res[i][j] %= MOD;
            }
        }
    }

    for (int i = 0; i <= T; i++)
        for (int j = 0; j <= T; j++)
            P[i][j] = res[i][j];
}


void binpow(ll X) {
    ll B[105][105];
    memset(B, 0, sizeof(B));
    for (int i = 1; i <= T; i++) B[i][i - 1] = 1;
    B[0][T] = K;
    B[T][T] = 1;

    while (X) {
        if (X & 1) multiply(A, B);
        multiply(B, B);
        X /= 2;
    }
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> K >> T >> C;

    for (int i = 0; i <= T; i++) {
        A[i][i] = 1;
    }

    binpow(N - 1);

    for (int i = 0; i <= T; i++) {
        ans += A[i][T] * C;
        ans %= MOD;
    }
    ans += A[T][T] * C;
    ans %= MOD;

    cout << ans << endl;

    return 0;
}
