// CCC '19 J1 - Winning Score
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

int A, B;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); setIO();

    int X;
    cin >> X; A += X * 3;
    cin >> X; A += X * 2;
    cin >> X; A += X * 1;
    cin >> X; B += X * 3;
    cin >> X; B += X * 2;
    cin >> X; B += X * 1;

    if (A > B) {
        cout << "A" << endl;
    }
    else if (B > A) {
        cout << "B" << endl;
    }
    else {
        cout << "T" << endl;
    }

    return 0;
}
