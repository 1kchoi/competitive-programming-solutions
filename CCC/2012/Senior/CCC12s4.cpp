// CCC '12 S4 - A Coin Game
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF INT_MAX/2
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef ar<int, 8> i8;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef ar<vi, 8> lineup;

int N;
lineup startnode, optimal;
map<lineup, int> dist;
queue<lineup> Q;

void initialize() {
    for (int i = 0; i < 8; i++) {
        startnode[i].clear();
        optimal[i].clear();
    }
    Q = queue<lineup>();
    dist.clear();
}

void processCandidate(lineup v, int i, int d) {
    if (v[i].back() < v[i + d].back()) {
        lineup newS = v;
        newS[i + d].PB(newS[i].back());
        newS[i].pop_back();
        if (!dist.count(newS)) {
            dist[newS] = dist[v] + 1;
            Q.push(newS);
        }
    }
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    while (cin >> N, N > 0) {
        initialize();

        for (int i = 0; i < N; i++) {
            int a; cin >> a; a--;
            startnode[i].PB(INF);
            startnode[i].PB(a);
            optimal[i].PB(INF);
            optimal[i].PB(i);
        }

        dist[startnode] = 0;
        Q.push(startnode);

        bool found = false;
        while (Q.size() && !found) {
            lineup v = Q.front(); Q.pop();
            for (int i = 0; i < N && !found; i++) {
                if (i >= 1) {
                    processCandidate(v, i, -1);
                }
                if (i + 1 < N) {
                    processCandidate(v, i, 1);
                }
                if (dist.count(optimal)) {
                    cout << dist[optimal] << endl;
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "IMPOSSIBLE" << endl;
        }
    }

    return 0;
}
