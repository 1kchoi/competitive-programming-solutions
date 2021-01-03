// DMOPC '20 Contest 2 P2 - Lousy Christmas Presents
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e6+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int N, M, F[NMAX], L[NMAX], ans = 0;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    memset(F, -INF, sizeof(F));
    memset(L, -INF, sizeof(L));
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (F[x] < 0) {
            F[x] = i;
        }
        L[x] = i;
    }

    while (M--) {
        int i, j; cin >> i >> j;
        if (F[i] < 0 || L[j] < 0) continue;
        ans = max(ans, L[j] - F[i] + 1);
    }
    cout << ans << endl;

    return 0;
}
