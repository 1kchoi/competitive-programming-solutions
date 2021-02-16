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
typedef ar<ll, 2> ii;
typedef ar<ll, 3> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;

ll N, D, dist[2][NMAX], ans[NMAX];
viii G[2]; // [0] is others, [1] is self
queue<ii> Q;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO("piepie");

    memset(dist, -1, sizeof(dist));
    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        ll a, b; cin >> a >> b;
        G[0].PB({b, a, i});
    }
    for (int i = 0; i < N; i++) {
        ll a, b; cin >> a >> b;
        G[1].PB({a, b, i});
    }
    sort(all(G[0]));
    sort(all(G[1]));
    for (int a = 0; a < 2; a++) {
        for (int i = 0; i < N; i++) {
            if (!G[a][i][0]) {
                Q.push({a, i});
                dist[a][i] = 1;
            }
        }
    }


    while (sz(Q)) {
        ii info = Q.front(); Q.pop();
        ll player = info[0], pos = info[1];
        ll self = G[player][pos][1];
        iii ltarget = {self - D, -(ll)(1e12), -(ll)(1e12)};
        iii rtarget = {self, (ll)(1e12), (ll)(1e12)};
        viii::iterator l = lower_bound(all(G[!player]), ltarget);
        viii::iterator r = upper_bound(all(G[!player]), rtarget); // fix with b search
        for (viii::iterator it = l; it != r; it++) {
            int i = it - G[!player].begin();
            if (dist[!player][i] >= 0) continue;
            dist[!player][i] = dist[player][pos] + 1;
            Q.push({!player, i});
        }
    }

    for (int i = 0; i < N; i++) {
        ans[G[0][i][2]] = dist[0][i];
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
