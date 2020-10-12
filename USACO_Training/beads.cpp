/*
ID: kai.cho1
TASK: beads
LANG: C++
*/
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
#define fout cout
//#define fin cin
#define ll long long;
#define MAXN 355
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("input.txt");
//ofstream fout("output.out");
//ifstream fin("TASK.in");
//ofstream fout("TASK.out");

int N;
int cindex = -1;
string S;
char color[MAXN*2];
int freq[MAXN*2];

int main() {

    fin >> N >> S;
    fout << S << endl;
    for (int i = 0; i < N; i++) {
        if (i == 0 || S.at(i) != color[cindex]) {
            color[++cindex] = S.at(i);
        }
        freq[cindex]++;
    }

    for (int i = 0; i <= cindex; i++) {
        color[cindex+i+1] = color[i];
        freq[cindex+i+1] = freq[i];
    }
    cindex = cindex*2+2;
    for (int i = 0; i < cindex; i++) {
        fout << color[i] << " " << freq[i] << endl;
    }

    return 0;
}
