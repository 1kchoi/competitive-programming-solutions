// CCC '18 S3 - RoboThieves
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define PF push_front
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 105
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M, G[NMAX][NMAX], dist[NMAX][NMAX];
bool cameraView[NMAX][NMAX];
deque<ii> Q;
int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};


void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    memset(dist, -1, sizeof(dist));
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] == 'W') G[i][j] = -1;
            if (s[j] == 'C') G[i][j] = -2;
            if (s[j] == 'R') G[i][j] = 2;
            if (s[j] == 'D') G[i][j] = 3;
            if (s[j] == 'L') G[i][j] = 4;
            if (s[j] == 'U') G[i][j] = 5;
            if (s[j] == 'S') {
                G[i][j] = 1;
                Q.PB({i, j});
                dist[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (G[i][j] == -2) {
                for (int k = j; k < M && G[i][k] != -1; k++) {
                    cameraView[i][k] = 1;
                    if (G[i][k] >= 2) cameraView[i][k] = 0;
                }
                for (int k = j; k >= 0 && G[i][k] != -1; k--) {
                    cameraView[i][k] = 1;
                    if (G[i][k] >= 2) cameraView[i][k] = 0;
                }
                for (int k = i; k < N && G[k][j] != -1; k++) {
                    cameraView[k][j] = 1;
                    if (G[k][j] >= 2) cameraView[k][j] = 0;
                }
                for (int k = i; k >= 0 && G[k][j] != -1; k--) {
                    cameraView[k][j] = 1;
                    if (G[k][j] >= 2) cameraView[k][j] = 0;
                }
            }
        }
    }

    while(sz(Q)) {
        ii node = Q.front(); Q.pop_front();
        int r = node[0], c = node[1];
        if (cameraView[r][c]) continue;
        int force = -1;
        if (G[r][c] >= 2) force = G[r][c] - 2;
        for (int i = 0; i < 4; i++) {
            if (force >= 0 && i != force) continue;
            int r2 = r + dr[i], c2 = c + dc[i];
            if (dist[r2][c2] >= 0 || cameraView[r2][c2] || G[r2][c2] < 0) continue;
            if (!G[r2][c2]) {
                Q.push_back({r2, c2});
                dist[r2][c2] = dist[r][c] + 1;
            }
            else {
                Q.push_front({r2, c2});
                dist[r2][c2] = dist[r][c];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!G[i][j]) cout << dist[i][j] << endl;
        }
    }


    return 0;
}
