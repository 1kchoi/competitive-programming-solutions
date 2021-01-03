// USACO 2019 December Contest, Gold
// Problem 3. Moortal Cowmbat
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define MMAX 27
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

ll N, M, K, dist[MMAX][MMAX], ps[MMAX][NMAX], A[NMAX], dp[NMAX][MMAX], mn[NMAX];
string S;

ll cost(int i, int j, int c) {
    return ps[c][j + 1] - ps[c][i];
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO("cowmbat");

    cin >> N >> M >> K >> S;
    for (int i = 0; i < N; i++) {
        A[i] = S[i] - 'a';
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cin >> dist[i][j];
        }
    }
    for (int k = 0; k < M; k++) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 1; j <= N; j++) {
            ps[i][j] = ps[i][j - 1] + dist[A[j - 1]][i];
        }
    }

    memset(dp, INF, sizeof(dp));
    memset(mn, INF, sizeof(mn));
    mn[0] = 0;
    for (int i = 0; i <= N; i++) {
        for (int c = 0; c < M; c++) {
            if (i + K <= N) {
                dp[i + K][c] = min(dp[i + K][c], mn[i] + cost(i, i + K - 1, c));
                mn[i + K] = min(mn[i + K], dp[i + K][c]);
            }
            if (i + 1 <= N) {
                dp[i + 1][c] = min(dp[i + 1][c], dp[i][c] + cost(i, i, c));
                mn[i + 1] = min(mn[i + 1], dp[i + 1][c]);
            }
        }
    }

    cout << mn[N] << endl;



    return 0;
}
