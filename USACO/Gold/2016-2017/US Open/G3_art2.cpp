// USACO 2017 US Open Contest, Gold
// Problem 3. Modern Art 2
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

int N, A[NMAX], st[NMAX], en[NMAX], ans;
vii B;
bool started[NMAX];
stack<int> S;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> N;
    memset(st, INF, sizeof(st));
    memset(en, -INF, sizeof(en));
    for (int i = 0; i < N; i++) {
        int x; cin >> x; A[i] = x;
        st[x] = min(st[x], i);
        en[x] = i;
    }

    for (int i = 1; i <= N; i++) {
        if (st[i] <= N) {
            B.PB({st[i], i});
        }
        if (en[i] >= 0) {
            B.PB({en[i], i});
        }
    }
    B.PB({-1, 0});
    B.PB({N, 0});
    sort(all(B));

    for (ii X : B) {
        if (!started[X[1]]) {
            started[X[1]] = true;
            S.push(X[1]);
            ans = max(ans, sz(S) - 1);
        }
        else {
            while(S.top() != X[1])
        }
    }

    return 0;
}
