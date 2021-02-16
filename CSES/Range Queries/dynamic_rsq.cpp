// CSES Problem Set - Range Sum Queries II
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
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

template<class T> struct Seg {
    const T ID = 0;
    int n;
    vector<T> S;

    T comb(T a, T b) { return a+b; }
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

int N, Q;
Seg<ll> ST;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin >> N >> Q;
    ST.init(N);
    for (int i = 0; i < N; i++) {
        ll a; cin >> a;
        ST.update(i, a);
    }

    for (int i = 0; i < Q; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            ST.update(--b, c);
        }
        else {
            cout << ST.query(--b, --c) << endl;
        }
    }

    return 0;
}
