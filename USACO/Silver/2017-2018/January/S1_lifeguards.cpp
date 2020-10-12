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
vii states; // (time, cow index)
int timeAlone[NMAX];
set<int> s;
int t;
int totalCovered;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a,b;
        cin >> a >> b;
        states.PB(ii(a,i));
        states.PB(ii(b,i));
    }
    sort(states.begin(),states.end());

    for (int i = 0; i < states.size(); ++i) {
        int cowTime = states[i].first;
        int cowIndex = states[i].second;

        if (s.size() == 1) {
            timeAlone[*s.begin()] += cowTime-t;
        }

        if (s.size() > 0) {
            totalCovered += cowTime-t;
        }

        if (s.find(cowIndex) != s.end()) {
            s.erase(cowIndex);
        }
        else {
            s.insert(cowIndex);
        }

        t = cowTime;
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        ans = min(ans, timeAlone[i]);
    }
    cout << totalCovered-ans << endl;

    return 0;
}
