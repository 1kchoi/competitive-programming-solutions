// USACO 2020 February Contest, Gold
// Problem 1. Timeline
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, M, C, S[NMAX], indegree[NMAX];
vii G[NMAX];
bool discovered[NMAX];
queue<ll> Q;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("timeline.in", "r", stdin);
    freopen("timeline.out", "w", stdout);

    cin >> N >> M >> C;
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
    }
    for (int i = 0; i < C; i++) {
        ll a, b, c; cin >> a >> b >> c;
        G[a].PB({c, b});
        indegree[b]++;
    }
    for (int i = 1; i <= N; i++) {
        if (!indegree[i]) {
            Q.push(i);
        }
    }
    while (Q.size()) {
        ll v = Q.front(); Q.pop();
        discovered[v] = true;
        for (int i = 0; i < sz(G[v]); i++) {
            S[G[v][i][1]] = max(S[G[v][i][1]], S[v] + G[v][i][0]);
            if (!--indegree[G[v][i][1]]) {
                Q.push(G[v][i][1]);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << S[i] << endl;
    }


    return 0;
}
