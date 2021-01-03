// CCC '20 J2 - Epidemiology
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

int A, B, C, ans;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> A >> B >> C;
    int X = ans = B;
    for (int i = 0; i < (int)(1e7+5); i++) {
        X *= C;
        ans += X;
        cout << ans << endl;
        if (ans > A) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    return 0;
}
