// Problem 11 - Largest product in a grid
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

ll N = 20, G[20][20], ans = 0;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> G[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 3; j++) {
            ans = max(ans, G[i][j] * G[i][j+1] * G[i][j+2] * G[i][j+3]);
        }
    }
    for (int i = 0; i < N - 3; i++) {
        for (int j = 0; j < N; j++) {
            ans = max(ans, G[i][j] * G[i+1][j] * G[i+2][j] * G[i+3][j]);
        }
    }
    for (int i = 0; i < N - 3; i++) {
        for (int j = 0; j < N - 3; j++) {
            ans = max(ans, G[i][j] * G[i+1][j+1] * G[i+2][j+2] * G[i+3][j+3]);
        }
    }
    for (int i = 3; i < N; i++) {
        for (int j = 0; j < N - 3; j++) {
            ans = max(ans, G[i][j] * G[i-1][j+1] * G[i-2][j+2] * G[i-3][j+3]);
        }
    }
    cout << ans << endl;

    return 0;
}
