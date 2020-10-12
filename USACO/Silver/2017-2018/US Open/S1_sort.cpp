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

int n, ans;
vii a;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.PB(ii(x,i));
    }
    sort(a.begin(),a.end());

    for (int i = 0; i < n; i++) {
        ans = max(ans,a[i].second-i);
    }

    cout << ans+1 << endl;



    return 0;
}
