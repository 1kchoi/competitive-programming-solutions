// Mock CCC '19 Contest 1 S4 - Pusheen Plays Neko Atsume
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

ll A, B, C, D, Q, X;
map<ll, ll> M;
set<ll> ans;

ll solve(int x) {
    if (x <= 0) {
        return 1;
    }
    if (!M.count(x)) {
        M[x] = solve((x - A * B) / A) + solve((x - C * D) / C);
    }
    ans.insert(M[x]);
    return M[x];
}

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> A >> B >> C >> D >> Q;
    /*
    for (int i = 1; i <= Q; i++) {
        cout << i << " " << solve(i) << " (" << i / A - B << " " << i / C - D << ") " << sz(ans) << endl;
    }
    */
    cout << solve((int)(1e9)) << " " << sz(ans) << endl;
    cout << solve((int)(1e9) - 19) << " " << sz(ans) << endl;

    return 0;
}
