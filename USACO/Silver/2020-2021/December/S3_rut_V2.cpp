// USACO 2020 December Contest, Silver
// Problem 3. Stuck in a Rut
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
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N;
int G[2005][2005];
bool direction[1005];
int location[1005][2];
bool dead[1005];
int killcount[1005];
int timefound[2005][2005];

/*
void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}
//*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0);// setIO();

    cin >> N;
    for (int i = 1; i <= N; i++) {
        char c; int x, y; cin >> c >> x >> y;
        direction[i] = (c == 'N');
        G[x][y] = i;
        timefound[x][y] = 2006;
        location[i][0] = x;
        location[i][1] = y;
    }

    int timer = 2005;
    while (timer--) {
        for (int i = 1; i <= N; i++) {
            if (dead[i]) continue;
            int x = location[i][0];
            int y = location[i][1];
            int x2 = x, y2 = y;

            if (direction[i]) y2++;
            else x2++;

            if (y2 > 2002 || x2 > 2002) {
                dead[i] = true;
                continue;
            }

            int currentcolor = G[x2][y2];

            if (!currentcolor || timefound[x2][y2] == timer) {
                location[i][0] = x2;
                location[i][1] = y2;
                G[x2][y2] = i;
                timefound[x2][y2] = timer;
            }
            else {
                dead[i] = true;
                killcount[currentcolor] += killcount[i] + 1;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << killcount[i] << endl;
    }

    return 0;
}
