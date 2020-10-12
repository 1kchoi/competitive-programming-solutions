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
#define NMAX (int)(1e5+5)
#define TMAX (int)(1e9+5)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int n,m,c,ans;
vi cows;

bool verify(int x) {
    int buses = 1;
    int capacity = 1;
    int start = cows[0]; // time that the first cow got on
    for (int i = 1; i < cows.size(); i++) {
        if (capacity == c || cows[i] - start > x) { // if capacity is max or distance is too far
            capacity = 0;
            start = cows[i];
            if (++buses > m) return 0;
        }
        capacity++;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);

    cin >> n >> m >> c;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        cows.PB(a);
    }
    sort(cows.begin(),cows.end());

    int lo = 0, hi = TMAX;
    while (lo < hi) {
        int mid = lo + (hi-lo)/2;
        //cout << "------------------------------------------mid: " << mid << endl;
        if (verify(mid)) {
            //cout << "works!\n";
            ans = mid;
            hi = mid;
        }
        else {
            lo = mid+1;
        }
    }

    cout << ans << endl;

    return 0;
}
