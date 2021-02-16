// CSES Problem Set - Range Update Queries
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

int N, Q;
struct node {
    ll s, lz;
} S[1 << 19];

void apply(int i, ll x, int l, int r) {
    S[i].s += x * (r - l + 1);
    S[i].lz += x;
}

void push(int i, int l, int r) {
    int m = (l + r) / 2;
    apply(2 * i, S[i].lz, l, m);
    apply(2 * i + 1, S[i].lz, m + 1, r);
    S[i].lz = 0;
}

void pull(int i) {
    S[i].s = S[2 * i].s + S[2 * i + 1].s;
}

void update(int pos, ll x, int i = 1, int l = 0, int r = N - 1) {
    if (l == r) {
        S[i].s = x;
        return;
    }
    push(i, l, r);
    int m = (l + r) / 2;
    if (pos <= m) {
        update(pos, x, 2 * i, l, m);
    }
    else {
        update(pos, x, 2 * i + 1, m + 1, r);
    }
    pull(i);
}

void rangeupdate(int l1, int r1, ll x, int i = 1, int l2 = 0, int r2 = N - 1) {
    if (l1 <= l2 && r2 <= r1) {
        apply(i, x, l2, r2);
        return;
    }
    push(i, l2, r2);
    int m2 = (l2 + r2) / 2;
    if (l1 <= m2) {
        rangeupdate(l1, r1, x, 2 * i, l2, m2);
    }
    if (m2 < r1) {
        rangeupdate(l1, r1, x, 2 * i + 1, m2 + 1, r2);
    }
    pull(i);
}

ll query(int l1, int r1, int i = 1, int l2 = 0, int r2 = N - 1) {
    if (l1 <= l2 && r2 <= r1) {
        return S[i].s;
    }
    push(i, l2, r2);
    int m2 = (l2 + r2) / 2;
    return (l1 <= m2 ? query(l1, r1, 2 * i, l2, m2) : 0) +
            (m2 < r1 ? query(l1, r1, 2 * i + 1, m2 + 1, r2) : 0);
}

void printS() {
    for (int i = 0; i < 2 * N; i++) {
        cout << setw(3) << i;
    }
    cout << endl;
    for (int i = 0; i < 2 * N; i++) {
        cout << setw(3) << S[i].s;
    }
    cout << endl;
    cout << endl;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        ll x; cin >> x;
        update(i, x);
        printS();
    }
    cout << "NOW IT STARTS" << endl;
    while (Q--) {
        int qt; cin >> qt;
        if (qt == 1) { // update
            int a, b; ll x; cin >> a >> b >> x; --a; --b;
            rangeupdate(a, b, x);
        }
        else {
            int i; cin >> i; --i;
            cout << query(i, i) << endl;
        }
    }

    return 0;
}
