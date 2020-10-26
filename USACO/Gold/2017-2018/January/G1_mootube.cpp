// USACO 2018 January Contest, Gold
// Problem 1. MooTube
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
typedef ar<int, 2> ii;
typedef ar<int, 3> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

struct DSU {
    vi e; void init(int n) { e = vi(n, -1); }
    int get(int x) { return (e[x] < 0) ? x : e[x] = get(e[x]); }
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -e[get(x)]; }
    bool unite(int x, int y) {
        x = get(x), y = get(y); if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y]; e[y] = x; return true;
    }
};

int N, Q;
vector<iii> EL, A;
ll ans[NMAX];
DSU S;
// EL: distance, a, b
// A: k, start node, query number

bool mySort(iii a, iii b) {
    return a[0] > b[0];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    cin >> N >> Q;
    S.init(N + 2);

    for (int i = 0; i < N - 1; i++) {
        int a, b, x; cin >> a >> b >> x;
        EL.PB({x, a, b});
    }
    sort(all(EL), mySort);

    for (int i = 0; i < Q; i++) {
        int k, v; cin >> k >> v;
        A.PB({k, v, i});
    }
    sort(all(A), mySort);

    int j = 0;
    for (int i = 0; i < Q; i++) {
        int k = A[i][0];
        while (j < N - 1 && EL[j][0] >= k) {
            S.unite(EL[j][1], EL[j][2]);
            j++;
        }
        ans[A[i][2]] = S.size(A[i][1]) - 1;
    }

    for (int i = 0; i < Q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
