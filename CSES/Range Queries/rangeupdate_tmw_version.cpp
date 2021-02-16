// CSES Problem Set - Range Update Queries
// William Lin CSES Speedrun Version (I made some changes to make it easier for myself to read, but the implementation is NOT mine!)
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

int N, Q;
ll X[NMAX];

struct node {
    ll mn, s, lz;
} S[1<<19];

void app(int i, ll x, int l2, int r2) {
    S[i].mn += x;
    S[i].s += x * (r2 - l2 + 1);
    S[i].lz += x;
}

void psh(int i, int l2, int r2) {
    int m2 = (l2 + r2) / 2;
    app(2 * i, S[i].lz, l2, m2);
    app(2 * i + 1, S[i].lz, m2 + 1, r2);
    S[i].lz = 0;
}

void pull(int i) {
    S[i].mn = min(S[2 * i].mn, S[2 * i + 1].mn);
    S[i].s = S[2 * i].s + S[2 * i + 1].s;
}

void upd(int l1, ll x, int i = 1, int l2 = 0, int r2 = N - 1) {
    if (l2 == r2) {
        S[i].mn = x;
        S[i].s = x;
        return;
    }
    psh(i, l2, r2);
    int m2 = (l2 + r2) / 2;
    if (l1 <= m2) {
        upd(l1, x, 2 * i, l2, m2);
    }
    else {
        upd(l1, x, 2 * i + 1, m2 + 1, r2);
    }
    pull(i);
}

void upd2(int l1, int r1, ll x, int i = 1, int l2 = 0, int r2 = N - 1) {
    if (l1 <= l2 && r2 <= r1) {
        app(i, x, l2, r2);
        return;
    }
    psh(i, l2, r2);
    int m2 = (l2 + r2) / 2;
    if (l1 <= m2) {
        upd2(l1, r1, x, 2 * i, l2, m2);
    }
    if (m2 < r1) {
        upd2(l1, r1, x, 2 * i + 1, m2 + 1, r2);
    }
    pull(i);
}

ll qry(int l1, int r1, int i = 1, int l2 = 0, int r2 = N - 1) {
    if (l1 <= l2 && r2 <= r1) {
        return S[i].s;
    }
    psh(i, l2, r2);
    int m2 = (l2 + r2) / 2;
    return (l1 <= m2 ? qry(l1, r1, 2 * i, l2, m2) : 0) + (m2 < r1 ? qry(l1, r1, 2 * i + 1, m2 + 1, r2) : 0);
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> X[i], upd(i, X[i]);
    }
    while(Q--) {
        int qt; cin >> qt;
        if (qt == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            --a; --b;
            upd2(a, b, u);
        }
        else {
            int k;
            cin >> k, --k;
            cout << qry(k, k) << endl;
        }
    }

    return 0;
}
