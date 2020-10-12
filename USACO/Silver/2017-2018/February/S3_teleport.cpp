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
#define pb push_back
#define NMAX (int)(1e5+5)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ifstream fin("teleport.in");
ofstream fout("teleport.out");

int N;
ll fullsum, slope, y, peak, x;
vii breakpoints; // x position, change in slope

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a,b,d;
        cin >> a >> b;
        d = abs(a-b);
        fullsum += d;
        if (abs(a) < d) {
            breakpoints.pb(ii(b+abs(a)-d, 1)); // left
            breakpoints.pb(ii(b, -2)); // mid
            breakpoints.pb(ii(b-abs(a)+d, 1)); // right
        }
    }
    peak = 0;
    if (!breakpoints.empty()) {
        sort (breakpoints.begin(),breakpoints.end());
        y = 0;
        x = breakpoints[0].first;
        slope = breakpoints[0].second;
        for (int i = 1; i < breakpoints.size(); i++) {
            //cout << x << " " << y << " " << slope << endl;
            int x2 = breakpoints[i].first;
            y += (x2-x)*slope;
            x = x2;
            slope += breakpoints[i].second;
            //if (y > peak) cout << "new peak of " << y << " at " << x << endl;
            peak = max(peak, y);
        }
    }
    cout << fullsum-peak << endl;


    return 0;
}
