// CSES Problem Set - Subtree Queries
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
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

template<class T> struct Seg {
    const T ID = 0;
    int n;
    vector<T> seg;

    void init(int _n) { n = _n; seg.assign(2 * n, ID); }
    T comb(T a, T b) { return a + b; }
    void pull(int p) { seg[p] = comb(seg[2 * p], seg[2 * p + 1]); }
    void update(int p, T val) {
        seg[p += n] = val;
        for (p /= 2; p; p /= 2) {
            pull(p);
        }
    }
    T query(int l, int r) {
        T ans = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ans = comb(ans, seg[l++]);
            if (r & 1) ans = comb(ans, seg[--r]);
        }
        return ans;
    }
};

ll N, Q, A[NMAX], timer = 0, st[NMAX], en[NMAX];
vi G[NMAX];
Seg<ll> S;

void dfs(int node, int parent) {
    st[node] = timer++;
    for (int x : G[node]) {
        if (x != parent) dfs(x, node);
    }
    en[node] = timer - 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> Q;
    S.init(N + 2);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        G[a].PB(b); G[b].PB(a);
    }
    dfs(1, 0);
    for (int i = 1; i <= N; i++) {
        S.update(st[i], A[i]);
    }

    while (Q--) {
        int t; cin >> t;
        if (t == 1) { // update node s to x
            int s, x; cin >> s >> x;
            S.update(st[s], x);
        }
        else { // query sum of subtree s
            int s; cin >> s;
            cout << S.query(st[s], en[s]) << endl;
        }
    }

    return 0;
}
