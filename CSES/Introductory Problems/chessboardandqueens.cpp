// CSES Problem Set - Chessboard and Queens
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int G[8][8], row[8];
ll ans;

bool isSafe(int r, int c) {
    for (int i = 0; i < r; i++) {
        if (row[i] == c) return false;
        if (i + row[i] == r + c) return false;
        if (i - row[i] == r - c) return false;
    }
    return true;
}

void solve(int x) {
    if (x == 8) {
        ans++;
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (isSafe(x, i) && G[x][i] != -1) {
            row[x] = i;
            solve(x + 1);
            row[x] = -1;
        }
    }
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    memset(row, -1, sizeof(row));
    for (int i = 0; i < 8; i++) {
        string s; cin >> s;
        for (int j = 0; j < 8; j++) {
            if (s[j] == '*') {
                G[i][j] = -1;
            }
        }
    }
    solve(0);
    cout << ans << endl;

    return 0;
}
