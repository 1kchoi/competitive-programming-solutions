/*
ID: kai.cho1
TASK: gift1
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
//#define fout cout
//#define fin cin
#define ll long long;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("gift1.in");
ofstream fout("gift1.out");

int NP;
string names[12];
int values[12];
string nameinput;
int total, divy;

int nameToNum(string n) {
    for (int i = 0; i < NP; i++) {
        if (n.compare(names[i]) == 0) return i;
    }
    return -1;
}

int main() {
    fin >> NP;

    for (int i = 0; i < NP; i++) {
        fin >> nameinput;
        names[i] = nameinput;
    }

    for (int i = 0; i < NP; i++) {
        fin >> nameinput >> total >> divy;
        if (divy == 0) continue;
        values[nameToNum(nameinput)] -= total / divy * divy;
        for (int j = 0; j < divy; j++) {
            fin >> nameinput;
            values[nameToNum(nameinput)] += total / divy;
        }
    }

    for (int i = 0; i < NP; i++) {
        fout << names[i] << " " << values[i] << endl;
    }

    return 0;
}
