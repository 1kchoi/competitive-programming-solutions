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
#define NMAX 1e12
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll n, m, k;
ll l, r, ans;

bool valid(ll x) {
    ll days = 0;
    ll given = 0;
    while (given < n) {
        ll pos = n-given;
        ll block = pos/x;
        if (block < m) {
            ll addedDays = (pos-1)/m + 1;
            days += addedDays;
            given += addedDays*m;
        }
        else {
            ll addedDays = (pos%x)/(block)+1;
            days += addedDays;
            given += addedDays*block;
        }
    }
    return days<=k;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);

    cin >> n >> k >> m;
    l = 1; r = NMAX;

    while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (valid(mid)) {
            l = mid;
        }
        else {
            r = mid-1;
        }
    }
    cout << l << endl;

    return 0;
}
