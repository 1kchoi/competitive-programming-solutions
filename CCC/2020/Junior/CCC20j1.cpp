// CCC '20 J1 - Dog Treats
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

int a, b, c;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);


    cin >> a >> b >> c;
    if (a + 2 * b + 3 * c >= 10) {
        cout << "happy" << endl;
    }
    else {
        cout << "sad" << endl;
    }

    return 0;
}
