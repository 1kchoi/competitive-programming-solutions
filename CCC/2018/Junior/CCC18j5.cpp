// CCC '18 J5 - Choose your own path
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define MAXPAGES 10009
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef struct {
    vvi edges;
    vi outdegree;
    int nvertices;
} graph;

graph g;
queue<ii> q;
int d[MAXPAGES] = {0};
bool discovered[MAXPAGES] = {false};
bool connected = true;

int N, m, x;
int closestEnd = -1;

void printGraph() {
    for (int i = 1; i <= g.nvertices; i++) {
        printf("%d|", i);
        for (int j = 0; j < g.outdegree[i]; j++) {
            printf("%d ", g.edges[i][j]);
        }
        printf("\n");
    }
}

void bfs() {
    ii u;
    int v, parent, nextNode;
    for (int i = 0; i < g.outdegree[1]; i++) {
        nextNode = g.edges[1][i];
        u.first = nextNode;
        u.second = 1;
        q.push(u);
        discovered[nextNode] = true;
    }
    while (!q.empty()) {
        ii u = q.front(); q.pop();
        v = u.first;
        parent = u.second;
        //cout << v << " " << parent << endl;
        d[v] = d[parent]+1;

        if (g.outdegree[v] == 0) {
            if (closestEnd == -1) closestEnd = d[v];
        }
        else {
            for (int i = 0; i < g.outdegree[v]; i++) {
                nextNode = g.edges[v][i];
                if (!discovered[nextNode]) {
                    u.first = nextNode;
                    u.second = v;
                    q.push(u);
                    discovered[nextNode] = true;
                }
            }
        }
    }
}

int main() {
    vi empty; empty.push_back(-1); // defining empty vi

    // INPUT
    cin >> N;
    g.nvertices = N;
    g.edges.push_back(empty);
    g.outdegree.push_back(1);
    d[1] = 1; discovered[1] = true;
    for (int i = 1; i <= N; i++) {
        cin >> m;
        if (m == 0) {
            g.edges.push_back(empty);
            g.outdegree.push_back(0);
        }
        else {
            g.outdegree.push_back(m);
            vi v;
            for (int j = 0; j < m; j++) {
                cin >> x;
                v.push_back(x);
            }
            g.edges.push_back(v);
        }
    }
    //cout << "-------" << endl;

    bfs();

    for (int i = 1; i <= N; i++) {
        if (d[i] == 0) connected = false;
        //cout << i << "|" << d[i] << endl;
    }

    if (connected) cout << "Y"; else cout << "N";

    cout << endl << closestEnd << endl;


}
