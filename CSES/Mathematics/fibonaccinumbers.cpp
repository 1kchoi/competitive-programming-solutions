// CSES Problem Set - Fibonacci Numbers
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

ll N, A[2][2], B[2][2];

void multiply(ll X[2][2], ll Y[2][2]) {
    ll res[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                res[i][j] += X[i][k] * Y[k][j];
                res[i][j] %= MOD;
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            X[i][j] = res[i][j];
        }
    }
}

void binpow(ll X) {
    B[0][1] = B[1][0] = B[1][1] = 1;
    A[0][0] = A[1][1] = 1;
    while (X) {
        if (X & 1) {
            multiply(A, B);
        }
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
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N;
    binpow(N);
    cout << A[0][1] << endl;

    return 0;
}
