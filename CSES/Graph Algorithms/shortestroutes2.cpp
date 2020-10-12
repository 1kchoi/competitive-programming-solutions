// CSES Problem Set - Shortest Routes II
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX 503
#define INF 0x3f3f3f
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M, Q;
ll G[NMAX][NMAX];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> M >> Q;
    memset(G, INF, sizeof(G));
    for (int i = 0; i < M; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        G[a][b] = G[b][a] = min(G[a][b], c);
    }

    for (int i = 1; i <= N; i++) {
        G[i][i] = 0;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        int a,b;
        cin >> a >> b;
        if (G[a][b] == G[0][0]) {
            cout << -1 << endl;
        }
        else cout << G[a][b] << endl;
    }

    return 0;
}
