/*
ID: kai.cho1
TASK: friday
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

//ifstream fin("input.txt");
//ofstream fout("output.out");
ifstream fin("friday.in");
ofstream fout("friday.out");

int N, day;
int freq[7];
int month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

bool isLeapYear(int n) {
    if (n % 400 == 0) return true;
    if (n % 100 == 0) return false;
    if (n % 4 == 0) return true;
    return false;
}

int main() {
    fin >> N;
    day = 5;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 12; j++) {
            //fout << 1900+i << " " << j << " " << day << endl;
            freq[day]++;
            day += month[j];
            if (j == 1 && isLeapYear(1900+i)) day++;
            day %= 7;
        }
    }

    for (int i = 5; i < 12; i++) {
        fout << freq[i%7];
        if (i < 11) fout << " ";
    }
    fout << endl;

    return 0;
}
