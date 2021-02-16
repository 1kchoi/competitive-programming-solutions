// USACO 2020 January Contest, Silver
// Problem 1. Berry Picking
#include <bits/stdc++.h>
using namespace std;
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

int N, K, M, ans;
vi A;

bool customSort(int x, int y) {
    return x % M < y % M;
}

void solve() {
    sort(all(A));
    int fullbaskets = 0;
    for (int x : A) {
        fullbaskets += x / M;
    }
    if (fullbaskets < K / 2) return;
    if (fullbaskets >= K) {
        ans = max(ans, M * K / 2);
        return;
    }
    int bessiebaskets = fullbaskets - K / 2;
    int bessieberries = M * bessiebaskets;
    sort(all(A), customSort);
    reverse(all(A));
    for (int i = 0; i < N && bessiebaskets < K / 2; i++, bessiebaskets++) {
        bessieberries += A[i] % M;
    }
    ans = max(ans, bessieberries);
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO("berries");

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int x; cin >> x; A.PB(x);
    }
    for (M = 1; M <= 1000; M++) {
        solve();
    }
    cout << ans << endl;

    return 0;
}
