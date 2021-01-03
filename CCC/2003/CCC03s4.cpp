// CCC '03 S4 - Substrings
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
#define MOD (int)(1e9+97)
typedef ar<int, 2> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

int T, N;
string S;
set<ll> H;
const ll P = 1e5+69;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    cin >> T;
    while (T--) {
        H.clear();
        cin >> S;
        N = sz(S);
        for (int start = 0; start < N; start++) {
            ll X = 0;
            for (int j = 0; start + j < N; j++) {
                X *= P; X %= MOD;
                X += S[start + j]; X %= MOD;
                H.insert(X);
            }
        }
        cout << sz(H) + 1 << endl;
    }

    return 0;
}
