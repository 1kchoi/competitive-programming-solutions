// USACO 2017 US Open Contest, Silver
// Problem 3. Where's Bessie?
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
#define NMAX 22
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int N, grid[NMAX][NMAX];

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < N; j++) {
            grid[i][j] = s[j] - 'A';
        }
    }

    for (int sizei = N; sizei >= 1; sizei--) {
        for (int sizej = N; sizei >= 1; sizej--) {
            
        }
    }

    return 0;
}
