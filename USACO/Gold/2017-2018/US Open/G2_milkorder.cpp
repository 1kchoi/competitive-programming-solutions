// USACO 2018 US Open Contest, Gold
// Problem 2. Milking Order
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(1e5+5)
#define MMAX (int)(5e4+5)
#define INF (INT_MAX/2)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M, X;
vi observations[MMAX];
vi G[NMAX];
int state[NMAX]; // unvisited, visited, completed
int indegree[NMAX];
vi topo;
bool FLAG;
priority_queue<int, vi, greater<int> > Q;

void resetG() {
    for (int i = 0; i < N; i++) {
        G[i].clear();
    }
}

void dfs(int v) {
    if (FLAG) {
        state[v] = 1; // visited
        for (int i = 0; i < G[v].size(); i++) {
            int u = G[v][i];
            if (state[u] == 0) { // unvisited
                dfs(u);
            }
            else if (state[u] == 1) { // visited
                FLAG = false;
                return;
            }
            // else completed, do nothing
        }
        state[v] = 2; // completed
    }
}

bool check(int a, bool mode) {
    FLAG = true;
    resetG();
    memset(state,0,sizeof(state));
    memset(indegree,0,sizeof(indegree));

    for (int i = 0; i < a; i++) {
        for (int j = 1; j < observations[i].size(); j++) {
            G[observations[i][j-1]].PB(observations[i][j]);
            indegree[observations[i][j]]++;
        }
    }

    if (!mode) {
        for (int i = 0; i < N && FLAG; i++) {
            if (state[i] == 0) {
                dfs(i);
            }
        }
    }
    else {
        for (int i = 0; i < N; i++) {
            if (!indegree[i]) {
                Q.push(i);
            }
        }

        while (!Q.empty()) {
            int v = Q.top(); Q.pop();
            topo.PB(v);
            for (int i = 0; i < G[v].size(); i++) {
                int u = G[v][i];
                if (--indegree[u] == 0) {
                    Q.push(u);
                }
            }
            G[v].clear();
        }
        for (int i = 0; i < topo.size(); i++) {
            cout << topo[i]+1;
            if (i < topo.size()-1) cout << " ";
        }
        cout << endl;
    }
    return FLAG;

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x; cin >> x;
        for (int j = 0; j < x; j++) {
            int a; cin >> a; --a;
            observations[i].PB(a);
        }
    }

    int L = 1, R = M;
    while (L <= R) {
        int mid = L + (R-L)/2;
        if (check(mid, 0)) {
            X = mid;
            L = mid+1;
        }
        else {
            R = mid-1;
        }
    }
    check(X,1);

    return 0;
}
