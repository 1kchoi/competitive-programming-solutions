// CSES Problem Set - Range Update Queries
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
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
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

template<class T> struct Seg {
    const T ID = 0;
    int n;
    vector<T> S;

    T comb(T a, T b) { return a + b; }
    void pull(int pos) { S[pos] = comb(S[2*pos], S[2*pos+1]); }
    void init(int _n) { n = _n; S.assign(2*n, ID); }
    void update(int pos, T x) {
        S[pos += n] += x;
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

int N, Q;
ll A[NMAX];
Seg<ll> delta;

/*
void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N >> Q;
    delta.init(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A[i] += A[i - 1];
    }
    while (Q--) {
        int type; cin >> type;
        if (type == 1) { // update
            ll i, j, d;
            cin >> i >> j >> d;
            delta.update(i, d);
            delta.update(j + 1, -d);
        }
        else { // query
            ll i; cin >> i;
            cout << A[i] - A[i - 1] + delta.query(1, i) << endl;
        }
    }

    return 0;
}
