// CCC '07 S3 - Friends
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
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, a, b, dist[NMAX];
bool discovered[NMAX];
vi G[NMAX];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        G[a].PB(b);
    }

    while (cin >> a >> b, a && b) {
        queue<int> Q;
        memset(dist, 0, sizeof(dist));
        memset(discovered, 0, sizeof(discovered));
        Q.push(a);
        bool flag = true;
        while (Q.size() && flag) {
            int v = Q.front(); Q.pop();
            for (int i = 0; i < sz(G[v]); i++) {
                int u = G[v][i];
                if (!discovered[u]) {
                    discovered[u] = true;
                    Q.push(u);
                    dist[u] = dist[v] + 1;
                    if (u == b) {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (discovered[b]) {
            cout << "Yes " << dist[b] - 1 << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

    return 0;
}
