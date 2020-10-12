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
#define NMAX (int)(1e3+5)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N;
bool G[NMAX][NMAX];
bool discovered[NMAX][NMAX];
int dr[] = {0,1,0,-1}; //right down left up
int dc[] = {1,0,-1,0};
int P, A;
int maxP, maxA;

void dfs(int r, int c) {
    //cout << r << " " << c << endl;
    A++;
    P += 4;
    discovered[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int nr = r+dr[i];
        int nc = c+dc[i];
        if(nr >= 0 && nc >= 0 && nr < N && nc < N && G[nr][nc]) {
            --P;
            if (!discovered[nr][nc]) {
                dfs(nr,nc);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < N; ++j) {
            G[i][j] = s.at(j)=='#';
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!discovered[i][j] && G[i][j]) {
                //cout << "dfs: " << i << " " << j << endl;
                P = A = 0;
                dfs(i,j);
                //cout << "results: " << A << " " << P << endl;
                if (A > maxA) {
                    maxA = A;
                    maxP = P;
                    //cout << "update: " << maxA << " " << maxP << endl;
                }
                else if (A == maxA) {
                    if (P < maxP) {
                        maxP = P;
                        //cout << "update: " << maxA << " " << maxP << endl;
                    }
                }
            }
        }
    }

    cout << maxA << " " << maxP << endl;

    return 0;
}
