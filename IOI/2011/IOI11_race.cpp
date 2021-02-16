// IOI '11 P2 - Race (Standard I/O)
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
#define NMAX (int)(2e5+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

ll N, K;
vii G[NMAX];
vector<map<ll, ll>> S;

void dfs(ll node, ll parent) {
    for (ii child : G[node]) {
        if (child[0] == parent) continue;
        dfs(child[0], node);
        for ()
    }
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> K;
    for (int i = 0; i < N - 1; i++) {
        ll a, b, x; cin >> a >> b >> x;
        G[a].PB({b, x});
        G[b].PB({a, x});
    }


    return 0;
}
