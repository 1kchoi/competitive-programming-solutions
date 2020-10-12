// Now I am become Death, the destroyer of worlds.
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <cassert>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <utility>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <complex>
#include <climits>
#include <fstream>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX 255
#define IDMAX (int)(1e6+5)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef struct{
    int id;
    int area;
    vi neighbors;
} node;

int n;
int g[NMAX][NMAX];
int solo, duo, highestID;
bool discovered[NMAX][NMAX];
int fillsize;
int dr[] = {0,1,0,-1}; //right down left up
int dc[] = {1,0,-1,0};
vector<node> graph;
set<int> dfsneighbors;

void printGrid() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printGraph() {
    for (int i = 0; i < graph.size(); i++) {
        cout << graph[i].id << " " << graph[i].area << " |";
        for (int j = 0; j < graph[i].neighbors.size(); j++) {
            cout << " " << graph[i].neighbors[j];
        }
        cout << endl;
    }
}

void dfs1(int r, int c, int color) {
    fillsize++;
    discovered[r][c] = 1;
    for (int i = 0; i < 4; i++) {
        int newr = r+dr[i], newc = c+dc[i];
        int newcolor = g[newr][newc];
        if (newr >= 0 && newc >= 0 && newr < n && newc < n) {
            if (newcolor == color) {
                if (!discovered[newr][newc]) {
                    dfs1(newr, newc,color);
                }
            }
            else {
                dfsneighbors.insert(newcolor);
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            highestID = max(highestID, g[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!discovered[i][j]) {
                fillsize = 0;
                dfsneighbors.clear();
                dfs1(i,j,g[i][j]);
                node newnode;
                newnode.id = g[i][j];
                newnode.area = fillsize;
                newnode.neighbors.assign(dfsneighbors.begin(), dfsneighbors.end());
                graph.PB(newnode);
                solo = max(solo, fillsize);
            }
        }
    }
    cout << solo << endl;

    printGrid();
    printGraph();


    return 0;
}
