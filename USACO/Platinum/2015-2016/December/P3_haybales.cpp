// USACO 2015 December Contest, Platinum
// Problem 3. Counting Haybales
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

struct node {
    ll s, mn, lz;
} S[1 << 19];

void apply(ll x, int i, int l, int r) {
    S[i].s += x * (r - l + 1);
    S[i].mn += x;
    S[i].lz += x;
}

void push(int i, int l, int r) {
    int m = (l + r) / 2;
    apply(S[i].lz, 2 * i, l, m);
    apply(S[i].lz, 2 * i + 1, m + 1, r);
    S[i].lz = 0;
}

void pull(int i) {
    S[i].s = S[2 * i].s + S[2 * i + 1].s;
    S[i].mn = min(S[2 * i].mn, S[2 * i + 1].mn);
}

void update(int l1, int r1, ll x, int i = 1, int l2 = 0, int r2 = N - 1) {
    if (l1 <= l2 && r2 <= r1) {
        apply(x, i, l2, r2);
        return;
    }
    push(i, l2, r2);
    int m2 = (l2 + r2) / 2;
    if (l1 <= m2) {
        update(l1, r1, x, 2 * i, l2, m2);
    }
    if (m2 < r1) {
        update(l1, r1, x, 2 * i + 1, m2 + 1, r2);
    }
    pull(i);
}

ll minquery(int l1, int r1, int i = 1, int l2 = 0, int r2 = N - 1) {
    if (l1 <= l2 && r2 <= r1) {
        return S[i].mn;
    }
    push(i, l2, r2);
    int m2 = (l2 + r2) / 2;
    ll ans = LLONG_MAX;
    if (l1 <= m2) {
        ans = min(ans, minquery(l1, r1, 2 * i, l2, m2));
    }
    if (m2 < r1) {
        ans = min(ans, minquery(l1, r1, 2 * i + 1, m2 + 1, r2));
    }
    assert(ans != LLONG_MAX);
    return ans;
}

ll sumquery(int l1, int r1, int i = 1, int l2 = 0, int r2 = N - 1) {
    if (l1 <= l2 && r2 <= r1) {
        return S[i].s;
    }
    push(i, l2, r2);
    int m2 = (l2 + r2) / 2;
    ll ans = 0;
    if (l1 <= m2) {
        ans += sumquery(l1, r1, 2 * i, l2, m2);
    }
    if (m2 < r1) {
        ans += sumquery(l1, r1, 2 * i + 1, m2 + 1, r2);
    }
    return ans;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO("haybales");

    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        ll x; cin >> x; update(i, i, x);
    }
    while (Q--) {
        char qt; cin >> qt;
        if (qt == 'M') {
            int a, b; cin >> a >> b;
            --a; --b;
            cout << minquery(a, b) << endl;
        }
        else if (qt == 'S') {
            int a, b; cin >> a >> b;
            --a; --b;
            cout << sumquery(a, b) << endl;
        }
        else { // qt == P, update
            int a, b; ll c; cin >> a >> b >> c;
            --a; --b;
            update(a, b, c);
        }
    }

    return 0;
}
