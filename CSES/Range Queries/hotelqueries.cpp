// CSES Problem Set - Hotel Queries
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
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
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

template<class T> struct SegTree {
    vector<T> A; int n; int base; T ID = LLONG_MIN;
    void init(int _n) {
        n = _n;
        base = (1 << (sizeof(int) - __builtin_clz(_n - 1)));
        A.assign(2 * base, ID);
    }
    T comb(T x, T y) { return max(x, y); }
    void pull(int pos) { A[pos] = comb(A[2 * pos], A[2 * pos + 1]); }
    void update(int pos, int x) { A[pos += base] = x; for (pos /= 2; pos; pos /= 2) pull(pos); }
    int firstOver(T k) {
        if (k > A[1]) return -1;
        int pos = 1;
        while (pos < base) {
            //cout << pos << endl;
            if (A[2 * pos] >= k) pos *= 2;
            else pos = pos * 2 + 1;
        }
        return (pos - base < n) ? (pos - base) : -1;
    }
    T query(int l, int r) {
        T ans = ID;
        for (l += base, r += base + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) ans = comb(ans, A[l++]);
            if (r & 1) ans = comb(ans, A[--r]);
        }
        return ans;
    }
};

int N, M;
SegTree<ll> S;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N >> M;
    S.init(N);
    for (int i = 0; i < N; i++) {
        ll x; cin >> x;
        S.update(i, x);
    }
    while (M--) {
        ll x; cin >> x;
        //cout << "QUERY" << endl;
        int pos = S.firstOver(x);
        cout << pos + 1 << " ";
        //cout << endl;
        S.update(pos, S.query(pos, pos) - x);
    }
    cout << endl;

    return 0;
}
