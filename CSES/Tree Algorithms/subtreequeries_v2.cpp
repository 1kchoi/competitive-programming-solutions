// CSES Problem Set - Subtree Queries
// v2, for practice
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
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

template<class T> struct Seg {
    const T ID = 0;
    int n;
    vector<T> seg;
    void init(int _n) {
        n = _n;
        seg = vector<T>(2 * n, ID);
    }
    T comb(T a, T b) {
        return a + b;
    }
    void pull(int p) {
        seg[p] = comb(seg[2 * p], seg[2 * p + 1]);
    }
    void update(int p, T x) {
        seg[p += n] = x;
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

ll N, Q, V[NMAX], timer = 0, st[NMAX], en[NMAX];
vi G[NMAX];
Seg<ll> A;

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
    A.init(N + 2);
    for (int i = 1; i <= N; i++) {
        cin >> V[i];
    }
    for (int i = 0; i < N - 1; i++) {
        ll a, b; cin >> a >> b;
        G[a].PB(b); G[b].PB(a);
    }
    dfs(1, 0);
    for (int i = 1; i <= N; i++) {
        A.update(st[i], V[i]);
    }

    while (Q--) {
        int q; cin >> q;
        if (q == 1) { // update node s to x
            ll s, x; cin >> s >> x;
            A.update(st[s], x);
        }
        else { // query node s
            ll s; cin >> s;
            cout << A.query(st[s], en[s]) << endl;
        }
    }

    return 0;
}
