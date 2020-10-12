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
#define MAXN 204
#define ll long long
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("input.txt");
ofstream fout("output.out");

int TC = 0;
int H, W, x;
int grid[MAXN][MAXN];
bool found[MAXN*MAXN];
string input;
char KEY[6] = {'W','A','K','J','S','D'};
vi objects;
vector<char> objects2;

int charToHex(char x) {
    if (x <= '9') return x - '0';
    else return x - 'a' + 10;
}

bool posCheck(int x, int i) {
    if ((x & (1<<i)) != 0) return true;
    return false;
}

void printGrid() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W*4; j++) {
            //cout << grid[i][j];
            if (grid[i][j] == -1) printf(" *");
            else printf("%2d", grid[i][j]);
        }
        cout << endl;
    }
    cout << endl << endl;
}

///*
int floodFill(int r0, int c0, int color, int border) { // BFS
    if (grid[r0][c0] == color || grid[r0][c0] == border) return -69; // throw bad start location

    //cout << "call: " << r0 << " " << c0 << " " << color << " " << border << endl;
    int output = 0;
    queue<ii> q;
    q.push(make_pair(r0, c0));
    grid[r0][c0] = color;
    memset(found, 0, sizeof(found));
    found[1] = 1;

    while (!q.empty()) {
        ii v = q.front();
        q.pop();
        //cout << v.first << " " << v.second << endl;

        if (v.first > 0 && grid[v.first-1][v.second] != color && grid[v.first-1][v.second] != border) { // up
            q.push(make_pair(v.first-1, v.second));
            if (!found[grid[v.first-1][v.second]]) {
                found[grid[v.first-1][v.second]] = 1;
                //cout << "new color: " << grid[v.first-1][v.second] << " " << output+1 << endl;
                output++;
            }
            grid[v.first-1][v.second] = color;
        }
        if (v.first < H-1 && grid[v.first+1][v.second] != color && grid[v.first+1][v.second] != border) { // down
            q.push(make_pair(v.first+1, v.second));
            if (!found[grid[v.first+1][v.second]]) {
                found[grid[v.first+1][v.second]] = 1;
                //cout << "new color: " << grid[v.first+1][v.second] << " " << output+1 << endl;
                output++;
            }
            grid[v.first+1][v.second] = color;
        }
        if (v.second > 0 && grid[v.first][v.second-1] != color && grid[v.first][v.second-1] != border) { // left
            q.push(make_pair(v.first, v.second-1));
            if (!found[grid[v.first][v.second-1]]) {
                found[grid[v.first][v.second-1]] = 1;
                //cout << "new color: " << grid[v.first][v.second-1] << " " << output+1 << endl;
                output++;
            }
            grid[v.first][v.second-1] = color;
        }
        if (v.second < W*4-1 && grid[v.first][v.second+1] != color && grid[v.first][v.second+1] != border) { // right
            q.push(make_pair(v.first, v.second+1));
            if (!found[grid[v.first][v.second+1]]) {
                found[grid[v.first][v.second+1]] = 1;
                //cout << "new color: " << grid[v.first][v.second+1] << " " << output+1 << endl;
                output++;
            }
            grid[v.first][v.second+1] = color;
        }
    }
    return output;
}
//*/

void fillBorder() { // color -1, border 1
    for (int i = 0; i < W*4; i++) {
        floodFill(0,i,-1,1);
        floodFill(H-1,i,-1,1);
    }
    for (int i = 0; i < H; i++) {
        floodFill(i,0,-1,1);
        floodFill(i,W*4-1,-1,1);
    }
}

int main() {

    while (cin >> H >> W, H > 0) {
        TC++;
        objects.clear();
        objects2.clear();
        for (int i = 0; i < H; i++) {
            cin >> input;
            for (int j = 0; j < W; j++) {
                x = charToHex(input.at(j));
                for (int k = 0; k < 4; k++) {
                    grid[i][4*j+k] = posCheck(x, 3-k);
                }
            }
        }

        // FILL BORDER
        fillBorder();

        // FILL HOLES
        int ncolor = 2;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W*4; j++) {
                if (grid[i][j] == 0) {
                    floodFill(i,j,ncolor,1);
                    ncolor++;
                }
            }
        }

        // FILL FULL OBJECTS
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W*4; j++) {
                if (grid[i][j] != -1) {
                    int filler = floodFill(i,j,-1,-1);
                    //cout << "found: " << filler << endl;
                    objects.push_back(filler);
                }
            }
        }

        // TRANSLATE AND PRINT
        for (int i = 0; i < objects.size(); i++) {
            objects2.push_back(KEY[objects[i]]);
        }
        sort(objects2.begin(), objects2.end());
        cout << "Case " << TC << ": ";
        for (int i = 0; i < objects2.size(); i++) {
            cout << objects2[i];
        }
        cout << endl;

    }

    return 0;
}
