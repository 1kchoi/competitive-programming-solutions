// Codeforces ####A - NAME
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
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
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
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
    void update(int pos, T x, bool opt = false) {
        if (opt) S[pos += n] += x;
        else S[pos += n] = x;
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

ll N, prefix[NMAX];
Seg<ll> S;
vii A;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO("haircut");

    cin >> N;
    S.init(N + 1);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        S.update(x, 1, true);
        A.PB({x, S.query(x + 1, N)});
    }
    sort(all(A));

    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i - 1] + A[i - 1][1];
    }

    int j = 0; // prefix[j]
    for (int i = 0; i < N; i++) { // ans[i]
        while (j < N && A[j][0] < i) {
            j++;
        }
        cout << prefix[j] << endl;
    }

    return 0;
}
