// CCC '18 S3 - RoboThieves
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define PF push_front
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 105
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int N, M, G[NMAX][NMAX], dist[NMAX][NMAX];
deque<ii> Q;
int dr[4] = {}

//*
void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}
//*/
int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    memset(dist, -1, sizeof(dist));
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] == 'W') G[i][j] = -1;
            if (s[j] == 'C') G[i][j] = 2;
            if (s[j] == 'L') G[i][j] = 3;
            if (s[j] == 'R') G[i][j] = 4;
            if (s[j] == 'U') G[i][j] = 5;
            if (s[j] == 'D') G[i][j] = 6;
            if (s[j] == 'S') {
                G[i][j] = 1;
                Q.PB({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while(sz(Q)) {
        ii node = Q.front(); Q.pop_front();
        int r = node[0], c = node[1];
        for ()
    }


    return 0;
}
