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
#define NMAX (int)(1e9+5)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N;
bool taken[NMAX];
int ansmin, ansmax;
int l, r, l2, r2;
int window, c;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    l = NMAX; r = 0; window = 0; ansmin = INT_MAX;

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        l = min(l,a);
        r = max(r,a);
        taken[a] = true;
    }

    for (int i = l; i < l+N; i++) {
        window += !taken[i];
    }
    ansmin = min(ansmin, window);
    //cout << "ansmin " << ansmin << endl;

    for (int i = l+N; i <= r; i++) {
        window += (!taken[i] - !taken[i-N]);
        ansmin = min(ansmin, window);
        /*if (window < ansmin) {
            ansmin = window;
            cout << "found: " << i << endl;
        }*/
    }

    cout << ansmin << endl;

    for (int i = l+1; i <= r; i++) {
        if (taken[i]) {
            l2 = i;
            break;
        }
    }
    for (int i = r-1; i >= l; i--) {
        if (taken[i]) {
            r2 = i;
            break;
        }
    }

    //cout << l2 << " " << r2 << endl;

    c = 0;
    for (int i = l2+1; i < r; i++) {
        c += !taken[i];
    }
    ansmax = c;

    c = 0;
    for (int i = r2-1; i > l; i--) {
        c += !taken[i];
    }
    //cout << ansmax << " " << c << endl;
    cout << max(ansmax, c) << endl;


    return 0;
}
