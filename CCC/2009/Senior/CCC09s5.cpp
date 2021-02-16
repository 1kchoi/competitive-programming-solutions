// CCC '09 S5 - Wireless
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define KMAX (int)(1e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll M, N, K, A[KMAX][4], ans;
vii B;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> A[i][j];
        }
        B.PB({A[i][0] + A[i][2], A[i][1]});
        B.PB({A[i][0] - A[i][2], A[i][1]});
        B.PB({A[i][0], A[i][1] + A[i][2]});
        B.PB({A[i][0], A[i][1] - A[i][2]});
    }
    for (int i = 0; i < sz(B); i++) {
        ll r = B[i][0], c = B[i][1];
        if (r < 1 || r > N || c < 1 || c > M) continue;
        ll cand = 0;
        for (int j = 0; j < K; j++) {
            ll dr = r - A[j][0];
            ll dc = c - A[j][1];
            if ((dr * dr) + (dc * dc) <= A[j][2] * A[j][2]) {
                cand += A[j][3];
            }
        }
        ans = max(ans, cand);
    }
    cout << ans << endl;

    return 0;
}
