// Codeforces ####A - NAME
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

ll N;
bool discovered[1 << 16];

void printNum(ll x) {
    for (int i = N - 1; i >= 0; i--) {
        cout << ((x & (1 << i)) > 0);
    }
    cout << endl;
}

void dfs(ll x) {
    printNum(x);
    discovered[x] = 1;
    for (int i = 0; i < N; i++) {
        int y = x ^ (1 << i);
        if (!discovered[y]) dfs(y);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    dfs(0);

    return 0;
}
