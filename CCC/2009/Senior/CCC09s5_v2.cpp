// CCC '09 S5 - Wireless
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(3e4+5)
#define KMAX (int)(1e3+5)
#define MMAX (int)(1e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, M, K, G[NMAX][MMAX], A[KMAX][4], hiscore, numways;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

void printG() {
    cout << "PRINTING G" << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M + 1; j++) {
            cout << setw(3) << G[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> M >> K;
    while (K--) {
        ll i, j, r, x; cin >> j >> i >> r >> x;
        //cout << i << " " << j << " " << r << " " << x << endl;
        for (ll a = i - r; a <= i + r; a++) {
            if (a < 1 || a > N) continue;
            ll di = abs(a - i);
            ll b = floor(sqrt(r * r - di * di));
            G[a][max(j - b, 1LL)] += x;
            G[a][min(j + b, M) + 1] -= x;
        }
    }

    for (int i = 1; i <= N; i++) {
        ll score = 0;
        for (int j = 1; j <= M; j++) {
            score += G[i][j];
            if (score == hiscore) {
                numways++;
            }
            else if (score > hiscore) {
                hiscore = score;
                numways = 1;
            }
        }
    }
    cout << hiscore << endl << numways << endl;

    return 0;
}
