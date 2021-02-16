// CSES Problem Set - Permutations
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

int N;

void setIO(string name = "input") {
    freopen((name + ".in").c_str(), "r", stdin);
    if (name != "input") freopen((name + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); //setIO();

    cin >> N;
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (N <= 3) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    for (int i = 2; i <= N; i += 2) {
        cout << i << " ";
    }
    for (int i = 1; i <= N; i += 2) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
