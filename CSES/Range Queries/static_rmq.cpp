// CSES Problem Set - Range Minimum Queries I
// Template for Sparse Table
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
    T A[NMAX], S[LOGNMAX][NMAX];

    T comb(T x, T y) { return min(x, y); }

    void init(int _N, T *_A) {
        N = _N;
        for (int i = 0; i < _N; i++) {
            A[i] = S[0][i] = _A[i];
        }
        for (int i = 1; (1 << i) <= N; i++) {
            for (int j = 0; j + (1 << i) - 1 < N; j++) {
                S[i][j] = comb(S[i - 1][j], S[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T query(int a, int b) {
        int level = (int)floor(log((double)(b - a + 1)) / log(2.0));
        return comb(S[level][a], S[level][b - (1 << level) + 1]);
    }

};

int N, Q;
ll A[NMAX];
SparseTable<ll> S;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    S.init(N, A);

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        cout << S.query(a, b) << endl;
    }

    return 0;
}
