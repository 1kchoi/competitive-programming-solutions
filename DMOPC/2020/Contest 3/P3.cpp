// DMOPC '20 Contest 3 P3 - A Ring of Buckets
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

ll Q, N, M, K, B;
ll xi[40], px[40];
// N buckets
// M capacity per bucket
// K capacity in my bucket
// B polynomial constant

ll calculateAns(ll C, ll X, ll Y) {
    memset(xi, 0, sizeof(xi));
    memset(px, 0, sizeof(px));
    xi[0] = px[0] = X % MOD;
    for (int i = 1; (1 << i) <= Y; i++) {
        xi[i] = xi[i - 1] * xi[i - 1];
        xi[i] %= MOD;
        px[i] = px[i - 1] * (xi[i - 1] + 1);
        px[i] %= MOD;
    }

    ll ans = 0;
    for (int i = 0; (1 << i) <= Y; i++) {
        if (Y & (1 << i)) {
            ans *= xi[i]; ans %= MOD;
            ans += px[i]; ans %= MOD;
        }
    }
    ans++; ans %= MOD;
    ans *= C; ans %= MOD;
    return ans;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> Q;
    while (Q--) {
        cin >> N >> M >> K >> B;
        if (M % (K + 2)) {
            if (K == 1 && !(N % 3)) {
                ll C = (((M * B) % MOD) * B) % MOD;
                ll X = (((B * B) % MOD) * B) % MOD;
                ll Y = N / 3 - 1;
                cout << calculateAns(C, X, Y) << endl;
            }
            else {
                cout << -1 << endl;
                continue;
            }
        }
        cout << calculateAns(M / (K + 2), B, N - 1) << endl;
    }

    return 0;
}
