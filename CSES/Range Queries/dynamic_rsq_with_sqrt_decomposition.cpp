// CSES Problem Set - Dynamic Range Sum Queries
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
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, Q, K, A[NMAX], blocksum[NMAX];

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N >> Q;
    K = (ll)(sqrt(N));
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        blocksum[i / K] += A[i];
    }
    while (Q--) {
        ll type, a, b; cin >> type >> a >> b;
        if (type == 1) { // update
            a--;
            blocksum[a / K] += b - A[a];
            A[a] = b;
        }
        else { // query
            a--; b--;
            ll ablock = a / K;
            ll bblock = b / K;
            ll ans = 0;
            if (ablock == bblock) {
                for (int i = a; i <= b; i++) {
                    ans += A[i];
                }
            }
            else {
                for (int i = a; i < (ablock + 1) * K; i++) {
                    ans += A[i];
                }
                for (int i = ablock + 1; i < bblock; i++) {
                    ans += blocksum[i];
                }
                for (int i = bblock * K; i <= b; i++) {
                    ans += A[i];
                }
            }

            cout << ans << endl;
        }
    }

    return 0;
}
