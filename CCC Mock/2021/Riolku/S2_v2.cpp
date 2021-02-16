// Riolku's Mock CCC S2 - Keen Keener Sequence
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ar array
#define PB push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define NMAX (int)(1.5e3+5)
#define INF 0x3f
#define MOD (int)(1e9+7)
typedef ar<ll, 2> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, A[NMAX], ans, taken[NMAX];
map<ll, vii> M;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ans += sz(M[A[i] * A[j]]);
            M[A[i] * A[j]].PB({i, j});
        }
    }
    for (map<ll, vii>::iterator it = M.begin(); it != M.end(); it++) {
        vii B = it->second;
        memset(taken, 0, sizeof(taken));
        for (ii e : B) {
            ans -= taken[e[0]];
            ans -= taken[e[1]];
            taken[e[0]]++;
            taken[e[1]]++;
        }
    }
    cout << ans * 8 << endl;

    return 0;
}
