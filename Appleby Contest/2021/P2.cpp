// Appleby Contest '20 P2 - Playful Playdoughs
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

ll N, Q, A[NMAX];

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        ll x; cin >> x;
        A[x]++;
    }
    while (Q--) {
        ll t, x; cin >> t >> x;
        if (t == 1) {
            A[x / 2] += A[x];
            A[(x + 1) / 2] += A[x];
            A[x] = 0;
        }
        else {
            cout << A[x] << endl;
        }
    }

    return 0;
}
