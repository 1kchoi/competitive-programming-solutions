// CSES Problem Set - Number Spiral
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

ll T, Y, X;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> T;
    while (T--) {
        cin >> Y >> X;
        ll num = max(X, Y);
        if (num % 2) {
            if (Y > X) {
                cout << (num - 1) * (num - 1) + X << endl;
            }
            else {
                cout << num * num - Y + 1 << endl;
            }
        }
        else {
            if (Y > X) {
                cout << num * num - X + 1 << endl;
            }
            else {
                cout << (num - 1) * (num - 1) + Y << endl;
            }
        }
    }

    return 0;
}
