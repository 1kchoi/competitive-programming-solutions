// CCC '14 S5 - Lazy Fox
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(2e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, G[NMAX][NMAX], dist[NMAX][NMAX], mx[NMAX];
vii A;
queue<ii> Q;

int solve(int i, int j) {
    if (dist[i][j] < 0) {
        dist[i][j] = 0;
        if (mx[i] < 0) {
            mx[i] = 0;
            for (int k = 1; k <= N; k++) {
                if (G[k][i] < G[i][j]) {
                    mx[i] = max(mx[i], solve(k, i));
                }
            }
        }
        dist[i][j] = mx[i] + 1;
    }
    return dist[i][j];
}

int solveoriginal(int i, int j) {
    if (dist[i][j] < 0) {
        dist[i][j] = 0;
        for (int k = 1; k <= N; k++) {
            if (G[k][i] < G[i][j]) {
                dist[i][j] = max(dist[i][j], solve(k, i) + 1);
            }
        }
    }
    return dist[i][j];
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N;
    A.PB({0, 0});
    for (int i = 1; i <= N; i++) {
        int x, y; cin >> x >> y;
        A.PB({x, y});
    }
    memset(G, INF, sizeof(G));
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (i == j) continue;
            int dx = A[i][0] - A[j][0];
            int x2 = dx * dx;
            int dy = A[i][1] - A[j][1];
            int y2 = dy * dy;
            G[i][j] = x2 + y2;
        }
    }
    memset(dist, -INF, sizeof(dist));
    memset(mx, -INF, sizeof(mx));

    cout << solve(0, 0) << endl;

    return 0;
}
