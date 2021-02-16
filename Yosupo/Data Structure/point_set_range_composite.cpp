// Yosupo - Point Set Range Composite
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(5e5+5)
#define INF 0x3f
#define MOD 998244353
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

template<class T> struct Node {
    T a, b;
    Node(T _a, T _b) {
        a = _a; b = _b;
    }
    T eval(T x) { return (a * x + b) % MOD; }
};

template<class T> struct SegTree {
    vector<Node<T>> A; int n; Node<T> ID = Node<T>(1, 0);
    Node<T> comb(Node<T> x, Node<T> y) { return Node<T>((x.a * y.a) % MOD, (x.b * y.a + y.b) % MOD); }
    void pull(int pos) { A[pos] = comb(A[2 * pos], A[2 * pos + 1]); }
    void init(int _n) { n = _n; A.assign(2 * n, ID); }
    void update(int pos, Node<T> x) {
        A[pos += n] = x;
        for (pos /= 2; pos; pos /= 2) pull(pos);
    }
    Node<T> query(int l, int r) {
        Node<T> lans = ID, rans = ID;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) lans = comb(lans, A[l++]);
            if (r & 1) rans = comb(A[--r], rans);
        }
        return comb(lans, rans);
    }
};

int N, Q;
SegTree<ll> S;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N >> Q;
    S.init(N);
    for (int i = 0; i < N; i++) {
        ll a, b; cin >> a >> b;
        S.update(i, Node<ll>(a, b));
    }
    while (Q--) {
        int type; cin >> type;
        if (!type) { // update
            ll p, c, d; cin >> p >> c >> d;
            S.update(p, Node<ll>(c, d));
        }
        else { // query
            ll l, r, x; cin >> l >> r >> x;
            Node<ll> ans = S.query(l, r);
            cout << S.query(l, r).eval(x) << endl;
        }
    }

    return 0;
}
