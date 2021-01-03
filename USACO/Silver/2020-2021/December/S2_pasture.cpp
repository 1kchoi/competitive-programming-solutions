// USACO 2020 December Contest, Silver
// Problem 2. Rectangular Pasture
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int N;
vii grid;
oset S;
ll ans = 1;

/*
void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}
//*/
int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        grid.PB({x, y});
    }
    sort(all(grid));

    for (int i = 0; i < N; i++) {
        int y = grid[i][1];
        S.clear();
        for (int j = i; j < N; j++) {
            int y2 = grid[j][1];
            S.insert(y2);
            int smaller = S.order_of_key(min(y, y2)) + 1;
            int larger = j - i + 1 - S.order_of_key(max(y, y2));
            ans += smaller * larger;
        }
    }

    cout << ans << endl;


    return 0;
}
