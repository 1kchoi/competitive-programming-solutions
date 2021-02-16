// CSES Problem Set - Apple Division
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
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

ll N, total, A[22], ans = LLONG_MAX;
set<ll> S;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N;
    S.insert(0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        total += A[i];
    }
    for (int i = 0; i < N; i++) {
        vi newdp;
        for (set<ll>::iterator it = S.begin(); it != S.end(); it++) {
            ll cand = (*it) + A[i];
            if (cand > total / 2) continue;
            newdp.PB(cand);
        }
        for (ll x : newdp) {
            S.insert(x);
        }
    }
    for (set<ll>::iterator it = S.begin(); it != S.end(); it++) {
        ans = min(ans, total - 2 * (*it));
    }
    cout << ans << endl;

    return 0;
}
