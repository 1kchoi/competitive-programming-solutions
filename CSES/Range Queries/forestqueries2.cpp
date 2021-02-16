// CSES Problem Set - Forest Queries II
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int N, Q, bit[NMAX][NMAX];

void update(int r, int c, int d) {
    for (int i = r; i <= N; i += (i & (-i))) {
        for (int j = c; j <= N; j += (j & (-j))) {
            bit[i][j] += d;
        }
    }
}

int query0(int r, int c) {
    int ans = 0;
    for (int i = r; i; i -= (i & (-i))) {
        for (int j = c; j; j -= (j & (-j))) {
            ans += bit[i][j];
        }
    }
    return ans;
}

int query(int r1, int c1, int r2, int c2) {
    return query0(r2, c2) - query0(r1 - 1, c2) - query0(r2, c1 - 1) + query0(r1 - 1, c1 - 1);
}

void printbit() {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            cout << setw(3) << bit[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        string s; cin >> s;
        for (int j = 1; j <= N; j++) {
            if (s[j - 1] == '*') {
                update(i, j, 1);
                //cout << i << " " << j << endl;
                //printbit();
            }
        }
    }

    while (Q--) {
        int type; cin >> type;
        if (type == 1) {
            int i, j; cin >> i >> j;
            update(i, j, query(i, j, i, j) ? -1 : 1);
        }
        else {
            int i1, j1, i2, j2; cin >> i1 >> j1 >> i2 >> j2;
            cout << query(i1, j1, i2, j2) << endl;
        }
    }

    return 0;
}
