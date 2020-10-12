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
//#define cin fin
#define ll long long
#define MAXDIM 105
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("input.txt");
ofstream fout("output.out");

int N, M, S, r, c, dir;
string s;
char x;
int grid[MAXDIM][MAXDIM];
bool taken[MAXDIM][MAXDIM];
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1}; // N,E,S,W
string instruction;
int collected;

int main() {

    while (scanf("%d %d %d", &N, &M, &S), N != 0) {
        //printf("%d %d %d\n", N, M , S);
        collected = 0;
        memset(taken, false, sizeof(taken));
        for (int i = 0; i < N; i++) {
            cin >> s;
            for (int j = 0; j < M; j++) {
                x = s.at(j);
                //cout << i << " " << j << " " << x << endl;
                if (x == '.') grid[i][j] = 0;
                else if (x == '*') grid[i][j] = 1;
                else if (x == '#') grid[i][j] = -1;
                else {
                    grid[i][j] = 0;
                    r = i;
                    c = j;
                    //cout << r << " " << c << endl;
                    if (x == 'N') dir = 0;
                    else if (x == 'L') dir = 1;
                    else if (x == 'S') dir = 2;
                    else if (x == 'O') dir = 3;
                    else cout << "uwu?" << r << " " << c << endl;
                }
            }
        }
        cin >> instruction;
        for (int i = 0; i < S; i++) {
            //cout << r << " " << c << " " << dir << endl;
            if (instruction.at(i) == 'D') {
                dir++;
                dir %= 4;
            }
            else if (instruction.at(i) == 'E') {
                dir += 3;
                dir %= 4;
            }
            else if (instruction.at(i) == 'F') {
                if (r+dr[dir] >= 0 && r+dr[dir] < N && c+dc[dir] >= 0 && c+dc[dir] < M && grid[r+dr[dir]][c+dc[dir]] >= 0) {
                    r += dr[dir];
                    c += dc[dir];
                    if (grid[r][c] && !taken[r][c]) {
                        collected++;
                        taken[r][c] = true;
                    }
                }
            }
            else {
                cout << "bruh" << endl;
            }
        }
        cout << collected << endl;
    }

    return 0;
}
