// USACO 2017 December Contest, Gold
// Problem 1. A Pie for a Pie
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef ar<int, 3> i3;
typedef vector<int> vi;
typedef vector<i3> vi3;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, D, rawinput[2][NMAX][2], dist[2][NMAX];
vi3 nodes[2]; // nodes[0] (bessie) has {x, y, id}, but nodes[1] (elsie) has {y, x, id};
queue<i3> Q; // {A, x, y} or {B, y, x}


void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    memset(dist, -1, sizeof(dist)); // check if memset -1 works
    cin >> N >> D;
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < N; i++) {
            ii x; cin >> x[0] >> x[1];
            rawinput[k][i][0] = x[0]; rawinput[k][i][1] = x[1];
            nodes[k].PB({x[k], x[1 - k], i});
            if (!x[1 - k]) {
                Q.push({0, x[k], x[1 - k]});
                dist[k][i] = 1;
            }
        }
    }
    sort(all(nodes[0]));
    sort(all(nodes[1]));

    while (Q.size()) {
        i3 v = Q.front(); Q.pop();
        int color = v[0];
        for (vi3::iterator it = lower_bound(all(nodes[1 - color]), {v[1 - color] - D, 0, 0});
                          it != upper_bound(all(nodes[1 - color])), {v[1 - color], 0, 0}); it++) {

        }
    }



    return 0;
}
