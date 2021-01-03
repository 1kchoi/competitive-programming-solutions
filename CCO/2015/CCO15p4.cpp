// CCO '15 P4 - Cars on Ice
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

int N, M, grid[NMAX][NMAX];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
bool discovered[NMAX][NMAX];
vii G[NMAX][NMAX];
bool degree[NMAX][NMAX];
queue<ii> Q;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] == '.') {
                grid[i][j] = -1;
            }
            if (s[j] == 'N') {
                grid[i][j] = 0;
            }
            if (s[j] == 'E') {
                grid[i][j] = 1;
            }
            if (s[j] == 'S') {
                grid[i][j] = 2;
            }
            if (s[j] == 'W') {
                grid[i][j] = 3;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] >= 0 && !discovered[i][j]) {
                //cout << "triggered " << i << " " << j << endl;
                discovered[i][j] = true;
                int r = i, c = j, d = grid[i][j];
                int lastr = i, lastc = j;
                while (true) {
                    r += dr[d];
                    c += dc[d];
                    if (!(r >= 0 && r < N && c >= 0 && c < M)) break;
                    //cout << "coords " << r << " " << c << endl;
                    if (grid[r][c] >= 0) {
                        if (!discovered[r][c]) {
                            discovered[r][c] = true;
                            d = grid[r][c];
                            G[r][c].PB({lastr, lastc});
                            degree[lastr][lastc] = 1;
                            //cout << lastr << " " << lastc << " is now 1" << endl;
                            lastr = r;
                            lastc = c;
                        }
                        else {
                            G[r][c].PB({lastr, lastc});
                            degree[lastr][lastc] = 1;
                            break;
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] >= 0 && !degree[i][j]) {
                //cout << "pushing " << i << " " << j << endl;
                Q.push({i, j});
            }
        }
    }
    while (sz(Q)) {
        ii v = Q.front(); Q.pop();
        cout << "(" << v[0] << "," << v[1] << ")" << endl;
        for (ii u : G[v[0]][v[1]]) {
            Q.push(u);
        }
    }

    return 0;
}
