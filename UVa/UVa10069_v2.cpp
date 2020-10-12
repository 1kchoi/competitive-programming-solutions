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
#define cin fin
//#define cout fout
using namespace std;
#define ll long long
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
#define XMAX (int)1e4 + 4
#define ZMAX (int)1e2 + 2

ifstream fin("input.txt");
ofstream fout("output.out");

ll N;
string X, Z;
ll xlength, zlength;
ll dp[XMAX][ZMAX];
bool done[XMAX][ZMAX];

ll solve(ll a, ll b) {
    if (!done[a][b]) {
        done[a][b] = true;
        if (b == zlength) {
            dp[a][b] = 1;
        }
        else if (a == xlength) {
            dp[a][b] = 0;
        }
        else {
            ll sum = 0;
            for (ll i = a; i < xlength; i++) {
                if (X.at(i) == Z.at(b)) {
                    sum += solve(i+1, b+1);
                }
            }
            dp[a][b] = sum;
        }
    }
    return dp[a][b];
}

int main() {
    cin >> N;
    cout << "N: " << N << endl;
    while (N--) {
        cin >> X;
        cin >> Z;
        xlength = X.length();
        zlength = Z.length();
        memset(done, false, XMAX*ZMAX);
        cout << solve(0,0) << endl;
    }

    return 0;
}
