// CCC '13 S4 - Who is Taller?
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#define MAXVALUE 1000005
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef struct {
    vvi edges;
    vi outdegree;
} graph;

int N, M, x, y, p, q;
graph g;
bool discovered[MAXVALUE];
bool FINISHED = false;

void initializeGraph() {
    vi empty;
    for (int i = 0; i <= N+5; i++) {
        g.edges.push_back(empty);
        g.outdegree.push_back(0);
    }
}

void dfs(int v, int goal) {
    discovered[v] = true;
    if (v == goal) {
        FINISHED = true;
    }
    if (FINISHED) return;
    else {
        for (int i = 0; i < g.outdegree[v]; i++) {
            int nextNode = g.edges[v][i];
            if (!discovered[nextNode]) {
                dfs(nextNode,goal);
            }
        }
    }
}

int main() {
    cin >> N >> M;
    initializeGraph();
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        g.edges[y].push_back(x);
        g.outdegree[y]++;
    }
    cin >> p >> q;
    dfs(q, p);
    if (FINISHED) {
        cout << "yes" << endl;
    }
    else {
        memset(discovered, false, sizeof(discovered));
        dfs(p, q);
        if (FINISHED) {
            cout << "no" << endl;
        }
        else {
            cout << "unknown" << endl;
        }
    }

    return 0;
}
