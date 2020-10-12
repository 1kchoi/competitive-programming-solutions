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
#define XMAX (int)(1e3+3)
#define NMAX (int)(1e5+3)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, K;
int grid[XMAX][XMAX];
int minx, miny, maxx, maxy;
int ans;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        minx = min(minx, x1);
        miny = min(miny, y1);
        maxx = max(maxx, x2);
        maxy = max(maxy, y2);
        for (int j = y1; j < y2; j++) {
            ++grid[j][x1];
            --grid[j][x2];
        }
    }

    for (int i = miny; i <= maxy; i++) {
        int layer = 0;
        for (int j = minx; j <= maxx; j++) {
            layer += grid[i][j];
            if (layer == K) {
                //cout << "* ";
                ans++;
            }
            else {
                //cout << layer << " ";
            }
        }
        //cout << endl;
    }

    cout << ans << endl;

    return 0;
}
