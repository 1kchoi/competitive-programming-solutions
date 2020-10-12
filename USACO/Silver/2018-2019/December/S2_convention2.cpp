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
#define A first.first
#define T first.second
#define S second
typedef pair<int,int> ii;
typedef pair<ii,int> iii; // arrival, visit length, seniority
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<iii> viii;

int n, t, endtime, ans, cowindex;
priority_queue<ii, vector<ii>, greater<ii> > q; // seniority, index (cows[i].S, i)
viii cows; // arrival, visit length, seniority
bool FLAG = false;
int waittime[NMAX];


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);

    cin >> n;
    cowindex = 0;

    for (int i = 0; i < n; i++) {
        int a,t;
        cin >> a >> t;
        cows.push_back(iii(ii(a,t),i));
    }
    sort(cows.begin(),cows.end());

    for (int b = 0; b < n; b++) {
        if (q.empty()) {
            t = cows[cowindex].A;
            q.push(ii(cows[cowindex].S,cowindex));
            cowindex++;
        }
        ii xpair = q.top(); q.pop();
        int x = xpair.second; // seniority, **INDEX**
        //cout << "popped from queue: " << x << endl;
        ans = max(ans, t-cows[x].A);
        //waittime[x] = t-cows[x].A;
        t += cows[x].T;
        //cout << "t: " << t << endl;
        for (cowindex; cowindex < n; cowindex++) {
            //cout << "cowindex:" << cowindex << endl;
            if (cows[cowindex].A <= t) {
                q.push(ii(cows[cowindex].S, cowindex));
            }
            else {
                break;
            }
        }
    }

    /*
    cout << "RESULTS:\n";
    for (int i = 0; i < n; i++) {
        cout << i << ": " << waittime[i] << endl;
    }
    //*/

    cout << ans << endl;

    return 0;
}
