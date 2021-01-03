// DMOPC '20 Contest 1 P5 - Victor Takes Over Canada
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(5e5+5)
#define LOGNMAX 23
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef tree<ii, null_type, less<ii>, rb_tree_tag,
            tree_order_statistics_node_update> oset;

template<class T> struct RMQ {
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
        if (a > b) return index(b, a);
        int d = level(b - a + 1);
        return comb(S[d][a], S[d][b - (1 << d) + 1]);
    }

    T query(int a, int b) {
        if (a > b) return query(b, a);
        return A[index(a, b)];
    }

    void print() {
        for (T x : A) {
            cout << x << " ";
        }
        cout << endl;
    }

};

template<class T> struct Seg {
    const T ID = 0;
    int n;
    vector<T> S;

    T comb(T a, T b) { return a + b; }
    void pull(int pos) { S[pos] = comb(S[2*pos], S[2*pos+1]); }
    void init(int _n) { n = _n; S.assign(2*n, ID); }
    void update(int pos, T x, bool option = false) { // if option is true, S += x
        pos += n;
        if (option) {
            S[pos] += x;
        }
        else {
            S[pos] = x;
        }
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
    void print() {
        for (int i = n; i < 2 * n; i++) {
            cout << S[i] << " ";
        }
        cout << endl;
    }
};

int N, K, M, C[NMAX], kancestor[NMAX][LOGNMAX];
int euler[2 * NMAX], depth[2 * NMAX], lcast[NMAX], timer1 = 0;
int st[NMAX], en[NMAX], timer2 = 0;
vi G[NMAX];
oset colorlist[NMAX];
Seg<int> S;
RMQ<int> LCA;

void dfs(int node, int parent, int d) {
    euler[timer1] = node;
    depth[timer1] = d;
    lcast[node] = timer1;
    timer1++;

    st[node] = timer2;
    colorlist[C[node]].insert({st[node], node});
    S.update(st[node], 1, true);
    timer2++;

    for (int v : G[node]) {
        if (v != parent) {
            dfs(v, node, d + 1);
            euler[timer1] = node;
            depth[timer1] = d;
            timer1++;
        }
    }

    en[node] = timer2 - 1;
}

void fixS(int c, int val) {
    int index = colorlist[C[c]].order_of_key({st[c], c});
    int clsz = sz(colorlist[C[c]]);

    if (clsz == 2 || (clsz > 2 && (!index || index == clsz - 1))) {
        int other;
        if (clsz == 2) {
            other = (*colorlist[C[c]].find_by_order(1 - index))[1];
        }
        else if (!index) { // left
            other = (*colorlist[C[c]].find_by_order(index + 1))[1];
        }
        else { // right
            other = (*colorlist[C[c]].find_by_order(index - 1))[1];
        }
        int ancestor = euler[LCA.index(lcast[other], lcast[c])];
        S.update(st[ancestor], val, true);
    }
    else if (clsz > 2) {
        int left = (*colorlist[C[c]].find_by_order(index - 1))[1];
        int right = (*colorlist[C[c]].find_by_order(index + 1))[1];
        int lancestor = euler[LCA.index(lcast[left], lcast[c])];
        int rancestor = euler[LCA.index(lcast[right], lcast[c])];
        int bancestor = euler[LCA.index(lcast[left], lcast[right])];
        S.update(st[lancestor], val, true);
        S.update(st[rancestor], val, true);
        S.update(st[bancestor], -val, true);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    memset(kancestor, -INF, sizeof(kancestor));
    cin >> N >> K >> M;
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; --a; --b;
        G[a].PB(b);
        G[b].PB(a);
    }

    S.init(N);

    dfs(0, -1, 0);

    LCA.init(vi(depth, depth + 2 * N - 1));

    for (int i = 1; i <= K; i++) {
        bool flag = true;
        ii prev;
        for (ii cur : colorlist[i]) {
            if (flag) {
                flag = false;
                prev = cur;
                continue;
            }
            int index = LCA.index(lcast[prev[1]], lcast[cur[1]]);
            int ancestor = euler[index];
            S.update(st[ancestor], -1, true);
            prev = cur;
        }
    }

    while (M--) {
        int type; cin >> type;
        if (type == 1) { // update
            int c, k; cin >> c >> k; --c;

            fixS(c, 1);

            colorlist[C[c]].erase({st[c], c});
            C[c] = k;
            colorlist[C[c]].insert({st[c], c});

            fixS(c, -1);
        }
        else { // query
            int u; cin >> u; --u;
            cout << S.query(st[u], en[u]) << endl;
        }
    }

    return 0;
}
