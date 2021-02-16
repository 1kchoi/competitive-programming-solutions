// CSES Problem Set - Labyrinth
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M, G[NMAX][NMAX], dist[NMAX][NMAX], parent[NMAX][NMAX], startr, startc, endr, endc;
int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
queue<ii> Q;

void backtrack(int r, int c) {
    int dir = parent[r][c];
    if (dir == -1) return;
    backtrack(r - dr[dir], c - dc[dir]);
    if (dir == 0) cout << "R";
    if (dir == 1) cout << "D";
    if (dir == 2) cout << "L";
    if (dir == 3) cout << "U";
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    memset(dist, -1, sizeof(dist));
    memset(parent, -1, sizeof(dist));
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] == '#') G[i][j] = -1;
            if (s[j] == 'A') {
                G[i][j] = 1;
                startr = i;
                startc = j;
                dist[i][j] = 0;
                parent[i][j] = -1;
                Q.push({i, j});
            }
            if (s[j] == 'B') {
                G[i][j] = 2;
                endr = i;
                endc = j;
            }
        }
    }

    while (sz(Q)) {
        ii node = Q.front(); Q.pop();
        int r = node[0], c = node[1];
        for (int i = 0; i < 4; i++) {
            int r2 = r + dr[i], c2 = c + dc[i];
            if (r2 < 0 || r2 >= N || c2 < 0 || c2 >= M) continue;
            if (G[r2][c2] < 0 || dist[r2][c2] >= 0) continue;
            Q.push({r2, c2});
            dist[r2][c2] = dist[r][c] + 1;
            parent[r2][c2] = i;
        }
    }

    if (dist[endr][endc] < 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << dist[endr][endc] << endl;
    backtrack(endr, endc);
    cout << endl;

    return 0;
}
