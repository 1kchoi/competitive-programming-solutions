// CSES Problem Set - Message Route
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF 0x3f3f3f
#define MOD (int)(1e9+7)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M;
vi AL[NMAX];
bool discovered[NMAX];
int dist[NMAX];
int parent[NMAX];
queue<int> Q; // v, parent[v]

void printPath(int v) {
    if (v) {
        printPath(parent[v]);
        cout << v << " ";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        AL[a].PB(b);
        AL[b].PB(a);
    }

    Q.push(1);
    discovered[1] = true;
    dist[1] = 1;
    parent[1] = 0;
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (int i = 0; i < sz(AL[v]); i++) {
            int u = AL[v][i];
            if (!discovered[u]) {
                discovered[u] = true;
                dist[u] = dist[v] + 1;
                parent[u] = v;
                Q.push(u);
            }
        }
    }

    if (!discovered[N]) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        cout << dist[N] << endl;
        printPath(N);
        cout << endl;
    }

    return 0;
}
