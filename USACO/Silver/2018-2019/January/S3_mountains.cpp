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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int n;
vii mountains; // (x+y), (x-y)
int t = INT_MAX; // threshold, must be under this to count
int ans;

bool mountainSort(ii x, ii y) {
    // return x < y : ascending
    if (x.first < y.first) return false;
    if (x.first == y.first) {
        return x.second < y.second;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        mountains.PB(ii(a+b,a-b));
    }
    sort (mountains.begin(), mountains.end(), mountainSort);

    for (int i = 0; i < mountains.size(); i++) {
        if (mountains[i].second < t) {
            t = mountains[i].second;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
