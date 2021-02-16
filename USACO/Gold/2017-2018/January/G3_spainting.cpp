// USACO 2018 January Contest, Gold
// Problem 3. Stamp Painting
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
#define NMAX (int)(1e6+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

ll N, M, K, total = 1, s[NMAX];

//*
void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}
//*/
int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO("spainting");

    cin >> N >> M >> K;
    s[0] = 0;
    for (int i = 1; i < K; i++) {
        s[i] = (s[i - 1] * M + M) % MOD;
        total = total * M % MOD;
    }
    for (int i = K; i <= N; i++) {
        s[i] = (M * s[i - 1] - (M - 1) * s[i - K]);
        s[i] += MOD; s[i] %= MOD;
        total = total * M % MOD;
    }
    cout << (total - (s[N] - s[N - 1]) + MOD) % MOD << endl;

    return 0;
}
