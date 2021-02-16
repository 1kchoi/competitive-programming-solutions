// DMOPC '19 Contest 6 P4 - Grade 12 Math
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
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, Q;
//unordered_map<int, int> S[4 * NMAX];
unordered_map<short int, int> S[2 * NMAX];

void init(int i = 1, int l = 0, int r = N - 1) {
    S[i][0] = r - l + 1;
    int m = (l + r) / 2;
    if (l == r) return;
    init(2 * i, l, m);
    init(2 * i + 1, m + 1, r);
}

int update(int pos, int d, int i = 1, int l = 0, int r = N - 1) {
    if (l == r) {
        int onlyval = S[i].begin()->first;
        S[i].erase(S[i].begin());
        S[i][onlyval + d] = 1;
        return onlyval;
    }
    int m = (l + r) / 2;
    int val = 0;
    if (pos <= m) {
        val = update(pos, d, 2 * i, l, m);
    }
    else {
        val = update(pos, d, 2 * i + 1, m + 1, r);
    }
    S[i][val + d]++;
    if (!S[i].count(val + d)) {
        S[i].erase(val + d);
    }
    S[i][val]--;
    if (!S[i].count(val)) {
        S[i].erase(val);
    }
    return val;
}

int query(int l1, int r1, int val, int i = 1, int l2 = 0, int r2 = N - 1) {
    if (l1 <= l2 && r2 <= r1) {
        if (S[i].count(val)) return S[i][val];
        return 0;
    }
    int m2 = (l2 + r2) / 2;
    int ans = 0;
    if (l1 <= m2) {
        ans += query(l1, r1, val, 2 * i, l2, m2);
    }
    if (m2 < r1) {
        ans += query(l1, r1, val, 2 * i + 1, m2 + 1, r2);
    }
    return ans;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> Q;
    init();
    while (Q--) {
        int type; cin >> type;
        if (type == 1) {
            int pos; cin >> pos; --pos;
            update(pos, 1);
        }
        if (type == 2) {
            int pos; cin >> pos; --pos;
            update(pos, -1);
        }
        if (type == 3) {
            int l, r, val; cin >> l >> r >> val; --l; --r;
            cout << query(l, r, val) << endl;
        }
    }

    return 0;
}
