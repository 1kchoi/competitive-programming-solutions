// UTS Open '21 P4 - Lucky Graph
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(2e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M, edges[NMAX][2], anscount;
vii evenlist;
set<ii> G[NMAX];
vi ans;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

void debugG() {
    for (int i = 1; i <= N; i++) {
        cout << i << ": ";
        for (ii u : G[i]) {
            cout << u[0] << "," << u[1] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> edges[i][0] >> edges[i][1];
        G[edges[i][0]].insert({edges[i][1], i});
        G[edges[i][1]].insert({edges[i][0], i});
    }

    for (int i = 1; i <= N; i++) {
        cout << "entering " << i << endl;
        cout << "size " << sz(G[i]) << endl;
        if (sz(G[i]) % 2 == 0) {
            cout << "in" << endl;
            evenlist.clear();
            for (ii u : G[i]) {
                if (sz(G[u[0]]) % 2 == 0) {
                    evenlist.PB(u);
                }
            }
            int highestodd = (sz(evenlist) - 1) / 2 * 2 + 1;
            if (!sz(evenlist)) highestodd = 0;
            cout << sz(evenlist) << " " << highestodd << endl;
            for (int j = 0; j < highestodd; j++) {
                ans.PB(evenlist[j][1]);
                G[i].erase(evenlist[j]);
                G[evenlist[j][0]].erase({i, evenlist[j][1]});
            }
        }
        cout << endl;
    }

    for (int i = 1; i <= N; i++) {
        if (sz(G[i]) % 2) anscount++;
    }
    cout << anscount << endl;
    cout << sz(ans) << endl;
    sort(all(ans));
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
