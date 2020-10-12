// USACO 2016 December Contest, Gold
// Problem 1. Moocast
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(1e3+5)
#define INF (INT_MAX/2)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, ans, X, dcount;
vii cows;
bool discovered[NMAX];

void dfs(int v) {
    discovered[v] = 1;
    dcount++;
    int x1 = cows[v].first;
    int y1 = cows[v].second;
    for (int i = 0; i < N; i++) {
        if (i != v && !discovered[i]) {
            int x2 = cows[i].first;
            int y2 = cows[i].second;
            if ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) <= X) {
                dfs(i);
            }
        }
    }
}

bool check() {
    memset(discovered,0,sizeof(discovered));
    dcount = 0;
    dfs(0);
    return dcount == N;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a,b; cin >> a >> b;
        cows.PB(ii(a,b));
    }

    int L = 0, R = INF;
    while (L <= R) {
        X = L + (R-L)/2;
        if (check()) {
            ans = X;
            R = X-1;
        }
        else {
            L = X+1;
        }
    }

    cout << ans << endl;

    return 0;
}
