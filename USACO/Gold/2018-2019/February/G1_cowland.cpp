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
typedef ar<int, 2> ii;
typedef vector<int> vi;
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
    int N;
    vector<T> A; vector<vi> S;

    T comb(T x, T y) {
        return (A[x] == A[y]) ? min(x, y) : ((A[x] < A[y]) ? x : y);
    }

    int level(int x) {
        return 31 - __builtin_clz(x);
    }

    void init(const vector<T>& _A) {
        A = _A;
        N = sz(A);

        S.PB(vi(N)); iota(all(S[0]), 0);

        for (int i = 1; (1 << i) <= N; i++) {
            S.PB(vi(N - (1 << i) + 1));
            for (int j = 0; j < sz(S[i]); j++) {
                S[i][j] = comb(S[i - 1][j], S[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int index(int a, int b) {
        int d = level(b - a + 1);
        return comb(S[d][a], S[d][b - (1 << d) + 1]);
    }

    T query(int a, int b) {
        return A[index(a, b)];
    }

};

int N, Q, A[NMAX], st[NMAX], en[NMAX], euler[2 * NMAX], depth[2 * NMAX], timer = 0;
vi G[NMAX];
Seg<ll> S;
SparseTable<int> P;

void dfs(int node, int parent, int d) {
    //cout << "entering " << node << endl;
    st[node] = timer;
    euler[timer] = node;
    depth[timer] = d;
    timer++;
    for (int v : G[node]) {
        if (v != parent) {
            dfs(v, node, d + 1);
            en[node] = timer;
            euler[timer] = node;
            depth[timer] = d;
            timer++;
        }
    }
    //cout << "leaving " << node << endl;
}

void setIO(string name = "input") {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    setIO();

    cin >> N >> Q;
    S.init(2 * N + 2);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        --a; --b;
        G[a].PB(b); G[b].PB(a);
    }
    dfs(0, -1, 1);

    P.init(vi(depth, depth + 2 * N + 2));

    for (int i = 0; i < N; i++) {
        S.update(st[i], A[i]);
        S.update(en[i], A[i]);
    }

    for (int i = 0; i < 2 * N; i++) {
        cout << setw(2) << i << " ";
    }
    cout << endl;
    for (int i = 0; i < 2 * N; i++) {
        cout << setw(2) << euler[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 2 * N; i++) {
        cout << setw(2) << depth[i] << " ";
    }
    cout << endl;

    //*
    while (Q--) {
        int q; cin >> q;
        if (q == 1) { // update
            int i; ll v; cin >> i >> v;
            --i;
            S.update(st[i], v);
            S.update(en[i], v);
        }
        else { // query
            int i, j; cin >> i >> j; --i; --j;
            if (st[i] > st[j]) swap(i, j);
            //ll lca = 0;
            //ll ipath = 0;
            //ll jpath = 0;
            ll lca = euler[P.index(st[i], st[j])];
            ll ipath = S.query(0, st[i]);
            ll jpath = S.query(0, st[j]);
            //cout << "hi" << endl;
            cout << ipath << " " << jpath << " " << lca << endl;
            //cout << P.query(st[i], st[j]) << endl;
            //cout << st[i] << " " << st[j] << endl;
            cout << (ipath ^ jpath ^ A[lca]) << endl;
            //cout << P.index(st[i], st[j]) << endl;
        }
    }
    //*/


    return 0;
}
