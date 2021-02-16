// IOI '14 P2 - Wall
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
    ll x;
    bool type, empty; // 0 = raise, 1 = cut
} S[1 << 21];

void apply(int i, int l, int r, ll x, bool type) {
    cout << "APPLY i=" << i << ", l=" << l << ", r=" << r << ", x=" << x << ", type=" << type << ", S[i].x=" << S[i].x << endl;
    if ((type && S[i].x > x) || (!type && S[i].x < x)) {
        cout << "apply success!" << endl;
        S[i].x = x;
        S[i].type = type;
    }
}

/*
void push(int i, int l, int r) {
    cout << "PUSHING " << i << " " << l << " " << r << endl;
    int m = (l + r) / 2;
    apply(2 * i, l, m, S[i].x, S[i].type);
    apply(2 * i + 1, m + 1, r, S[i].x, S[i].type);
    S[i].x = 0;
    S[i].type = 0;
}
*/

void push(int i, int l, int r) {
    
}

void update(int l1, int r1, ll x, bool type, int i = 1, int l2 = 0, int r2 = N - 1) {
    if (l1 <= l2 && r2 <= r1) {
        cout << "perfect!" << endl;
        push(i, l2, r2);
        apply(i, l2, r2, x, type);
        return;
    }
    push(i, l2, r2);
    int m2 = (l2 + r2) / 2;
    if (l1 <= m2) {
        update(l1, r1, x, type, 2 * i, l2, m2);
    }
    if (m2 < r1) {
        update(l1, r1, x, type, 2 * i + 1, m2 + 1, r2);
    }
}

ll query(int pos, int i = 1, int l = 0, int r = N - 1) {
    if (l == r) return S[i].x;
    push(i, l, r);
    int m = (l + r) / 2;
    if (pos <= m) {
        return query(pos, 2 * i, l, m);
    }
    return query(pos, 2 * i + 1, m + 1, r);
}

void printS() {
    for (int i = 1; i <= 2 * N; i++) {
        cout << setw(7) << i;
    }
    cout << endl;
    for (int i = 1; i <= 2 * N; i++) {
        cout << setw(7) << S[i].x;
    }
    cout << endl;
    for (int i = 1; i <= 2 * N; i++) {
        cout << setw(7) << S[i].type;
    }
    cout << endl << endl;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> Q;

    while (Q--) {
        ll type, l, r, x;
        cin >> type >> l >> r >> x; type--;
        update(l, r, x, type);
        printS();
    }

    for (int i = 0; i < N; i++) {
        cout << query(i) << endl;
    }

    return 0;
}
