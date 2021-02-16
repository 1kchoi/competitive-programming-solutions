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

int N, Q, A[NMAX];

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> Q;
    while (Q--) {
        int type; cin >> type;
        if (type == 1) {
            int i; cin >> i;
            A[i]++;
        }
        if (type == 2) {
            int i; cin >> i;
            A[i]--;
        }
        if (type == 3) {
            int l, r, val; cin >> l >> r >> val;
            int ans = 0;
            for (int i = l; i <= r; i++) {
                if (A[i] == val) ans++;
            }
            cout << ans << endl;
        }
    }

    return 0;
}
