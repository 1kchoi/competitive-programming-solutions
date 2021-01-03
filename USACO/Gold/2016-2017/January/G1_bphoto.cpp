// USACO 2017 January Contest, Gold
// Problem 1. Balanced Photo
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
#define NMAX (int)(1e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int N, A[NMAX], L[NMAX], R[NMAX], ans;
oset S;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO("bphoto");

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        S.insert(A[i]);
        L[i] = S.order_of_key(A[i]);
    }
    S.clear();
    for (int i = N - 1; i >= 0; i--) {
        S.insert(A[i]);
        int r = S.order_of_key(A[i]);
        if (max(L[i], r) > 2 * min(L[i], r)) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
