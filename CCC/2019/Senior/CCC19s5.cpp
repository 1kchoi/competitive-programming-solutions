// CCC '19 S5 - Triangle: The Data Structure
// easy 4/15 solution
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
#define NMAX (int)(3e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int N, K, A[2][NMAX][NMAX];
ll ans;

//*
void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}
//*/
int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> A[1][i][j];
            ans += A[1][i][j];
        }
    }
    if (K == 1) {
        cout << ans << endl;
        return 0;
    }
    ans = 0;

    for (int k = 2; k <= K; k++) {
        int p = k % 2;
        memset(A[p], 0, sizeof(A[p]));
        for (int i = 0; i < N + 1 - k; i++) {
            for (int j = 0; j <= i; j++) {
                A[p][i][j] = max({A[1 - p][i][j], A[1 - p][i + 1][j], A[1 - p][i + 1][j + 1]});
                if (k == K) {
                    ans += A[p][i][j];
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
