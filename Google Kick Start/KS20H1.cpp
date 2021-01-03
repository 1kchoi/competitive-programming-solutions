// Google Kick Start 2020 Round H Question 1 - Retype
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

ll T, N, K, S;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N >> K >> S;
        cout << "Case #" << tc << ": ";
        cout << min(N + 2 * (K - S), N + K);
        cout << endl;
    }

    return 0;
}
