// USACO 2017 February Contest, Gold
// Problem 3. Why Did the Cow Cross the Road III
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
#define NMAX (int)(5e4+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> oset;

int N, A[2 * NMAX], st[NMAX];
ll ans;
oset S;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO("circlecross");

    cin >> N;
    for (int i = 0; i < 2 * N; i++) {
        int x; cin >> x;
        A[i] = x;
        if (!st[x]) st[x] = i;
    }
    for (int i = 0; i < 2 * N; i++) {
        int pos = S.order_of_key({st[A[i]], A[i]});
        if (pos == sz(S)) { // not found
            S.insert({i, A[i]});
        }
        else {
            ans += sz(S) - pos - 1;
            S.erase({st[A[i]], A[i]});
        }
    }
    cout << ans << endl;


    return 0;
}
