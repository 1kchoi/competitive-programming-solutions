// USACO 2019 February Contest, Gold
// Problem 1. Cow Land
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
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

template<class T> struct Seg {
    const T ID = 0;
    int n;
    vector<T> S;
    T comb(T a, T b) { return a^b; }
    void pull(int pos) { S[pos] = comb(S[2*pos], S[2*pos+1]); }
    void init(int _n) { n = _n; S.assign(2*n, ID); }
    void update(int pos, T x) {
        S[pos += n] = x;
        for (pos /= 2; pos; pos /= 2) pull(pos);
    }
    T query(int l, int r) {
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra, S[l++]);
            if (r&1) rb = comb(rb, S[--r]);
        }
        return comb(ra, rb);
    }
};

template<class T> struct SparseTable {
    int N; vector<T> A; vector<vi> S;
    T comb(T x, T y) {
        return (A[x] == A[y]) ? min(x, y) : ((A[x] < A[y]) ? x : y);
    }
    int level(int x) { return 31 - __builtin_clz(x); }
    void init(const vector<T>& _A) {
        A = _A; N = sz(A); S.PB(vi(N)); iota(all(S[0]), 0);
        for (int i = 1; (1 << i) <= N; i++) {
            S.PB(vi(N - (1 << i) + 1));
            for (int j = 0; j < sz(S[i]); j++)
                S[i][j] = comb(S[i - 1][j], S[i - 1][j + (1 << (i - 1))]);
        }
    }
    int index(int a, int b) {
        int d = level(b - a + 1); return comb(S[d][a], S[d][b - (1 << d) + 1]);
    }
    T query(int a, int b) { return A[index(a, b)]; }
};

ll N, Q, E[NMAX];
ll euler1[2 * NMAX], depth[2 * NMAX], dst[NMAX], timer1 = 0;
ll euler2[2 * NMAX], st[NMAX], en[NMAX], timer2 = 0;
Seg<ll> S;
SparseTable<ll> RMQ;
vi G[NMAX];

void dfs(int node, int parent, int d) {
    euler1[timer1] = node;
    depth[timer1] = d;
    dst[node] = timer1;
    timer1++;

    euler2[timer2] = node;
    st[node] = timer2;
    timer2++;

    for (int x : G[node]) {
        if (x != parent) {
            dfs(x, node, d + 1);
            euler1[timer1] = node;
            depth[timer1] = d;
            timer1++;
        }
    }

    en[node] = timer2;
    timer2++;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO("cowland");

    cin >> N >> Q;
    S.init(2 * N - 1);
    for (int i = 0; i < N; i++) {
        cin >> E[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        --a; --b;
        G[a].PB(b); G[b].PB(a);
    }

    dfs(0, -1, 0);

    RMQ.init(vi(depth, depth + 2 * N - 1));
    for (int i = 0; i < N; i++) {
        S.update(st[i], E[i]);
        S.update(en[i], E[i]);
    }

    while (Q--) {
        int qtype; cin >> qtype;
        if (qtype == 1) { // update
            int i, x; cin >> i >> x; --i;
            S.update(st[i], x);
            S.update(en[i], x);
            E[i] = x;
        }
        else { // query
            int i, j; cin >> i >> j; --i; --j;
            if (st[i] > st[j]) swap(i, j);
            int ipath = S.query(0, st[i]);
            int jpath = S.query(0, st[j]);
            int lca = euler1[RMQ.index(dst[i], dst[j])];
            int ea = E[lca];
            cout << (ipath ^ jpath ^ ea) << endl;
        }
    }

    return 0;
}
