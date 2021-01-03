// DMOPC '20 Contest 2 P4 - Hungry Pigeons
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(5e4+5)
#define MMAX (int)(5e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

template<class T> struct SegMin {
    const T ID = INT_MAX;
    int n;
    vector<T> S;

    T comb(T a, T b) { return min(a,b); }
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

template<class T> struct SegMax {
    const T ID = INT_MIN;
    int n;
    vector<T> S;

    T comb(T a, T b) { return max(a,b); }
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

int N, M, B[NMAX];
oset S[NMAX];
SegMin<int> Smin;
SegMax<int> Smax;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    sort(B, B + N);
    Smin.init(N);
    Smax.init(N);
    while (M--) {
        int x; cin >> x;
        
    }

    return 0;
}
