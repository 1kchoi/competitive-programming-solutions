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
//#define cout fout
#define cin fin
#define ll long long
#define VMAX 303
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("input.txt");
ofstream fout("output.out");

vvi AL;
int V, a, b;
int color[VMAX];
int edgecount;
bool FLAG;

void initializeAL() {
    AL.clear();
    vi empty;
    for (int i = 0; i < VMAX; i++) {
        AL.push_back(empty);
    }
}

void bipartiteCheck() {
    queue<int> Q;
    int u, v;
    Q.push(1);
    color[1] = 0;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        for (int i = 0; i < AL[u].size(); i++) {
            v = AL[u][i];
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                Q.push(v);
            }
            else if (color[v] == color[u]) {
                FLAG = false;
                cout << "NO" << endl;
                return;
            }
        }
    }
}

int main() {

    while (cin >> V, V != 0) {
        FLAG = true;
        edgecount = 0;
        initializeAL();
        memset(color, -1, sizeof(color));
        while (cin >> a >> b, a != 0) {
            AL[a].push_back(b);
            AL[b].push_back(a);
            edgecount++;
        }
        if (edgecount % 3 == 0) {
            bipartiteCheck();
            if (FLAG) {
                cout << "YES" << endl;
            }
        }
        else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
