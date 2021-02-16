// CCC '20 S2 - Escape Room
#include <vector>
#include <iostream>
using namespace std;

const int NMAX = (int)(4e3+5);
vector<int> G[NMAX * NMAX];
bool discovered[NMAX * NMAX];

void dfs(int x) {
    discovered[x] = 1;
    for (int child : G[x]) {
        if (discovered[child]) continue;
        dfs(child);
    }
}

bool can_escape(int M, int N, vector<vector<int>> v) {
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            G[i * j].push_back(v[i][j]);
        }
    }
    dfs(1);
    return discovered[M * N];
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    int M, N; cin >> M >> N;
    vector<vector<int>> grid(M + 1, vector<int>(N + 1));
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> grid[i][j];
        }
    }

    cout << (can_escape(M, N, grid) ? "yes" : "no") << endl;

    return 0;
}
