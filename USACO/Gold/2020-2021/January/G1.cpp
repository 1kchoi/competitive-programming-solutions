// USACO 2021 January Contest, Gold
// Problem 1. Uddered but not Herd
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

string S;
int N, ans = 1;
vi G[28];
bool discovered[28];

bool canFind(int v, int st, int en) {
    discovered[v] = true;
    if (v == en) {
        return true;
    }
    for (int i = 0; i < sz(G[v]); i++) {
        if (!discovered[G[v][i]]) {
            if (canFind(G[v][i], st, en)) {
                return true;
            }
        }
    }
    return false;
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> S;
    N = sz(S);
    for (int i = 0; i + 1 < N; i++) {
        int c1 = S[i] - 'a', c2 = S[i + 1] - 'a';
        memset(discovered, 0, sizeof(discovered));
        if (!canFind(c2, c2, c1)) {
            G[c1].PB(c2);
        }
        else {
            ans++;
            cout << i << "!" << endl;
        }
    }

    cout << ans << endl;

    return 0;
}
