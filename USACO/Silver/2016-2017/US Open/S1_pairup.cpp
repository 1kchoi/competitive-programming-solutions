// USACO 2017 US Open Contest, Silver
// Problem 1. Paired Up
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

ll N, ans;
vii A;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO("pairup");

    cin >> N;
    for (int i = 0; i < N; i++) {
        ll x, y; cin >> x >> y;
        A.PB({y, x});
    }
    sort(all(A));

    int l = 0, r = N - 1;
    while (l <= r) {
        if (A[l][1] > A[r][1]) {
            A[l][1] -= A[r][1];
            A[r][1] = 0;
            ans = max(ans, A[l][0] + A[r][0]);
            r--;
        }
        else if (A[l][1] < A[r][1]) {
            A[r][1] -= A[l][1];
            A[l][1] = 0;
            ans = max(ans, A[l][0] + A[r][0]);
            l++;
        }
        else { // equal
            A[r][1] = A[l][1] = 0;
            ans = max(ans, A[l][0] + A[r][0]);
            l++; r--;
        }
    }
    cout << ans << endl;

    return 0;
}
