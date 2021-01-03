// CSES Problem Set - Path Queries
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(4e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

template<class T> struct BIT {
    int N;
    T A[NMAX];
    void init(int _N) { N = _N; }
    T sum(int k) {
        T s = 0;
        while (k >= 1) {
            s += A[k];
            k -= k & -k;
        }
        return s;
    }
    T query(int a, int b) {
        return (a>b) ? query(b, a) : sum(b) - sum(a - 1);
    }
    void update(int i, T x) {
        T d = x - query(i, i);
        while (i <= N) {
            A[i] += d;
            i += i & -i;
        }
    }
};

ll N, Q, A[NMAX], st[NMAX], en[NMAX], timer = 1;
vi G[NMAX];
BIT<ll> B;

void dfs(int node, int parent) {
    st[node] = timer++;
    for (int v : G[node]) {
        if (v != parent) {
            dfs(v, node);
        }
    }
    en[node] = timer++;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> Q;

    B.init(2 * N + 2);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        G[a].PB(b); G[b].PB(a);
    }
    dfs(1, 0);

    for (int i = 1; i <= N; i++) {
        B.update(st[i], A[i]);
        B.update(en[i], -A[i]);
    }

    while (Q--) {
        int q; cin >> q;
        if (q == 1) { // update
            int s, x; cin >> s >> x;
            B.update(st[s], x);
            B.update(en[s], -x);
        }
        else { // query
            int s; cin >> s;
            cout << B.query(1, st[s]) << endl;
        }
    }

    return 0;
}
