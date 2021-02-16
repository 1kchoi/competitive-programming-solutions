// SPOJ - Horrible Queries
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

template<class T> struct BIT {
    int n; vector<T> A; T ID = 0;
    void init(int _n) { n = _n; A.clear(); A.assign(n + 1, ID); }
    void update(int i, T d) { for (; i <= n; i += i & (-i)) A[i] += d; }
    T query(int i) {T x = ID; for (; i; i -= i & (-i)) x += A[i]; return x;}
};

template <class T> struct BITrange {
    int n; BIT<T> A[2]; // 0 is intercept, 1 is slope
    void init(int _n) { n = _n; A[0].init(n); A[1].init(n); }
    void update(int i, T d) { // change [1, i]
        A[1].update(1, d);
        A[1].update(i + 1, -d);
        A[0].update(i + 1, i * d);
    }
    void update(int l, int r, T d) { // change [l, r]
        update(l - 1, -d);
        update(r, d);
    }
    T sum(int i) { return A[1].query(i) * i + A[0].query(i); }
    T sum(int l, int r) { return sum(r) - sum(l - 1); }
};

int T, N, Q;
BITrange<ll> A;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> T;
    while (T--) {
        cin >> N >> Q;
        A.init(N);
        while (Q--) {
            int type; cin >> type;
            if (type) { // query
                int l, r; cin >> l >> r;
                if (l > r) swap(l, r);
                cout << A.sum(l, r) << endl;
            }
            else { // update
                int l, r, x; cin >> l >> r >> x;
                if (l > r) swap(l, r);
                A.update(l, r, x);
            }
        }
    }

    return 0;
}
