// CSES Problem Set - Two Knights
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

ll N, given[5] = {0, 0, 6, 28, 96};

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N;
    for (int i = 1; i <= N; i++) {
        if (i <= 4) {
            cout << given[i] << endl;
            continue;
        }
        ll ans = 0;

        ans += i * i - 3;
        ans += 2 * (i * i - 4);
        ans += (i - 3) * (i * i - 5);
        ans += (i - 4) * (i * i - 7);
        ans *= 4;

        ans += (i - 4) * (i - 4) * (i * i - 9);

        ans /= 2;
        cout << ans << endl;
    }
    return 0;
}
