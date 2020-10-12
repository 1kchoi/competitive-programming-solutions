// CSES Problem Set - Range Sum Queries II
// Template for Fenwick Tree
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
#define NMAX (int)(1e5+5)
#define INF 0x3f3f3f
#define MOD (int)(1e9+7)
typedef pair<int,int> ii;
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

int N, Q;
ll B[NMAX];
BIT<ll> A;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> Q;
    A.init(N);
    for (int i = 1; i <= N; i++) {
        ll x; cin >> x;
        A.update(i, x);
    }

    for (int i = 0; i < Q; i++) {
        int q; cin >> q;
        if (q == 1) {
            int x; ll y;
            cin >> x >> y;
            A.update(x, y);
        }
        else {
            int x, y;
            cin >> x >> y;
            cout << A.query(x, y) << endl;
        }
    }

    return 0;
}
