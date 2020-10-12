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
#define NMAX 1002
#define INF (int)(1e9)
typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("input.txt");
ofstream fout("output.out");

int T, N, M;
int grid[NMAX][NMAX];
priority_queue< iii, vector<iii>, greater<iii> > Q; // <weight, (r,c)>
int dist[NMAX][NMAX];
int dr[4] = {-1,0,1,0};
int dc[4] = {0,-1,0,1}; // up left down right

void initializeDist() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dist[i][j] = INF;
        }
    }
    dist[0][0] = 0;
}

void printDist() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {

    cin >> T;

    while (T--) {
        cin >> N >> M;
        initializeDist();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> grid[i][j];
            }
        }

        Q.push(iii(0, ii(0,0)));
        dist[0][0] = grid[0][0];
        while (!Q.empty()) {
            iii front = Q.top();
            Q.pop();
            int d = front.first;
            ii u = front.second;
            int r = u.first, c = u.second;
            if (d > dist[r][c]) continue;
            for (int i = 0; i < 4; i++) {
                int r2 = r+dr[i], c2 = c+dc[i];
                if (r2 >= 0 && r2 < N && c2 >= 0 && c2 < M) {
                    if (dist[r][c] + grid[r2][c2] < dist[r2][c2]) {
                        dist[r2][c2] = dist[r][c] + grid[r2][c2];
                        Q.push(iii(dist[r2][c2], ii(r2, c2)));
                    }
                }
            }
        }

        cout << dist[N-1][M-1] << endl;

    }

    return 0;
}
