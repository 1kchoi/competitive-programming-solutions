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
#define cout fout
#define cin fin
#define endl "\n"
#define ll long long
#define PB push_back
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("moobuzz.in");
ofstream fout("moobuzz.out");

int N;
int extra[] = {1,2,4,7,8,11,13,14};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    cout << ((N-1)/8*15) + extra[(N-1)%8] << endl;

    return 0;
}
