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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("input.txt");
ofstream fout("output.out");

int sum;

int main() {
    sum = 0;
    for (int i = 1; i < 1000; i++) {
        if (i%3==0 || i%5==0) {
            sum+=i;
        }
    }
    cout << sum << endl;

    return 0;
}
