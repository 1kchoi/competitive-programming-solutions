// USACO 2015 December Contest, Gold
// Problem 3. Bessie's Dream
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e3+5)
#define INF 0x3f3f3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef ar<int, 4> i4;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M, G[NMAX][NMAX], dist[NMAX][NMAX][2][4], infinity, ans;
int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1}; // up right down left
queue<i4> Q; // row, col, fruit, dir

bool inBounds(int r, int c) {
    return (r >= 1 && r <= N && c >= 1 && c <= M);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);

    memset(dist, INF, sizeof(dist));
    infinity = ans = dist[0][0][0][0];

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> G[i][j];
        }
    }

    dist[1][1][0][0] = 0;
    Q.push({1, 1, 0, 0});
    while (Q.size()) {
        i4 v = Q.front(); Q.pop();
        int r = v[0], c = v[1], dir = v[3];
        bool fruit = v[2];
        int newdist = dist[r][c][fruit][dir] + 1;

        bool blocked = false;
        int rs = r + dr[dir], cs = c + dc[dir];
        if (inBounds(rs, cs)) {
            int slidetile = G[rs][cs];
            if (slidetile == 0 || slidetile == 3) {
                blocked = true;
            }
        }
        else {
            blocked = true;
        }

        for (int i = 0; i < 4; i++) {
            int r2 = r + dr[i], c2 = c + dc[i];
            if (inBounds(r2, c2)) {
                if (G[r][c] != 4 || i == dir || blocked) {
                    if (G[r2][c2] == 1) { // normal
                        if (dist[r2][c2][fruit][i] == infinity) {
                            dist[r2][c2][fruit][i] = newdist;
                            Q.push({r2, c2, fruit, i});
                        }
                    }
                    if (G[r2][c2] == 2) { // fruit
                        if (dist[r2][c2][1][i] == infinity) {
                            dist[r2][c2][1][i] = newdist;
                            Q.push({r2, c2, 1, i});
                        }
                    }
                    if (G[r2][c2] == 3 && fruit && G[r][c] != 4) { // piranhas
                        if (dist[r2][c2][fruit][i] == infinity) {
                            dist[r2][c2][fruit][i] = newdist;
                            Q.push({r2, c2, fruit, i});
                        }
                    }
                    if (G[r2][c2] == 4) {
                        if (dist[r2][c2][0][i] == infinity) {
                            dist[r2][c2][0][i] = newdist;
                            Q.push({r2, c2, 0, i});
                        }
                    }
                }
            }
        }
    }


    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            ans = min(ans, dist[N][M][i][j]);
        }
    }
    if (ans == infinity) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }


    return 0;
}
