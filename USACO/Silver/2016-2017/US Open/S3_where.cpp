// USACO 2017 US Open Contest, Silver
// Problem 3. Where's Bessie?
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 22
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, grid[NMAX][NMAX], colors[28], ans;
bool found[NMAX][NMAX];
queue<ii> Q;
int dr[4] = {0, 1, 0, -1}, dc[4] = {1, 0, -1, 0};
vector<ar<int, 4>> A;

void floodfill(int a1, int b1, int a2, int b2, int x0, int y0, int col) {
    Q = queue<ii>();
    Q.push({x0, y0});
    while (sz(Q)) {
        ii v = Q.front(); Q.pop();
        int r = v[0], c = v[1];
        found[r][c] = true;
        for (int i = 0; i < 4; i++) {
            int r2 = r + dr[i], c2 = c + dc[i];
            if (r2 < a1 || r2 > a2 || c2 < b1 || c2 > b2) continue;
            if (found[r2][c2] || grid[r2][c2] != col) continue;
            Q.push({r2, c2});
        }
    }
}

bool check(int r1, int c1, int r2, int c2) {
    int colcount = 0;
    memset(found, 0, sizeof(found));
    memset(colors, 0, sizeof(colors));
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            if (found[i][j]) continue;
            if (!colors[grid[i][j]]) colcount++;
            colors[grid[i][j]]++;
            floodfill(r1, c1, r2, c2, i, j, grid[i][j]);
        }
    }
    if (colcount != 2) return false;
    bool found1 = false, found2 = false;
    for (int i = 0; i < 26; i++) {
        if (colors[i] == 1) found1 = true;
        if (colors[i] > 1) found2 = true;
    }
    return found1 && found2;
}

bool PCLtest(int i, int j) { // test if i swallows j
    return (A[i][0] <= A[j][0] && A[i][1] <= A[j][1] && A[i][2] >= A[j][2] && A[i][3] >= A[j][3]);
}

bool maxPCL(int x) {
    for (int i = 0; i < sz(A); i++) {
        if (i == x) continue;
        if (PCLtest(i, x)) return false;
    }
    return true;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO("where");

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < N; j++) {
            grid[i][j] = s[j] - 'A';
        }
    }

    for (int i1 = 0; i1 < N; i1++) {
        for (int j1 = 0; j1 < N; j1++) {
            for (int i2 = i1; i2 < N; i2++) {
                for (int j2 = j1; j2 < N; j2++) {
                    if (check(i1, j1, i2, j2)) {
                        A.PB({i1, j1, i2, j2});
                    }
                }
            }
        }
    }

    for (int i = 0; i < sz(A); i++) {
        if (maxPCL(i)) ans++;
    }
    cout << ans << endl;

    return 0;
}
