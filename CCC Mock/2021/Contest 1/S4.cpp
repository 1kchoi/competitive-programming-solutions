// Mock CCC '21 S4 - Infinite Molecule
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(4e4+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, A[NMAX][4];
map<int, set<int>> M;
bool discovered[NMAX], ans;

void dfs(int v, int cur = -99) {
    if (ans) return;
    //cout << "ENTERING " << v << endl;
    discovered[v] = true;
    for (int i = 0; i < 4; i++) {
        //cout << v << " i = " << i << endl;
        if (A[v][i] == cur) continue;
        for (int u : M[-A[v][i]]) {
            //cout << v << " u = " << u << endl;
            if (discovered[u]) {
                //cout << v << " discovered!" << endl;
                if (!(v == u && A[v][i] == 0)) {
                    //cout << v << " FOUND!" << endl;
                    ans = true;
                    return;
                }
            }
            dfs(u, -A[v][i]);
        }
    }
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N;
    for (int i = 0; i < N; i++) {
        int zerocount = 0;
        for (int j = 0; j < 4; j++) {
            cin >> A[i][j];
            if (A[i][j] == 0) zerocount++;
            M[A[i][j]].insert(i);
        }
        if (zerocount >= 2) {
            cout << 1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < N && !ans; i++) {
        if (!discovered[i]) {
            dfs(i);
        }
    }

    cout << ans << endl;


    return 0;
}
