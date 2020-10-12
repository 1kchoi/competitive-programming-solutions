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
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define MAXDIM 251

int T, R, C;
char input;
int grid[MAXDIM][MAXDIM];
int dr[4] = {1,0,-1,0};
int dc[4] = {0,1,0,-1};

void bfs1(int r, int c) {
    queue<ii> q;
    q.push(make_pair(r,c));
    while (!q.empty()) {
        ii current = q.front();
        q.pop();
        //cout << current.first << " " << current.second << endl;
        for (int i = 0; i < 4; i++) {
            if (current.first+dr[i] >= 0 && current.first+dr[i] < R && current.second+dc[i] >= 0 && current.second+dc[i] < C) {
                if (grid[current.first+dr[i]][current.second+dc[i]] > grid[current.first][current.second]+1) {
                    grid[current.first+dr[i]][current.second+dc[i]] = grid[current.first][current.second]+1;
                    q.push(make_pair(current.first+dr[i], current.second+dc[i]));
                }
            }
        }
    }
}

void printGrid() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        // input
        scanf("%d %d", &R, &C);
        for (int i = 0; i < R; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < C; j++) {
                if (!s.substr(j,1).compare("0")) grid[i][j] = INT_MAX;
                else grid[i][j] = 0;
            }
        }
        cout << endl;
        //printGrid();

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == 0) bfs1(i,j);
            }
        }
        printGrid();
    }
    return 0;
}
