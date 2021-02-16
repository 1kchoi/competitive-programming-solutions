// CSES Problem Set - Range Minimum Queries I
// (Better) Template for Sparse Table
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(2e5+5)
#define LOGNMAX 20
#define INF 0x3f3f3f
#define MOD (int)(1e9+7)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

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

int N, Q;
vector<ll> A;
SparseTable<ll> S;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> Q;
    A.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    S.init(A);

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        cout << S.query(a, b) << endl;
    }

    return 0;
}
