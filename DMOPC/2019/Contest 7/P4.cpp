// DMOPC '19 Contest 7 P4 - Bob and Continued Fractions
// unfinished
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(3e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, Q, A[NMAX], dat[20][NMAX][2], mask[NMAX];

ll gcd(ll a, ll b) {
    if (!b) return a;
    return gcd(b, a % b);
}

void fillhelper(int depth, int i) {
    dat[depth][i][0] = A[i] * dat[depth][i + 1][0] + dat[depth][i + 1][1];
    dat[depth][i][1] = dat[depth][i + 1][0];
    ll g = gcd(dat[depth][i][0], dat[depth][i][1]);
    dat[depth][i][0] /= g;
    dat[depth][i][1] /= g;
}

void fillDAT(int depth, int l, int r) {
    if (l == r) {
        dat[depth][l][0] = A[l];
        dat[depth][l][1] = 1;
        return;
    }
    int m = (l + r) / 2;
    dat[depth][m][0] = A[m];
    dat[depth][m][1] = 1;
    for (int i = m - 1; i >= l; i--) {
        fillhelper(depth, i);
    }
    dat[depth][r][0] = A[r];
    dat[depth][r][1] = 1;
    mask[r] ^= (1 << depth);
    for (int i = r - 1; i > m; i--) {
        fillhelper(depth, i);
        mask[i] ^= (1 << depth);
    }
    fillDAT(depth + 1, l, m);
    fillDAT(depth + 1, m + 1, r);
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    fillDAT(0, 0, N - 1);
    while (Q--) {
        int l, r; cin >> l >> r;
        cout <<
    }

    return 0;
}
