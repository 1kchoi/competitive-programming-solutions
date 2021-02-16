// DMOPC '15 Contest 1 P6 - Lelei and Contest
#include <bits/stdc++.h>
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

struct node {
    ll x = 0, lz = 0;
};

ll N, M, Q;
node S[4 * NMAX];

void apply(int i, ll d, int l, int r) {
    S[i].x += d * (r - l + 1);
    S[i].lz += d;
    S[i].x %= M;
    S[i].lz %= M;
}

void push(int i, int l, int r) {
    int m = (l + r) / 2;
    apply(2 * i, S[i].lz, l, m);
    apply(2 * i + 1, S[i].lz, m + 1, r);
    S[i].lz = 0;
}

void pull(int i) {
    S[i].x = S[2 * i].x + S[2 * i + 1].x;
    S[i].x %= M;
}

void pointupdate(int pos, ll d, int i = 1, int l = 0, int r = N - 1) {
    if (l == r) {
        S[i].x += d;
        S[i].x %= M;
        return;
    }
    push(i, l, r);
    int m = (l + r) / 2;
    if (pos <= m) {
        pointupdate(pos, d, 2 * i, l, m);
    }
    else {
        pointupdate(pos, d, 2 * i + 1, m + 1, r);
    }
    pull(i);
}

void rangeupdate(int l1, int r1, ll d, int i = 1, int l2 = 0, int r2 = N - 1) {
    if (l1 <= l2 && r2 <= r1) {
        apply(i, d, l2, r2);
        return;
    }
    push(i, l2, r2);
    int m2 = (l2 + r2) / 2;
    if (l1 <= m2) {
        rangeupdate(l1, r1, d, 2 * i, l2, m2);
    }
    if (m2 < r1) {
        rangeupdate(l1, r1, d, 2 * i + 1, m2 + 1, r2);
    }
    pull(i);
}

ll query(int l1, int r1, int i = 1, int l2 = 0, int r2 = N - 1) {
    if (l1 <= l2 && r2 <= r1) {
        return S[i].x;
    }
    push(i, l2, r2);
    int m2 = (l2 + r2) / 2;
    ll ans = 0;
    if (l1 <= m2) {
        ans += query(l1, r1, 2 * i, l2, m2);
        ans %= M;
    }
    if (m2 < r1) {
        ans += query(l1, r1, 2 * i + 1, m2 + 1, r2);
        ans %= M;
    }
    return ans;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> M >> N >> Q;
    for (int i = 0; i < N; i++) {
        ll x; cin >> x;
        pointupdate(i, x);
    }
    while (Q--) {
        int t; cin >> t;
        if (t == 1) { // update l r x
            ll l, r, x; cin >> l >> r >> x;
            --l; --r;
            rangeupdate(l, r, x);
        }
        else { // query l r
            ll l, r; cin >> l >> r;
            --l; --r;
            cout << query(l, r) << endl;
        }
    }

    return 0;
}
