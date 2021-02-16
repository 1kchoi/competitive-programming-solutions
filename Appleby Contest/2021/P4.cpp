// Appleby Contest '20 P4 - Philosophy Class
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(3e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, M;
vi G[NMAX];
bool inG[NMAX], flag;
set<vi> cycle3;
vi path;

void cycle3check(int start, int node, int parent = -1, int depth = 1) {
    if (flag) return;
    for (int u : G[node]) {
        if (depth == 3) {
            if (u == start) {
                vi candidate({start, node, parent});
                sort(all(candidate));
                cout << 3 << endl;
                for (int x : candidate) {
                    cout << x << " ";
                }
                cout << endl;
                flag = true;
            }
        }
        else {
            if (u != parent) {
                cycle3check(start, u, node, depth + 1);
            }
        }
    }
}

void chain4check(int node, int parent = -1) {
    if (flag) return;
    if (sz(path) == 4) {
        sort(all(path));
        cout << 4 << endl;
        for (int x : path) {
            cout << x << " ";
        }
        cout << endl;
        flag = true;
    }
    for (int u : G[node]) {
        if (u != parent) {
            path.PB(u);
            chain4check(u, node);
            path.pop_back();
        }
    }
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        G[a].PB(b);
        G[b].PB(a);
    }
    for (int i = 1; i <= N; i++) {
        if (sz(G[i])) {
            sort(all(G[i]));
        }
    }

    for (int i = 1; i <= N && !flag; i++) {
        if (sz(G[i])) {
            cycle3check(i, i);
        }
    }

    if (flag) return 0;

    for (int i = 1; i <= N && !flag; i++) {
        if (sz(G[i])) {
            path.PB(i);
            chain4check(i);
            path.clear();
        }
    }

    if (flag) return 0;

    cout << -1 << endl;


    return 0;
}
