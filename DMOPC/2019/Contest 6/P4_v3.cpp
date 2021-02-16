// DMOPC '19 Contest 6 P4 - Grade 12 Math
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int N, Q, o = (int)(5e5+5), A[NMAX];
oset S[2 * NMAX];

void update(int i, int d) {
    S[A[i]].erase(i);
    A[i] += d;
    S[A[i]].insert(i);
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        S[o].insert(i);
        A[i] = o;
    }
    while (Q--) {
        int type; cin >> type;
        if (type == 1) {
            int i; cin >> i;
            update(i, 1);
        }
        if (type == 2) {
            int i; cin >> i;
            update(i, -1);
        }
        if (type == 3) {
            int l, r, c; cin >> l >> r >> c; c += o;
            cout << S[c].order_of_key(r + 1) - S[c].order_of_key(l) << endl;
        }
    }

    return 0;
}
