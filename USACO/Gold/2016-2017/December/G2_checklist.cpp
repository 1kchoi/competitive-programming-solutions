// USACO 2016 December Contest, Gold
//Problem 2. Cow Checklist
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define NMAX (int)(1e3+5)
#define INF (INT_MAX/2)
#define HH true
#define GG false
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int H, G, dp[NMAX][NMAX][2];
vii hpos, gpos;

int dist(ii p1, ii p2) {
    int dx = p1.first-p2.first;
    int dy = p1.second-p2.second;
    return dx*dx + dy*dy;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> H >> G;
    for (int i = 0; i < H; i++) {
        int a,b; cin >> a >> b;
        hpos.PB(ii(a,b));
    }
    for (int i = 0; i < G; i++) {
        int a,b; cin >> a >> b;
        gpos.PB(ii(a,b));
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 0; j <= G; j++) {
            for (int k = 0; k < 2; k++) {
                //if (i == 1 && j == 0) continue;
                if (k == GG && j == 0) continue;
                if (k == HH && i == 1) continue;

                if (k == GG) {
                    dp[i][j][GG] = min( dp[i-1][j][GG] + dist(gpos[i-2], gpos[i-1]) ,
                                        dp[i][j-1][HH] + dist(hpos[i-1], gpos[i-1]) );
                }
                else {
                    dp[i][j][HH] = min( dp[i-1][j][GG] + dist(gpos[i-1], hpos[i-1]) ,
                                        dp[i][j-1][HH] + dist(hpos[i-2], hpos[i-1]) );
                }

            }
        }
    }

    cout << dp[H][G][HH] << endl;

    return 0;
}
