// Mock CCC '18 Contest 1 S4 - A Graph Problem
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, M, K, S, T, ans;
vector<ar<ll, 3>> G[NMAX];
set<ll> temp, valid;
vi kvalues;
bool discovered[NMAX];

void dfs(ll v, ll k) {
    discovered[v] = true;
    for (ar<ll, 3> u : G[v]) {
        if (!discovered[u[0]]) {
            if (u[1] <= k && k <= u[2]) {
                dfs(u[0], k);
            }
        }
    }
}

bool check(ll k) {
    memset(discovered, 0, sizeof(discovered));
    dfs(S, k);
    return discovered[T];
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N >> M >> K >> S >> T;
    temp.insert(1); temp.insert(K);
    for (int i = 0; i < M; i++) {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        G[a].PB({b, c, d});
        if (c < K) temp.insert(c);
        if (d < K) temp.insert(d);
    }
    kvalues = vi(all(temp));

    for (int i = 0; i < sz(kvalues); i++) {
        if (check(kvalues[i])) {
            valid.insert(kvalues[i]);
            if (i && check(kvalues[i] - 1)) {
                ans += kvalues[i] - kvalues[i - 1];
            }
            else {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
