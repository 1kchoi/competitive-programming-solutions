// CCC '11 S5 - Switch
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
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
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int N;
int M;
map<int, int> dist;
queue<int> Q;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (x) {
            M |= (1 << i);
        }
    }

    dist[M] = 0;
    Q.push(M);
    while (sz(Q)) {
        ll v = Q.front(); Q.pop();
        for (int i = 0; i < N; i++) {
            if (!(v & (1 << i))) {
                ll u = v | (1 << i);

                int streak = 0;
                for (int j = 0; j <= N; j++) {
                    if (j == N || !(u & (1 << j))) {
                        if (streak >= 4) {
                            for (int k = j - 1; k >= j - streak; k--) {
                                u ^= (1 << k);
                            }
                        }
                        streak = 0;
                    }
                    else {
                        streak++;
                    }
                }

                if (!dist.count(u)) {
                    dist[u] = dist[v] + 1;
                    Q.push(u);
                }
            }
        }
    }

    cout << dist[0] << endl;


    return 0;
}
