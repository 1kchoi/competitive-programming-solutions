// DMOPC '20 Contest 2 P3 - Roadrollification
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
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
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

ll N, A[NMAX], indegree[NMAX], subsum[NMAX], rsubsum[NMAX], presum, ans;
vector<ll> G[NMAX], G2[NMAX];
vii EL;

ll dfs(ll v) {
    if (subsum[v] == 0) {
        subsum[v] = A[v];
        for (ll u : G[v]) {
            subsum[v] += dfs(u);
        }
    }
    return subsum[v];
}

ll rdfs(ll v) {
    if (rsubsum[v] == 0) {
        rsubsum[v] = A[v];
        for (ll u : G2[v]) {
            rsubsum[v] += rdfs(u);
        }
    }
    return rsubsum[v];
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i < N; i++) {
        int v, u; cin >> v >> u;
        --v; --u;
        EL.PB({v, u});
        G[v].PB(u);
        G2[u].PB(v);
        indegree[u]++;
    }

    for (int i = 0; i < N; i++) {
        presum += A[i] * (dfs(i) - 1);
        rdfs(i);
    }
    ans = presum;

    for (ii e : EL) {
        ll additional = (rsubsum[e[1]] - rsubsum[e[0]]) * (subsum[e[0]] - subsum[e[1]]);
        ans = max(ans, presum + additional);
    }

    cout << ans << endl;

    return 0;
}
