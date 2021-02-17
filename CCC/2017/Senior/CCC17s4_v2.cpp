// CCC '17 S4 - Minimum Cost Flow
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
#define MMAX (int)(2e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

struct DSU {
    vi e; void init(int N) { e = vi(N, -1); }
    int get(int x) { return (e[x] < 0) ? x : e[x] = get(e[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {
        x = get(x), y = get(y); if (x == y) return 0;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x; return 1;
    }
};

ll N, M, D, E[MMAX][32], ans, wl;
bool inMST[MMAX];
bool largestinoriginal;
vii EL;
DSU S;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> M >> D;
    S.init(N + 1);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> E[i][j];
        }
        EL.PB({E[i][2], i});
    }
    sort(all(EL));
    for (ii e : EL) {
        ll i = e[1];
        if (S.unite(E[i][0], E[i][1])) {
            inMST[i] = true;
            wl = e[0];
            largestinoriginal = (i < N - 1);
        }
    }
    for (int i = 0; i < N - 1; i++) {
        if (!inMST[i]) {
            ans++;
        }
    }
    if (largestinoriginal) {
        cout << ans << endl;
        return 0;
    }
    S.init(N + 1);
    for (ii e : EL) {
        ll w = e[0], i = e[1];
        if (!S.sameSet(E[i][0], E[i][1])) {
            if (w < wl || (w == wl && i < N - 1)) {
                S.unite(E[i][0], E[i][1]);
            }
            else if (i < N - 1 && w > wl && w <= D) {
                cout << ans - 1 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
